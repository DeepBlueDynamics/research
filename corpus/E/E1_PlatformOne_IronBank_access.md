<!-- id: E1 -->
<!-- title: Platform One / Iron Bank — access and hardened-container overview -->
<!-- category: E -->
<!-- license: FREE -->
<!-- sources: https://docs-ironbank.dso.mil/overview/ ; https://docs-ironbank.dso.mil/faq/ ; https://p1.dso.mil/services/iron-bank ; https://ironbank.dso.mil/about -->
<!-- retrieved_at: 2026-08-27 -->
<!-- notes: Named explicitly in DON26BX05-NP004 Q&A (08/08 containerization answer: "Reference DoD Platform One Iron Bank for approved images"). Public at IL2. -->

# Platform One / Iron Bank — access (spec item E1)

## Bottom line
Iron Bank is the DoD's repository of **hardened container images** (1000+ vendor and
open-source containers, each with a compliance/vulnerability Body of Evidence and an
Overall Risk Assessment score). **Iron Bank and Repo1 (GitLab) are completely open to
the public at IL2 — there is no locked-down version.** No cost to users. Named in the
NP004 Q&A as the approved-image source for the containerized deployment.

## How to get it
1. **Browse the catalog (no account):** https://ironbank.dso.mil/about → "Browse All
   Hardened Containers." Each entry links its documentation and BoE.
2. **Register for a Repo1/P1 SSO account (free):** https://sso-info.il2.dso.mil/new_account.html
   — under the "MFA Log In" button there is a registration link. Same credentials sign
   into Repo1 (GitLab, the hardening-pipeline source) and the registry.
3. **Pull images:** `docker login registry1.dso.mil -u <user> -p <token>` then pull the
   image path shown on its catalog page.
4. **Support contact:** aflcmc.hncx.p1cst@us.af.mil

## What matters for NP004 Phase I
- **Rebase onto an Iron Bank base image** — that is the mechanism by which your
  containers become "hardened." (Verified Publisher program is the exception.)
- **Internet-disconnected build processes** are required — aligns with the topic's
  100% air-gapped constraint.
- Hardened containers do **not** carry an ATO or CtF by themselves; the ORA score helps
  the fielding program assess risk. ATO is earned in the downstream environment via the
  DevSecOps Reference Design. So for Phase I you demonstrate *hardening-ready*
  containerization, not an accredited system.
- IL levels: **IL2 today**; IL5/IL6 in progress.

## Related public docs to pull if needed
- DoD Container Hardening Guide / DevSecOps Reference Design: https://software.af.mil/dsop/documents/
- Acceptance Baseline Criteria: https://docs-ironbank.dso.mil/reference/abc/
- Overall Risk Assessment: https://docs-ironbank.dso.mil/reference/ora/
