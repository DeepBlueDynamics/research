# deploy/ — public demo hosting for the APNT console

Serves `notes/hmi-mockups/apnt-console.html` as a standalone static site on Google
Cloud Run, with an Open Graph / Twitter `summary_large_image` card so the link
previews well when shared.

> This is the **public demo** path only. It is **not** the air-gapped, Iron Bank
> hardened container required for the Phase I deliverable — that stays separate
> (see `PHASE1_BUILD_PLAN.md` §5-W5). Don't conflate the two in the proposal.

## Files
- `build_deploy.py` — (container) rasterizes `og-card.png` (PyMuPDF) and wraps the
  console into a standalone `index.html` with OG/Twitter meta. Re-run after editing
  the console: `python3 build_deploy.py [DEPLOY_URL]`.
- `index.html` — generated standalone page (do not hand-edit; regenerate).
- `og-card.png` — 2400×1260 social card.
- `Dockerfile` + `nginx.conf` — nginx:alpine serving on :8080 (Cloud Run).
- `deploy.ps1` — one-command deploy (host: PowerShell + gcloud).

## Deploy
```powershell
cd deploy
gcloud config set project <your-project>   # once
.\deploy.ps1                                # deploys, bakes card URL, redeploys
```
Prereqs: `gcloud` authenticated (`gcloud auth login`), Cloud Run + Cloud Build APIs
enabled, billing on. The script prints the live URL and the card URL.

## Twitter/OG
`index.html` carries `twitter:card=summary_large_image` + `og:image` → `og-card.png`.
After deploy, paste the URL into the X/Twitter card validator to confirm the preview.
