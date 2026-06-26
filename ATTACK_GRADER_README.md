# Attack Grader — Setup & Run Guide

Grades every submission under 5 conditions (clean + 4 attacks) across 4 HuggingFace models and saves all results to a single CSV file.

---

## Before You Start

Make sure your folder looks like this:

```
PS_Data-master/
├── grade_attacks.py
├── src/
│   ├── __init__.py
│   └── attacks/
│       ├── __init__.py
│       ├── base.py
│       ├── persona_role_play.py
│       ├── textual_injection.py
│       ├── control_flow_interleaving.py
│       └── identifier_shadowing.py
├── configs/
│   └── models.yaml
├── data/
│   └── final_dataset/
│       ├── Python/
│       ├── Java/
│       ├── C++/
│       ├── JavaScript/
│       └── problem_statements/
└── .env                ← you create this, never push to GitHub
```

---

## Step 1 — Install Dependencies

```bash
pip install huggingface-hub python-dotenv pyyaml tqdm
```

---

## Step 2 — Create `.env` File

Create a file called `.env` in the root folder (same place as `grade_attacks.py`):

```
HF_TOKEN=hf_your_token_here
```

Get your token from huggingface.co → Settings → Access Tokens. Make sure you have access to all 4 models:
- `meta-llama/Llama-3.1-8B-Instruct`
- `Qwen/Qwen3-8B`
- `google/gemma-4-E4B-it`
- `deepseek-ai/DeepSeek-R1-Distill-Qwen-7B`

> ⚠️ Never push `.env` to GitHub. Make sure it is in `.gitignore`.

---

## Step 3 — Dry Run First

```bash
python grade_attacks.py --dry-run --max 3
```

You should see all 4 models and all 5 conditions running on 3 submissions with no errors. If you see `[skip] Language folder not found` — your `final_dataset` is not inside the `data/` subfolder.

---

## Step 4 — Test With Real API Calls

```bash
python grade_attacks.py --max 2
```

Open `results/raw_scores.csv` and check that scores look reasonable.

---

## Step 5 — Full Run

```bash
python grade_attacks.py
```

Takes 2-4 hours depending on API speed. If it crashes at any point just rerun the same command — it automatically skips already completed rows and picks up where it left off.

---

## Output

Single file: `results/raw_scores.csv`

~12,820 rows total (641 submissions × 4 models × 5 conditions).

Each row contains:

```
submission_id, language, tier, error_type, problem_id,
model, condition, total_score,
format, time_complexity, space_complexity,
general_correctness, edge_case_correctness,
parse_failed
```

The `condition` column tells you whether the row is `clean` or which attack was applied (`persona_role_play`, `textual_injection`, `control_flow_interleaving`, `identifier_shadowing`).

---

## Useful Options

```bash
# One language only
python grade_attacks.py --language Python

# Limit submissions (for testing)
python grade_attacks.py --max 10

# Skip a specific model
python grade_attacks.py --skip-models Qwen/Qwen3-8B

# Skip specific attacks
python grade_attacks.py --skip-attacks control_flow_interleaving identifier_shadowing
```

---

## Common Errors

| Error | Fix |
|---|---|
| `ModuleNotFoundError` | Run `pip install huggingface-hub python-dotenv pyyaml tqdm` |
| `HF_TOKEN not set` | Create `.env` file with `HF_TOKEN=hf_...` |
| `Language folder not found` | Move `final_dataset` inside a `data/` subfolder |
| `FileNotFoundError: configs/models.yaml` | Make sure `configs/` folder is in the project root |
| `No module named 'src.attacks'` | Run the script from the project root folder, not from inside `src/` |
| `Model is currently loading` | Script retries automatically, just wait |
