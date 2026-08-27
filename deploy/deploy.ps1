# One-command Cloud Run deploy for the APNT console demo.
# Run from this deploy/ directory on the host:  .\deploy.ps1
# Host-only (PowerShell + gcloud); no Python/PyMuPDF needed at deploy time.
#
# Two passes: (1) deploy to learn the service URL, (2) bake that URL into the
# OG/Twitter meta (Twitter needs an absolute image URL) and redeploy so the card
# renders when the link is shared.
param(
  [string]$Project = $(gcloud config get-value project 2>$null),
  [string]$Region  = "us-central1",
  [string]$Service = "apnt-console"
)
if (-not $Project) { Write-Error "No GCP project set. Run: gcloud config set project <id>"; exit 1 }

Write-Host "== Pass 1: deploy to $Service ($Region / $Project) =="
gcloud run deploy $Service --source . --region $Region --project $Project `
  --port 8080 --allow-unauthenticated --quiet
if ($LASTEXITCODE -ne 0) { Write-Error "deploy pass 1 failed"; exit 1 }

$URL = gcloud run services describe $Service --region $Region --project $Project `
  --format "value(status.url)"
Write-Host "Service URL: $URL"

Write-Host "== Pass 2: bake OG/Twitter absolute URLs and redeploy =="
(Get-Content index.html -Raw).Replace("__DEPLOY_URL__", $URL) | Set-Content index.html -NoNewline
gcloud run deploy $Service --source . --region $Region --project $Project `
  --port 8080 --allow-unauthenticated --quiet

Write-Host ""
Write-Host "LIVE : $URL"
Write-Host "CARD : $URL/og-card.png"
Write-Host "Validate the card at https://cards-dev.twitter.com/validator (paste $URL)"
