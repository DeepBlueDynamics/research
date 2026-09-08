# Independent opening-pages assignment — NP004

User requests each agent independently research and draft:
Page 1: 1. Identification and Significance of the Problem / Operational Need
Page 2: 2. Phase I Technical Objectives & Key Performance Parameters (KPPs)

Deliver roughly one page of content for each (target 450–550 words/page, less with tables). Markdown drafting targets are not verified PDF pagination. Use the user headings for this exercise; identify mapping to Navy Volume 2 sections 1.0/1.4 and 1.1 in separate research notes. Do not modify official template headings or shared build plan.

Read README.md, PHASE1_BUILD_PLAN.md, notes/NP004_filing_outline_2026-09-07.md, docs/F/F1_NAVY_SBIR_26BX_R5_v2_2026-09-07.md, docs/F/F4_DOW_CSO_R5_PREFACE_2026-09-07.md and the September 7 topic/Q&A capture. Research current authoritative public sources; verify citations and dates. Latest public topic mirror: https://www.navysbir.com/n26_5/DON26BX05-NP004.htm . Crawler endpoint inside container: http://host.docker.internal:6792.

User's conceptual direction: explore a Kobayashi Maru style evaluation of problem solving. Under progressive PNT degradation, assess what is known, expose failed assumptions/dependencies, and identify what independent evidence would resolve ambiguity. No-win cases should allow appropriate uncertainty/abstention; do not force a single correct COA. Include recoverable and nominal cases to avoid rewarding permanent abstention. Reproducible scenarios, ground truth separate from system inputs, held-out cases, identical baseline/prototype inputs. Frame as a proposal hypothesis, not a Navy requirement. Keep unified APNT operator awareness as the product; the simulator is feasibility/evaluation infrastructure. No new sensors/navigation algorithms or autonomous ship control. Initial recommendations informational; local/air-gapped architecture; source and composite confidence; 3–8 sources at 1–10 Hz; subsecond ingestion-to-alert/initial COA per Q&A.

User clarification: air-gapped, secured and subsecond are mandatory. Define a concrete secured-runtime gate (least privilege, controlled access, pinned/scanned dependencies, audit and protected data/configuration; no unsupported accreditation claim). No percentile allowance may excuse >=1-second initial-alert/COA events. Local inference and UI also belong inside the airgap.

KPPs: explicitly distinguish source-stated requirements, our proposed measurable targets, and unverified assumptions. Define measurement boundaries, denominator/sample size or plan to choose it, baseline, test method, and failure criteria. Do not invent measured improvements, government acceptance thresholds, operational endorsements or project commitments. Account for latest Q&A: ECDIS familiarity is a UX target; no human research expected; Phase I CUI answer needs scope clarification. Do not claim synthetic implies unrestricted/public performance.

Write ONLY your own output files in notes/proposals/opening_pages/:
<agent>_pages_1_2.md — proposal prose plus compact source markers
<agent>_research_notes.md — sources with URLs/clauses, assumptions, KPP rationale, uncertainty and unresolved issues
Use agent keys claude, antigravity, grok, codex.
Use MCP file tools. Claude on host: same navy repo is C:\Users\kordl\Code\research\navy. Container repo /workspace/navy. Do not read other agents' drafts until you finish your own; no further delegation or messages to external people. Do not submit to DSIP or alter accounts/configuration. Report completion and paths to coordinating Codex pane (address in task message), or clearly in your terminal.