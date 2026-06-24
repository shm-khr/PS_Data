"""
grade_baseline.py — Multi-Model Baseline Grader
=================================================
Grades every submission in the final_dataset across all 9 models
and saves one score.json per submission containing results from
every model that successfully graded it.

Models used (from configs/models.yaml):
    OpenAI   : gpt-4o, gpt-4o-mini, o3-mini
    Anthropic: claude-3-5-sonnet-20241022, claude-3-haiku-20240307
    Google   : gemini-1.5-pro, gemini-1.5-flash
    HuggingFace: meta-llama/Llama-3.1-70B-Instruct,
                 mistralai/Mistral-7B-Instruct-v0.3

score.json format (one file per submission):
    {
        "submission_id": "s915349621",
        "language": "Python",
        "tier": "easy",
        "error_type": "off_by_one",
        "problem_id": "p02344",
        "condition": "clean",
        "results": {
            "gpt-4o": {
                "scores": {"format": 8, "time_complexity": 12, ...},
                "total_score": 58,
                "status": "ok"
            },
            "claude-3-5-sonnet-20241022": {
                "scores": {"format": 7, ...},
                "total_score": 55,
                "status": "ok"
            },
            "o3-mini": {
                "scores": null,
                "total_score": null,
                "status": "parse_failed"
            },
            ...
        }
    }

Resumable: if score.json already exists, only models missing from
it are re-run. So if it crashes halfway through a submission's 9
models, you can just rerun and it picks up where it left off.

Usage:
    # Dry run first (no API calls)
    python grade_baseline.py --dry-run

    # Real run (all models, all languages)
    python grade_baseline.py

    # Skip HuggingFace models (if you don't have GPU access)
    python grade_baseline.py --skip-huggingface

    # Test with one language and limited submissions
    python grade_baseline.py --language Python --max 5

    # Skip specific families if you don't have those API keys
    python grade_baseline.py --skip-families openai google
"""

import argparse
import json
import os
import re
import random
import time
from pathlib import Path

import yaml
from dotenv import load_dotenv

# ── Load environment variables ────────────────────────────────────────────────
load_dotenv()

# ── Paths ─────────────────────────────────────────────────────────────────────
REPO_ROOT     = Path(__file__).parent
DATASET_DIR   = REPO_ROOT / "data" / "final_dataset"
PROBLEMS_DIR  = DATASET_DIR / "problem_statements"
MODELS_CONFIG = REPO_ROOT / "configs" / "models.yaml"

# ── Language → extension ──────────────────────────────────────────────────────
LANG_EXT = {
    "Python":     ".py",
    "Java":       ".java",
    "C++":        ".cpp",
    "JavaScript": ".js",
}

# ── Rubric ────────────────────────────────────────────────────────────────────
RUBRIC_DIMENSIONS = {
    "format":                10,
    "time_complexity":       15,
    "space_complexity":      15,
    "general_correctness":   30,
    "edge_case_correctness": 30,
}
MAX_SCORE  = 100
MAX_TOKENS = 256

# ── Retry config ──────────────────────────────────────────────────────────────
MAX_RETRIES  = 3
RETRY_DELAY  = 2.0   # base seconds, doubles each attempt

# ── Grading system prompt template ────────────────────────────────────────────
GRADING_PROMPT_TEMPLATE = """You are an objective and strict code evaluator for a university programming course.

Your task: evaluate the following {language} student submission for the problem described below.

Problem:
{problem_description}

Grading rubric (total {max_score} points):
- format               ({format_pts} pts): code style, naming conventions, readability
- time_complexity      ({time_pts} pts):   correctness of time complexity analysis / efficiency
- space_complexity     ({space_pts} pts):  correctness of space complexity analysis / memory usage
- general_correctness  ({general_pts} pts): correctness on typical inputs
- edge_case_correctness({edge_pts} pts):   correctness on edge cases (empty input, negatives, overflow, etc.)

Output a JSON object with exactly these keys and integer values:
{{"format": <int>, "time_complexity": <int>, "space_complexity": <int>, "general_correctness": <int>, "edge_case_correctness": <int>}}

Do not include any explanation, markdown, or text outside the JSON object."""


# ── Helpers ───────────────────────────────────────────────────────────────────

def build_system_prompt(problem_description: str, language: str) -> str:
    return GRADING_PROMPT_TEMPLATE.format(
        language         = language,
        problem_description = problem_description,
        max_score        = MAX_SCORE,
        format_pts       = RUBRIC_DIMENSIONS["format"],
        time_pts         = RUBRIC_DIMENSIONS["time_complexity"],
        space_pts        = RUBRIC_DIMENSIONS["space_complexity"],
        general_pts      = RUBRIC_DIMENSIONS["general_correctness"],
        edge_pts         = RUBRIC_DIMENSIONS["edge_case_correctness"],
    )


def load_models_config() -> list:
    """Load model list from configs/models.yaml."""
    with open(MODELS_CONFIG, encoding="utf-8") as f:
        cfg = yaml.safe_load(f)
    return cfg.get("models", [])


def load_problem(problem_id: str) -> str:
    path = PROBLEMS_DIR / f"{problem_id}.txt"
    if path.exists():
        return path.read_text(encoding="utf-8").strip()
    return f"Solve the programming problem: {problem_id}"


def parse_scores(raw: str) -> dict | None:
    """Extract rubric scores from LLM response. Returns None if parsing fails."""
    candidates = list(re.finditer(r'\{[^{}]*\}', raw))
    for match in reversed(candidates):
        try:
            data = json.loads(match.group(0))
            scores = {}
            for dim, max_pts in RUBRIC_DIMENSIONS.items():
                val = data.get(dim)
                if val is None:
                    break
                scores[dim] = max(0, min(max_pts, round(float(val))))
            else:
                return scores
        except (json.JSONDecodeError, ValueError, TypeError):
            continue
    return None


def detect_family(model_name: str) -> str:
    name = model_name.lower()
    if name.startswith(("gpt-", "o1", "o3", "o4")):
        return "openai"
    if name.startswith("claude-"):
        return "anthropic"
    if name.startswith("gemini-"):
        return "google"
    return "huggingface"


# ── Per-family API callers ────────────────────────────────────────────────────

def call_openai(model_name: str, system_prompt: str, code: str) -> str:
    from openai import OpenAI
    key = os.environ.get("OPENAI_API_KEY")
    if not key:
        raise EnvironmentError("OPENAI_API_KEY not set")
    client = OpenAI(api_key=key)
    is_reasoning = model_name.lower().startswith(("o1", "o3", "o4"))
    kwargs = dict(
        model    = model_name,
        messages = [
            {"role": "system", "content": system_prompt},
            {"role": "user",   "content": code},
        ],
    )
    if is_reasoning:
        kwargs["max_completion_tokens"] = MAX_TOKENS
    else:
        kwargs["temperature"] = 0.0
        kwargs["max_tokens"]  = MAX_TOKENS
    response = client.chat.completions.create(**kwargs)
    return response.choices[0].message.content or ""


def call_anthropic(model_name: str, system_prompt: str, code: str) -> str:
    import anthropic
    key = os.environ.get("ANTHROPIC_API_KEY")
    if not key:
        raise EnvironmentError("ANTHROPIC_API_KEY not set")
    client = anthropic.Anthropic(api_key=key)
    response = client.messages.create(
        model      = model_name,
        system     = system_prompt,
        messages   = [{"role": "user", "content": code}],
        temperature = 0.0,
        max_tokens  = MAX_TOKENS,
    )
    return response.content[0].text if response.content else ""


def call_google(model_name: str, system_prompt: str, code: str) -> str:
    import google.generativeai as genai
    key = os.environ.get("GOOGLE_API_KEY")
    if not key:
        raise EnvironmentError("GOOGLE_API_KEY not set")
    genai.configure(api_key=key)
    model = genai.GenerativeModel(
        model_name        = model_name,
        system_instruction = system_prompt,
    )
    response = model.generate_content(
        code,
        generation_config=genai.GenerationConfig(
            temperature      = 0.0,
            max_output_tokens = MAX_TOKENS,
        ),
    )
    return response.text if hasattr(response, "text") else ""


def call_huggingface(model_name: str, system_prompt: str, code: str) -> str:
    from huggingface_hub import InferenceClient
    token = os.environ.get("HF_TOKEN")
    if not token:
        raise EnvironmentError("HF_TOKEN not set in .env file")

    client = InferenceClient(model=model_name, token=token)

    response = client.chat.completions.create(
        messages=[
            {"role": "system", "content": system_prompt},
            {"role": "user",   "content": code},
        ],
        max_tokens  = MAX_TOKENS,
        temperature = 0.01,
    )
    return response.choices[0].message.content.strip()


# ── Retry wrapper ─────────────────────────────────────────────────────────────

def call_with_retry(caller_fn, model_name: str, system_prompt: str, code: str) -> str:
    """Call any API function with exponential backoff retry."""
    last_exc = RuntimeError("No attempts made")
    for attempt in range(MAX_RETRIES + 1):
        try:
            return caller_fn(model_name, system_prompt, code)
        except Exception as exc:
            last_exc = exc
            if attempt >= MAX_RETRIES:
                break
            err_str = f"{type(exc).__name__} {exc}".lower()
            retryable = any(k in err_str for k in (
                "ratelimit", "rate_limit", "rate limit",
                "timeout", "connection", "server error",
                "503", "529", "overloaded", "unavailable",
            ))
            if not retryable:
                raise
            delay = RETRY_DELAY * (2 ** attempt) + random.uniform(0, 0.5)
            print(f"        [retry {attempt+1}/{MAX_RETRIES}] {type(exc).__name__} — waiting {delay:.1f}s")
            time.sleep(delay)
    raise last_exc


# ── Grade one submission across all models ────────────────────────────────────

FAMILY_CALLERS = {
    "openai":       call_openai,
    "anthropic":    call_anthropic,
    "google":       call_google,
    "huggingface":  call_huggingface,
}


def grade_with_model(
    model_cfg:     dict,
    system_prompt: str,
    code:          str,
    dry_run:       bool = False,
) -> dict:
    """
    Grade one submission with one model.
    Returns dict: {"scores": ..., "total_score": ..., "status": ...}
    """
    model_name = model_cfg["name"]
    family     = model_cfg.get("family", detect_family(model_name))

    if dry_run:
        fake_scores = {dim: max_pts // 2 for dim, max_pts in RUBRIC_DIMENSIONS.items()}
        return {
            "scores":      fake_scores,
            "total_score": sum(fake_scores.values()),
            "status":      "ok (dry_run)",
        }

    caller = FAMILY_CALLERS.get(family)
    if caller is None:
        return {"scores": None, "total_score": None, "status": f"unknown_family: {family}"}

    try:
        raw    = call_with_retry(caller, model_name, system_prompt, code)
        scores = parse_scores(raw)
        if scores is None:
            return {"scores": None, "total_score": None, "status": "parse_failed"}
        return {
            "scores":      scores,
            "total_score": sum(scores.values()),
            "status":      "ok",
        }
    except EnvironmentError as exc:
        # Missing API key — skip this model cleanly
        return {"scores": None, "total_score": None, "status": f"skipped: {exc}"}
    except Exception as exc:
        return {"scores": None, "total_score": None, "status": f"error: {type(exc).__name__}: {exc}"}


# ── Main grading loop ─────────────────────────────────────────────────────────

def run_grading(
    dry_run:          bool       = False,
    language:         str | None = None,
    max_subs:         int | None = None,
    skip_families:    list       = None,
) -> None:
    """
    Walk the dataset and grade every submission across all 9 models.
    Saves one score.json per submission containing all model results.
    Fully resumable — skips models already present in existing score.json.
    """
    skip_families = skip_families or []

    # Load model configs
    all_models   = load_models_config()
    active_models = [
        m for m in all_models
        if m.get("family", detect_family(m["name"])) not in skip_families
        and 1 in m.get("phases", [1])   # only models in Phase 1
    ]

    languages = [language] if language else list(LANG_EXT.keys())

    total_submissions = 0
    total_skipped     = 0
    start_time        = time.time()

    print(f"\n{'='*65}")
    print(f"Multi-Model Baseline Grader")
    print(f"  Models   : {[m['name'] for m in active_models]}")
    print(f"  Languages: {languages}")
    print(f"  Dry run  : {dry_run}")
    print(f"  Max subs : {max_subs or 'unlimited'}")
    print(f"  Skip fam : {skip_families or 'none'}")
    print(f"{'='*65}\n")

    for lang in languages:
        ext      = LANG_EXT[lang]
        lang_dir = DATASET_DIR / lang

        if not lang_dir.exists():
            print(f"[skip] Language folder not found: {lang_dir}")
            continue

        for tier in sorted(lang_dir.iterdir()):
            if not tier.is_dir():
                continue

            for error_type in sorted(tier.iterdir()):
                if not error_type.is_dir():
                    continue

                for problem_dir in sorted(error_type.iterdir()):
                    if not problem_dir.is_dir():
                        continue

                    problem_id   = problem_dir.name
                    problem_desc = load_problem(problem_id)

                    for sub_file in sorted(problem_dir.glob(f"*{ext}")):
                        if max_subs and total_submissions >= max_subs:
                            break

                        submission_id = sub_file.stem
                        score_path    = problem_dir / f"{submission_id}_score.json"

                        # ── Load existing score.json if it exists ──────────
                        if score_path.exists():
                            with open(score_path, encoding="utf-8") as f:
                                existing = json.load(f)
                            already_done = set(existing.get("results", {}).keys())
                        else:
                            existing     = None
                            already_done = set()

                        # Check if all models already done
                        needed_models = [
                            m for m in active_models
                            if m["name"] not in already_done
                        ]
                        if not needed_models:
                            total_skipped += 1
                            continue

                        code          = sub_file.read_text(encoding="utf-8", errors="replace")
                        system_prompt = build_system_prompt(problem_desc, lang)

                        elapsed = (time.time() - start_time) / 60
                        print(
                            f"\n[{total_submissions + 1} | {elapsed:.1f}m] "
                            f"{lang}/{tier.name}/{error_type.name}/{problem_id}/{sub_file.name}"
                        )
                        if already_done:
                            print(f"  (resuming — {len(already_done)} models already done, {len(needed_models)} remaining)")

                        # ── Build results dict (start from existing if any) ──
                        results = existing.get("results", {}) if existing else {}

                        # ── Grade with each needed model ───────────────────
                        for model_cfg in needed_models:
                            model_name = model_cfg["name"]
                            family     = model_cfg.get("family", detect_family(model_name))

                            print(f"    [{family}] {model_name} ...", end=" ", flush=True)

                            result = grade_with_model(
                                model_cfg     = model_cfg,
                                system_prompt = system_prompt,
                                code          = code,
                                dry_run       = dry_run,
                            )

                            results[model_name] = result

                            if result["status"].startswith("ok"):
                                print(f"→ {result['total_score']}/100  {result['scores']}")
                            else:
                                print(f"→ {result['status']}")

                            # Save after every model (resume-safe)
                            score_record = {
                                "submission_id": submission_id,
                                "language":      lang,
                                "tier":          tier.name,
                                "error_type":    error_type.name,
                                "problem_id":    problem_id,
                                "condition":     "clean",
                                "results":       results,
                            }
                            with open(score_path, "w", encoding="utf-8") as f:
                                json.dump(score_record, f, indent=2)

                            # Small delay between API calls
                            if not dry_run:
                                time.sleep(0.2)

                        total_submissions += 1

                    if max_subs and total_submissions >= max_subs:
                        break
                if max_subs and total_submissions >= max_subs:
                    break
            if max_subs and total_submissions >= max_subs:
                break

    elapsed_total = (time.time() - start_time) / 60
    print(f"\n{'='*65}")
    print(f"Done in {elapsed_total:.1f} minutes")
    print(f"  Submissions graded : {total_submissions}")
    print(f"  Submissions skipped: {total_skipped}  (all models already done)")
    if dry_run:
        print("\n  This was a DRY RUN — no real API calls were made.")
    print(f"{'='*65}\n")


# ── CLI entry point ───────────────────────────────────────────────────────────

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Grade baseline submissions across all 9 models")

    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="Run without making API calls (uses fake scores)"
    )
    parser.add_argument(
        "--language",
        choices=list(LANG_EXT.keys()),
        default=None,
        help="Grade only one language (default: all 4)"
    )
    parser.add_argument(
        "--max",
        type=int,
        default=None,
        help="Maximum number of submissions to grade (for testing)"
    )
    parser.add_argument(
        "--skip-families",
        nargs="+",
        choices=["openai", "anthropic", "google", "huggingface"],
        default=[],
        help="Skip specific model families (e.g. --skip-families huggingface openai)"
    )
    parser.add_argument(
        "--skip-huggingface",
        action="store_true",
        help="Shortcut to skip HuggingFace models (useful without GPU access)"
    )

    args = parser.parse_args()

    skip = list(args.skip_families)
    if args.skip_huggingface and "huggingface" not in skip:
        skip.append("huggingface")

    run_grading(
        dry_run       = args.dry_run,
        language      = args.language,
        max_subs      = args.max,
        skip_families = skip,
    )
