import os
import json
import time
import anthropic

RAW_DIR   = r"path/to/codenet_raw"  # change this to wherever they clone the repo
DRY_RUN   = True   # set to False when ready
MAX_CALLS = 10     # bump to 2000 for full run

LANG_EXT = {
    'Python':     '.py',
    'C++':        '.cpp',
    'Java':       '.java',
    'JavaScript': '.js'
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

client = anthropic.Anthropic()

total_calls         = 0

for lang in os.listdir(RAW_DIR):
    lang_dir = os.path.join(RAW_DIR, lang)
    if not os.path.isdir(lang_dir):
        continue

    ext = LANG_EXT.get(lang)
    if not ext:
        continue

    for tier in os.listdir(lang_dir):
        tier_dir = os.path.join(lang_dir, tier)
        if not os.path.isdir(tier_dir):
            continue

        for problem_id in os.listdir(tier_dir):
            problem_dir = os.path.join(tier_dir, problem_id)
            if not os.path.isdir(problem_dir):
                continue

            # read problem statement
            ps_path = os.path.join(problem_dir, 'problem_statement.txt')
            if not os.path.exists(ps_path):
                continue
            with open(ps_path, 'r', encoding='utf-8', errors='replace') as f:
                problem_statement = f.read().strip()

            # read reference accepted solution — skip problem entirely if missing
            ref_path = os.path.join(problem_dir, f'reference_accepted{ext}')
            if not os.path.exists(ref_path):
                print(f"  Skipping {lang}/{tier}/{problem_id} — no reference solution")
                continue
            with open(ref_path, 'r', encoding='utf-8', errors='replace') as f:
                reference = f.read().strip()

            # load existing classifications if any (resume on crash)
            out_path = os.path.join(problem_dir, 'classifications.json')
            if os.path.exists(out_path):
                with open(out_path, 'r') as f:
                    classifications = json.load(f)
            else:
                classifications = {}

            # classify each submission
            for fname in os.listdir(problem_dir):
                if not fname.endswith(ext):
                    continue
                if fname == f'reference_accepted{ext}':
                    continue  # skip the reference file
                if total_calls >= MAX_CALLS:
                    break

                sid = fname.replace(ext, '')

                # skip if already classified
                if sid in classifications:
                    continue

                with open(os.path.join(problem_dir, fname), 'r', encoding='utf-8', errors='replace') as f:
                    code = f.read().strip()

                prompt = PROMPT_TEMPLATE.format(
                    problem_statement=problem_statement,
                    language=lang,
                    reference=reference,
                    code=code
                )

                if DRY_RUN:
                    print(f"[DRY RUN] Would classify: {lang}/{tier}/{problem_id}/{fname}")
                    print(f"  Prompt length: {len(prompt)} chars")
                    print(f"  First 200 chars:\n  {prompt[:200]}\n")
                    classifications[sid] = 'DRY_RUN'
                else:
                    try:
                        response = client.messages.create(
                            model="claude-haiku-4-5-20251001",
                            max_tokens=10,
                            messages=[{"role": "user", "content": prompt}]
                        )
                        result = response.content[0].text.strip().lower()

                        # validate response
                        if result not in ('off_by_one', 'logic_error', 'partial_solution'):
                            result = 'logic_error'  # fallback

                        classifications[sid] = result
                        print(f"  {lang}/{tier}/{problem_id}/{fname} → {result}")

                        time.sleep(0.1)  # avoid rate limits

                    except Exception as e:    
                        print(f"  Error on {fname}: {e}")
                        continue

                total_calls += 1

                # save after every submission
                with open(out_path, 'w') as f:
                    json.dump(classifications, f, indent=2)

            if total_calls >= MAX_CALLS:
                break
        if total_calls >= MAX_CALLS:
            break
    if total_calls >= MAX_CALLS:
        break

print(f"\nDone!")
print(f"Total calls made: {total_calls}")
