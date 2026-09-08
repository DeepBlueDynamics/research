# How to Reference Shit in This Project

**Project:** DON26BX05-NP004 — Unified Assured PNT Operational Awareness and Decision Support  
**Last reviewed:** September 7, 2026  
**Purpose:** Find the actual rule, distinguish it from our design choices, and leave a citation the next person can verify.

## Start with the answer about page limits

**The Navy caps the entire Technical Volume (Volume 2) at 10 pages. The saved Navy v2 instructions and Open Topic template do not impose a separate one-page limit on the problem statement or technical objectives.**

“One page for the problem; one page for objectives/KPPs” is our drafting allocation. We may redistribute that space while keeping every required section inside the total limit. A sample winning proposal is an example of presentation, not a controlling rule.

Verified in [Navy v2 instructions, PDF page 3](corpus/F/F1_NAVY_SBIR_26BX_R5_v2_2026-09-07.pdf#page=3) and the [Open Topic template text](docs/F/F5_Navy_Volume_2_and_5_templates_2026-09-07.md), “Format” and section instructions:

| Item | Actual requirement / project choice |
|---|---|
| Total Volume 2 length | At most 10 pages, regardless of content. |
| What counts | All content: prose, tables, figures, references, personnel/resumes, base and option work. Do not assume an extra title/reference page is free. |
| Paper and margins | US Letter, one-inch margins on all sides. |
| Layout | Single column; single-spaced typed lines. |
| Font | Navy v2 states at least 10 point. Our suggested 11-point body and 13–14-point headings are readability choices. |
| Table/font exception | The DOCX template permits smaller type for certain elements, but Navy v2 states a 10-point minimum without that exception. Use at least 10 point throughout unless the Government resolves the discrepancy otherwise. |
| Individual section size | No separate page or word cap found for these opening sections in the saved Navy-specific instructions/template. |
| Volume 5 | Administrative support only. Do not move technical overflow, resumes, test data or publications there to evade Volume 2's cap. Navy v2 PDF page 4. |
| Our screen preview | Markdown and browser geometry are drafting aids. The final exported PDF, with actual fonts, spacing, headers, tables and page breaks, is the page-count authority. |

The earlier browser fit check used 11-point Arial, 13-point headings and 1.15 line height. It demonstrated space in that browser layout; it was **not** verification of the required final single-spaced submission PDF.

## Which source wins?

1. **Current solicitation and applicable amendments in DSIP.** Check the actual release/topic; do not borrow another year's or another component's instructions.
2. **Navy-specific instructions for this release.** Navy v2 PDF page 1 expressly says its instructions take precedence over the DoW-wide instructions.
3. **The current NP004 topic and dated Q&A** for technical scope and clarifications. Read the answer, its question and its date. A Q&A answer on one subject does not automatically waive a different administrative rule.
4. **The Navy Phase I Open Topics (CSO) template**, used together with the instructions. Do not substitute Conventional Topic, Direct-to-Phase-II or generic preface headings.
5. **Technical primary sources** for engineering facts: the actual standard, policy, advisory, specification, paper or source code.
6. **Our notes, designs, agent drafts, Discord messages and external samples** are working material. They point to evidence; they are not that evidence.

This is a lookup/interpretation order, not permission to invent a resolution to a conflict. Record both passages, their versions and dates. Use the applicable explicit precedence rule; otherwise prepare a clarification.

The Navy topic website is a public mirror and identifies itself as unofficial. Retain it for convenience, but check authenticated DSIP before filing. A new file timestamp alone does not prove a document is a new official revision.

## The rules are saved locally

| Reference | Searchable local copy | Original / locator |
|---|---|---|
| **NAVY-v2** — Navy 2026 Release 5 instructions | [Text](docs/F/F1_NAVY_SBIR_26BX_R5_v2_2026-09-07.md) | [PDF](corpus/F/F1_NAVY_SBIR_26BX_R5_v2_2026-09-07.pdf). PDF p.1 precedence; p.3 format, duration and cost; p.4 Volume 5 restrictions; p.5 evaluation. |
| **CSO-preface** — current saved DoW-wide preface, Amendment 2 | [Text](docs/F/F4_DOW_CSO_R5_PREFACE_2026-09-07.md) | [PDF](corpus/F/F4_DOW_CSO_R5_PREFACE_2026-09-07.pdf). §2.3 DSIP access; §2.10 human research; §3.7 volumes; §6.2 questions; §7.0 release dates. |
| **NP004-QA** — topic and Q&A captured September 7 | [Text](docs/F/F2_DON26BX05-NP004_topic_2026-09-07.md) | [Saved web capture](corpus/F/F2_DON26BX05-NP004_topic_2026-09-07.md). Cite the dated question/answer, not just the page title. |
| **V2-template** — Navy Phase I Open Topics | [Combined template extraction](docs/F/F5_Navy_Volume_2_and_5_templates_2026-09-07.md) | [DOCX](corpus/F/templates/DON_SBIR_Phase_I_OPEN_TOPICS_Technical_Volume_2_Template_2026-0304.docx). Extraction preserves paragraph text, not Word layout. |
| **V5-template** — supporting documents | Same combined extraction, after DOCUMENT_BREAK | [DOCX](corpus/F/templates/DON_SBIR_STTR_Ph_I_and_II_Sup_Doc_Vol_5_Template_02_12_25.docx). |
| Working filing checklist | [Filing outline](notes/NP004_filing_outline_2026-09-07.md) | Interpretation and task list; verify claims against the originals above. |
| Working page allocation | [Volume 2 layout](notes/NP004_volume2_layout.md) | Editable planning budget, not a section-size requirement. |

Official refresh locations:

- [DSIP](https://www.dodsbirsttr.mil/submissions/login).
- [Navy v2 download endpoint](https://www.dodsbirsttr.mil/submissions/api/public/download/solicitationDocuments?component=NAVY&documentType=INSTRUCTIONS&release=5&solicitation=DOD_SBIR_2026_P1_CBX).
- [Release preface download endpoint](https://www.dodsbirsttr.mil/submissions/api/public/download/solicitationDocuments?documentType=RELEASE_PREFACE&release=5&solicitation=DOD_SBIR_2026_P1_CBX).
- [Navy forms/templates](https://www.navysbir.com/links_forms.htm) — choose **Phase I Open Topics (CSO)**.
- [NP004 public topic/Q&A](https://www.navysbir.com/n26_5/DON26BX05-NP004.htm).

Original PDFs, both DOCX templates and the September 7 captures were confirmed present when this guide was written. The forms page was checked live; the current DSIP PDF was not re-downloaded in this guide-writing pass. “Saved September 7” is not a promise that no later amendment exists.

## Map our drafting headings to the real template

| Our current working content | Navy template destination |
|---|---|
| Problem, scenario, proposed solution and innovation | **1.0 Description of Proposed Phase I Technical Effort** |
| Technical objectives and KPPs | **1.1 Phase I Technical Objectives** |
| Base and option tasks, schedule, performers, deliverables | **1.2 Phase I (Base and Option) Statement of Work** |
| Prior relevant work | **1.3 Related Work** |
| Customer, defense use case, differentiation and applicability | **1.4 Defense Need** |
| Kord/Clint qualifications and roles | **2.0 Key Personnel** |
| Commercialization and transition | **3.0 Commercialization/Transition Plan Summary** |
| Facilities and equipment | **Facilities/Equipment** |

The presentation draft currently uses the user's two opening-section headings. Before filing, map it into the Navy template rather than treating those two headings as a complete compliant Volume 2. Avoid duplicating the same scenario in 1.0 and 1.4 just to fill both.

## Where the rest of the evidence lives

- **docs/**: searchable text. A = interfaces/data; B = displays/alerting; C = resilient-PNT policy/advisories; E = deployment/security; F = solicitation/topic.
- **corpus/**: original PDFs, archives and captured pages. Open these when exact wording, tables or pagination matter.
- **crawl_cache/**: crawler output. Check source URL, retrieval date and extraction quality before citing.
- **vendors/**: competitor research. Verify an award against its original award record; distinguish an award from a topic or vendor marketing.
- **notes/resumes/sources/**: LinkedIn captures. They establish what a profile said, not independently verified qualifications.
- **notes/resumes/clint_personnel_wording_pending.md**: user-proposed personnel language and unresolved duty/training claims.
- **notes/proposals/submission_draft.md**: current clean presentation draft, including later editorial cuts and the proposed <100 ms KPP.
- **notes/proposals/opening_pages/**: four independent drafts, research notes, counterarguments, acceptance records and protocols. [Index](notes/proposals/opening_pages/README.md).
- **PHASE1_BUILD_PLAN.md**: earlier engineering plan, with assumptions superseded by later Q&A. Never treat it as Navy authority.
- **BUILDING.md / lume/**: retrieval implementation and historical benchmarks. Retrieval performance is not APNT or human-performance evidence.

Agent acceptance applies to the specific version reviewed. The four-agent agreement covers shared v3. The later <100 ms proposal and presentation edits have not inherited that acceptance automatically.

## How to reference a claim

For each material claim, retain:

**Claim → evidence status → source/version → exact locator → URL/local original → retrieval date → limitation.**

Use these statuses consistently:

- **Verified:** read in a named source or observed in a named test. Say what was verified.
- **Inferred:** reasoned from cited facts; explain the inference.
- **Proposed:** our design, schedule, budget or performance target.
- **Assumed / pending:** unchecked input, such as company role, availability or service qualification.
- **Measured:** a result with test configuration, sample, date and retained output.

Examples:

> **Verified rule:** Volume 2 is limited to 10 pages in total.  
> NAVY-v2, “Phase I Submission Requirements — Technical Proposal,” PDF p.3, saved September 7, 2026. [Original](corpus/F/F1_NAVY_SBIR_26BX_R5_v2_2026-09-07.pdf#page=3).

> **Proposed KPP:** <100 ms from input receipt to the first displayed frame containing the alert and initial recommendation, with hardening enabled.  
> User proposal September 7; [proposed protocol](notes/proposals/opening_pages/proposed_v4_protocol_100ms.md). This is stricter than the topic's sub-second requirement and has not been measured.

> **Pending personnel claim:** Clint's bridge-watchstanding or ECDIS experience.  
> Confirm the specific role, qualification and dates; neither an EM4 rating nor assignment to a ship establishes those duties by itself.

For the filed proposal, use compact numbered references in prose and a bibliography **inside** the page limit. Cite the authoritative title, revision/date and page/section; use a public URL where available. A reviewer cannot follow our local filesystem links. Local paths are for the team's traceability, not substitutes for submission citations.

Distinguish PDF viewer page numbers from printed page numbers. The preface has front matter, so its PDF and printed page numbers differ. Prefer a section locator such as §6.2 alongside the page. September 7 PDF.js text uses “PAGE N”; older extractions may have provenance hashes and linked page markers. Do not assume every file has the same extraction format.

## Search, verify, then write

1. Find the passage in **docs/** using MCP nuts_search; read its surrounding text with nuts_read. Search results are leads.
2. Open the original PDF/DOCX or live authoritative page for wording, exceptions, tables and dates. A snippet, LLM answer or agent citation register is not sufficient.
3. Check whether a later revision/Q&A changes the claim. Keep older copies as history with their original dates.
4. Write the claim no broader than the evidence supports. If a source is unavailable or only an abstract was read, state that; do not invent page references.
5. Save the citation and unresolved assumptions in the research notes. Keep the clean proposal readable; keep review history in the review files.
6. For a fresh fetch, save the original under corpus/ and searchable extraction under docs/ with URL, date, revision and extraction method. Record hashes where supported. Do not silently overwrite an earlier capture.
7. Check index freshness before relying on retrieval. The September 7 filing/drafting work did not rebuild .lume-index. Use the REPL's :verify / :history and inspect the underlying file; do not assume new captures are indexed. Rebuild only as an intentional operation, then record the snapshot.
8. Recheck DSIP immediately before filing and validate the exported/uploaded PDF page count. Do not infer submission from “In Progress” or “Ready to Certify.”

Use nuts_* MCP tools for file work in this workspace. Do not hand-edit agent configuration or managed AGENTS.md to install this guide. The [README](README.md) links here so future sessions can find it.

## Known traps to avoid

| Trap | Correct treatment |
|---|---|
| “Page 1 and Page 2 must each be one page” | Our allocation; the formal constraint is 10 pages total. |
| “11 point is mandatory” | Our recommendation. Navy v2 minimum is 10 point. |
| “<100 ms is the Navy requirement / already achieved” | Proposed tighter KPP, not measured performance. |
| “Synthetic means publicly releasable” | August 28 Q&A describes Phase I data/activity as CUI. Resolve categories/handling; do not automatically relabel pre-existing public sources. |
| “No human research expected means our study is exempt” | September 1 answer is not an IRB determination for a study we invent. |
| “ECDIS-like means certified” | August 28 calls it a UX familiarity target. |
| “Iron Bank timing is settled” | The specific Phase I base-image question was not directly answered. |
| “CMMC L2 uses the Rev 3 document in docs/E” | The saved filing review identifies Rev 2 for the applicable L2 assessment guidance. Consult the current preface/assessment authority, not whichever NIST PDF is nearby. |
| “Two agreeing receivers guarantee assurance” | Check dependencies, freshness and available independent evidence. |
| “The scenario succeeded, so the product passed” | A narrated scenario or mocked UI is not a measured test. |
| “A historical agent post proves competitor coverage or award details” | Read the underlying award/source; mark gaps in the search rather than asserting absence. |
| “Questions close September 9, so they must answer within 24 hours” | That is the submission cutoff. Saved preface §6.2 says answers are generally posted within seven business days. |
| “Clint must register just to be named” | DSIP users need their own account/firm access; named personnel do not need portal access solely to appear in the proposal. Preface §2.3. |

## Before handing a draft to the next person

Identify the exact draft/version, which rules were checked, date of the last source refresh, open company/Government questions, and tests/layout checks actually performed. Preserve citations through rewrites. Agreement on prose does not validate an untested capability.

Current working filing questions and account/cost tasks: [filing outline](notes/NP004_filing_outline_2026-09-07.md). Current personnel clarification checklist: [Clint checklist](notes/resumes/clint_discord_clarifications.md).
