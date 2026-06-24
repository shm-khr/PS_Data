# Baseline Grader — Setup & Usage Guide

This script grades every submission in the `final_dataset` across all 9 models and saves one `score.json` file per submission containing results from every model.

---

## Models Used

| Family | Models |
|---|---|
| OpenAI | gpt-4o, gpt-4o-mini, o3-mini |
| Anthropic | claude-3-5-sonnet-20241022, claude-3-haiku-20240307 |
| Google | gemini-1.5-pro, gemini-1.5-flash |
| HuggingFace | meta-llama/Llama-3.1-70B-Instruct, mistralai/Mistral-7B-Instruct-v0.3 |

---

## Output Format

For each submission file (e.g. `s915349621.py`), the script creates a `s915349621_score.json` in the same folder:

```json
{
  "submission_id": "s915349621",
  "language": "Python",
  "tier": "easy",
  "error_type": "off_by_one",
  "problem_id": "p02344",
  "condition": "clean",
  "results": {
    "gpt-4o": {
      "scores": {
        "format": 8,
        "time_complexity": 12,
        "space_complexity": 12,
        "general_correctness": 20,
        "edge_case_correctness": 18
      },
      "total_score": 70,
      "status": "ok"
    },
    "claude-3-5-sonnet-20241022": {
      "scores": { ... },
      "total_score": 68,
      "status": "ok"
    },
    ...all 9 models...
  }
}
```

---

## Folder Structure Required

Make sure your repo looks like this before running:

```
PS_Data-master/
├── grade_baseline.py        ← the grader script
├── configs/
│   └── models.yaml          ← copy from skeleton repo
├── data/
│   └── final_dataset/
│       ├── Python/
│       │   ├── easy/
│       │   │   ├── off_by_one/
│       │   │   └── logic_error/
│       │   ├── medium/
│       │   └── hard/
│       ├── Java/
│       ├── C++/
│       ├── JavaScript/
│       └── problem_statements/
│           └── p02344.txt   ← one .txt per problem
├── .env                     ← YOU CREATE THIS (see Step 2)
└── .gitignore               ← make sure .env is listed here
```

---

## Step 1 — Install Dependencies

```bash
pip install anthropic openai google-generativeai huggingface-hub pyyaml python-dotenv requests
```

---

## Step 2 — Create the `.env` File

Create a file called `.env` in the root of PS_Data-master (same folder as `grade_baseline.py`) and add your API keys:

```
ANTHROPIC_API_KEY=sk-ant-your-key-here
OPENAI_API_KEY=sk-your-key-here
GOOGLE_API_KEY=AIza-your-key-here
HF_TOKEN=hf_your-token-here
```

**Where to get each key:**

- **Anthropic** → console.anthropic.com → Settings → API Keys
- **OpenAI** → platform.openai.com → API Keys
- **Google** → aistudio.google.com → Get API Key
- **HuggingFace** → huggingface.co → Settings → Access Tokens

> ⚠️ Never push your `.env` file to GitHub. Make sure `.env` is listed in `.gitignore`.

---

## Step 3 — Dry Run First (No API Calls)

Always do a dry run before the real thing to confirm the folder structure and script are working:

```bash
python grade_baseline.py --dry-run --max 5
```

You should see output like this:

```
=================================================================
Multi-Model Baseline Grader
  Models   : ['gpt-4o', 'gpt-4o-mini', 'o3-mini', ...]
  Languages: ['Python', 'Java', 'C++', 'JavaScript']
  Dry run  : True
  Max subs : 5
=================================================================

[1 | 0.0m] Python/easy/logic_error/p02332/s516583347.py
    [openai] gpt-4o ... → 49/100
    [openai] gpt-4o-mini ... → 49/100
    [openai] o3-mini ... → 49/100
    [anthropic] claude-3-5-sonnet-20241022 ... → 49/100
    [anthropic] claude-3-haiku-20240307 ... → 49/100
    [google] gemini-1.5-pro ... → 49/100
    [google] gemini-1.5-flash ... → 49/100
    [huggingface] meta-llama/Llama-3.1-70B-Instruct ... → 49/100
    [huggingface] mistralai/Mistral-7B-Instruct-v0.3 ... → 49/100
```

If you see `[skip] Language folder not found` errors — your folder structure is wrong. Check Step 0 above.

---

## Step 4 — Test With Real API Calls (2 Submissions)

```bash
python grade_baseline.py --max 2
```

This makes real API calls on just 2 submissions. Check the generated `score.json` files to confirm scores look reasonable (not all zeros, not all 100s).

---

## Step 5 — Full Run

```bash
python grade_baseline.py
```

This grades all 641 submissions × 9 models. Expected time varies by API speed — roughly 1-3 hours depending on rate limits.

---

## Resuming After a Crash

The script is fully resumable. If it crashes or you stop it midway, just run the same command again:

```bash
python grade_baseline.py
```

It will automatically skip:
- Submissions where all 9 models already have results
- Individual models that already have results for a submission

So no work is lost and no duplicate API calls are made.

---

## Useful Options

| Command | What it does |
|---|---|
| `--dry-run` | No API calls, uses fake scores for testing |
| `--max 5` | Only grade 5 submissions (for testing) |
| `--language Python` | Only grade Python submissions |
| `--skip-families huggingface` | Skip HuggingFace models |
| `--skip-families openai google` | Skip multiple families |
| `--skip-huggingface` | Shortcut to skip HuggingFace |

Examples:

```bash
# Test only Python with Anthropic models
python grade_baseline.py --language Python --max 10 --skip-families openai google huggingface

# Full run without HuggingFace
python grade_baseline.py --skip-families huggingface

# Full run all 9 models
python grade_baseline.py
```

---

## If a Model Fails

If a model fails due to a missing API key, rate limit, or any other error, the script records the error in the `score.json` and moves on:

```json
"gpt-4o": {
  "scores": null,
  "total_score": null,
  "status": "skipped: OPENAI_API_KEY not set"
}
```

It does NOT crash the whole run. You can re-run later to fill in the failed models — the resume system will pick them up automatically.

---

## Rubric (100 points total)

| Dimension | Points |
|---|---|
| Format / code style | 10 |
| Time complexity | 15 |
| Space complexity | 15 |
| General correctness | 30 |
| Edge case correctness | 30 |

---

## Common Errors

**`FileNotFoundError: configs/models.yaml`**
→ Copy the `configs` folder from the skeleton repo into PS_Data-master.

**`[skip] Language folder not found: data/final_dataset/Python`**
→ Your dataset is not inside a `data/` subfolder. Create a `data` folder and move `final_dataset` inside it.

**`ModuleNotFoundError`**
→ Run `pip install anthropic openai google-generativeai huggingface-hub pyyaml python-dotenv requests`

**`HF_TOKEN not set`**
→ Add `HF_TOKEN=hf_...` to your `.env` file.

**`OPENAI_API_KEY not set`**
→ Add `OPENAI_API_KEY=sk-...` to your `.env` file.
