# Mock-UI deploy trail

Running log of every mock UI we publish or deploy for NP004. Newest first.
Add a row whenever a mock is published as an Artifact or deployed to a host.

| Date | Name | Source | Artifact URL | Cloud URL | State | Notes |
|---|---|---|---|---|---|---|
| 2026-08-27 | SEXTANT (was Assured-PNT Console v1) | `notes/hmi-mockups/apnt-console.html` | https://claude.ai/code/artifact/f92e6605-6f0c-44ae-8aa2-2030698e4915 | _pending_ (`deploy/deploy.ps1` → Cloud Run `apnt-console`) | Artifact live; Cloud Run deploy staged, blocked on Hyperia pane | Interactive: Nominal⇄Degraded, S-52 Day/Dusk/Night. Widget toolkit reference. Twitter card = `deploy/og-card.png`. Supersedes the 4 DO-NOT-USE ChatGPT images. |

## Conventions
- **Artifact URL** = claude.ai/code artifact (private until shared).
- **Cloud URL** = public Cloud Run demo (via `deploy/`), *not* the air-gapped Phase I build.
- Keep `og-card.png` per deployed mock if the branding differs.
- When a mock is superseded, keep its row and mark State = superseded.
