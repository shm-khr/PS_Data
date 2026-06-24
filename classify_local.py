import os
os.environ["HF_HOME"] = "/localstorage/home/dhruvkumar/f20240533_ps/hf_cache"

import json
import time
import torch
from dotenv import load_dotenv
from transformers import (
    AutoTokenizer,
    AutoModelForCausalLM,
    BitsAndBytesConfig,
)

# ── Load token from .env file ────────────────────────────────────────────────
load_dotenv()
HF_TOKEN = os.environ.get("HF_TOKEN")
if not HF_TOKEN:
    raise EnvironmentError("HF_TOKEN not found. Make sure .env file has: HF_TOKEN=hf_...")

# ── HuggingFace cache: point to YOUR folder, not Dhruv sir's home ───────────
os.environ["HF_HOME"] = "/localstorage/home/dhruvkumar/f20240533_ps/hf_cache"

# ── Paths & run config ───────────────────────────────────────────────────────
RAW_DIR   = "/localstorage/home/dhruvkumar/f20240533_ps/PS_Data/codenet_raw_topup"
DRY_RUN   = False    # ← keep True for first test, change to False for real run
MAX_CALLS = 2000

MODEL_NAME = "meta-llama/Llama-3.1-8B-Instruct"

# ── Language extensions ──────────────────────────────────────────────────────
LANG_EXT = {
    'Python':     '.py',
    'C++':        '.cpp',
    'Java':       '.java',
    'JavaScript': '.js'
}

TIER_MAP = {
    'easy':   'tier1',
    'medium': 'tier2',
    'hard':   'tier3',
}

PROMPT_TEMPLATE = """You are a programming expert. Given a problem statement, a correct reference solution, and an incorrect student submission, classify the type of error into exactly one of these three categories:

1. off_by_one - The logic is almost correct but has a boundary/index/range error (e.g. < instead of <=, starting index wrong, loop runs one too many or too few times). This includes Time Limit Exceeded caused by a minor boundary mistake.
2. logic_error - The overall approach or algorithm is fundamentally wrong or misunderstands the problem.
3. partial_solution - The solution is incomplete, missing major cases, or only solves part of the problem.

Problem Statement:
{problem_statement}

Correct Reference Solution ({language}):
{reference}

Incorrect Student Submission ({language}):
{code}

Reply with exactly one of: off_by_one, logic_error, partial_solution
No explanation, no punctuation, just the category name."""

# ── Load model ONCE at startup (do NOT move this inside the loop) ────────────
def load_model():
    print(f"[Model] Loading {MODEL_NAME} with 4-bit quantization...")
    print(f"[Model] First run will download weights (~5GB). This takes 2-3 minutes.")

    bnb_config = BitsAndBytesConfig(
        load_in_4bit=True,
        bnb_4bit_compute_dtype=torch.float16,
        bnb_4bit_use_double_quant=True,
        bnb_4bit_quant_type="nf4",
    )

    tokenizer = AutoTokenizer.from_pretrained(
        MODEL_NAME,
        token=HF_TOKEN,
    )
    tokenizer.pad_token = tokenizer.eos_token

    model = AutoModelForCausalLM.from_pretrained(
        MODEL_NAME,
        quantization_config=bnb_config,
        device_map="auto",
        token=HF_TOKEN,
    )
    model.eval()

    allocated = torch.cuda.memory_allocated() / 1e9
    print(f"[Model] Ready. GPU VRAM used: {allocated:.1f} GB\n")

    return tokenizer, model


# ── Single classification call ────────────────────────────────────────────────
def classify(tokenizer, model, prompt: str) -> str:
    """Run local inference and return one of the three category strings."""

    messages = [{"role": "user", "content": prompt}]
    formatted = tokenizer.apply_chat_template(
        messages,
        tokenize=False,
        add_generation_prompt=True,
    )

    inputs = tokenizer(
        formatted,
        return_tensors="pt",
        truncation=True,
        max_length=3072,
    ).to("cuda")

    with torch.no_grad():
        output = model.generate(
            **inputs,
            max_new_tokens=10,
            do_sample=False,
            pad_token_id=tokenizer.eos_token_id,
        )

    new_tokens = output[0][inputs["input_ids"].shape[1]:]
    result = tokenizer.decode(new_tokens, skip_special_tokens=True).strip().lower()

    if result not in ("off_by_one", "logic_error", "partial_solution"):
        print(f"    [warn] Unexpected response: {result!r} — defaulting to logic_error")
        result = "logic_error"

    return result


# ── Main ──────────────────────────────────────────────────────────────────────
def main():
    print(f"=== Classification Script (LOCAL GPU) ===")
    print(f"  Model    : {MODEL_NAME}")
    print(f"  Dataset  : {RAW_DIR}")
    print(f"  Dry run  : {DRY_RUN}")
    print(f"  Max calls: {MAX_CALLS}")
    print(f"  CUDA     : {torch.cuda.is_available()}")
    if torch.cuda.is_available():
        print(f"  GPU      : {torch.cuda.get_device_name(0)}\n")

    if not os.path.exists(RAW_DIR):
        print(f"ERROR: Dataset folder not found: {RAW_DIR}")
        print("Check the RAW_DIR path at the top of this script.")
        return

    tokenizer, model = None, None
    if not DRY_RUN:
        tokenizer, model = load_model()

    total_calls = 0
    start_time  = time.time()

    for lang in os.listdir(RAW_DIR):
        lang_dir = os.path.join(RAW_DIR, lang)
        if not os.path.isdir(lang_dir):
            continue

        ext = LANG_EXT.get(lang)
        if not ext:
            print(f"  [skip] Unknown language folder: {lang}")
            continue

        for tier_name in os.listdir(lang_dir):
            tier_dir = os.path.join(lang_dir, tier_name)
            if not os.path.isdir(tier_dir):
                continue

            for problem_id in os.listdir(tier_dir):
                problem_dir = os.path.join(tier_dir, problem_id)
                if not os.path.isdir(problem_dir):
                    continue

                ps_path = os.path.join(problem_dir, "problem_statement.txt")
                if not os.path.exists(ps_path):
                    print(f"  [skip] No problem_statement.txt in {problem_dir}")
                    continue
                with open(ps_path, "r", encoding="utf-8", errors="replace") as f:
                    problem_statement = f.read().strip()

                ref_path = os.path.join(problem_dir, f"reference_accepted{ext}")
                if os.path.exists(ref_path):
                    with open(ref_path, "r", encoding="utf-8", errors="replace") as f:
                        reference = f.read().strip()
                else:
                    reference = "No reference solution available."

                out_path = os.path.join(problem_dir, "classifications.json")
                if os.path.exists(out_path):
                    with open(out_path, "r") as f:
                        classifications = json.load(f)
                else:
                    classifications = {}

                for fname in sorted(os.listdir(problem_dir)):
                    if not fname.endswith(ext):
                        continue
                    if fname == f"reference_accepted{ext}":
                        continue
                    if total_calls >= MAX_CALLS:
                        break

                    sid = fname.replace(ext, "")

                    if sid in classifications and classifications[sid] != "DRY_RUN":
                        print(f"  [skip] {lang}/{tier_name}/{problem_id}/{fname}")
                        continue

                    with open(os.path.join(problem_dir, fname), "r", encoding="utf-8", errors="replace") as f:
                        code = f.read().strip()

                    prompt = PROMPT_TEMPLATE.format(
                        problem_statement=problem_statement,
                        language=lang,
                        reference=reference,
                        code=code,
                    )

                    if DRY_RUN:
                        print(f"  [DRY RUN] {lang}/{tier_name}/{problem_id}/{fname}")
                        print(f"    Prompt length : {len(prompt)} chars")
                        print(f"    First 200 chars:\n    {prompt[:200]}\n")
                        classifications[sid] = "DRY_RUN"
                    else:
                        try:
                            elapsed = (time.time() - start_time) / 60
                            print(
                                f"  [{total_calls+1}/{MAX_CALLS} | {elapsed:.1f}m] "
                                f"Classifying {lang}/{tier_name}/{problem_id}/{fname}...",
                                end=" ", flush=True
                            )
                            result = classify(tokenizer, model, prompt)
                            classifications[sid] = result
                            print(f"→ {result}")

                        except Exception as e:
                            print(f"\n  [error] {fname}: {e}")
                            continue

                    total_calls += 1

                    with open(out_path, "w") as f:
                        json.dump(classifications, f, indent=2)

                if total_calls >= MAX_CALLS:
                    break
            if total_calls >= MAX_CALLS:
                break
        if total_calls >= MAX_CALLS:
            break

    elapsed_total = (time.time() - start_time) / 60
    print(f"\n=== Done in {elapsed_total:.1f} minutes ===")
    print(f"Total calls made: {total_calls}")
    if DRY_RUN:
        print("\nThis was a DRY RUN — no model calls were made.")
        print("To run for real: set DRY_RUN = False at the top of this file.")


if __name__ == "__main__":
    main()

