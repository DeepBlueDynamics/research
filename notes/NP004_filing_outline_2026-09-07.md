# NP004 filing outline — reviewed 2026-09-07

The repository targets **DON26BX05-NP004**, NAVWAR's open topic for unified assured-PNT operational awareness and decision support. The filing deadline shown by the Navy is **September 23, 2026, noon Eastern (16:00 UTC)**. The public topic page says new DSIP questions close **September 9, noon Eastern**. Recommended internal submission target: September 21. [Navy release calendar](https://www.navysbir.com/topics26_5.htm), [topic/Q&A](https://www.navysbir.com/n26_5/DON26BX05-NP004.htm).

Evidence labels: **Verified** means read in the cited repo file or live page; **recommendation/inference** is our proposed response to that evidence; **unverified** means company information or controlling documents still need checking. Existing SBA/SBIR accounts are user-reported; no private accounts were inspected.

**Repository assessment**

Verified: [README](../README.md) and [BUILDING](../BUILDING.md) describe the corpus, retrieval engine, index and historical retrieval benchmark. [PHASE1_BUILD_PLAN](../PHASE1_BUILD_PLAN.md) supplies architecture, deterministic alert path, simulated strait scenario, component work packages and evaluation intentions. [HMI README](../notes/hmi-mockups/README.md) identifies a notional console with a schematic chart. [Deployment README](../deploy/README.md) describes public demo hosting separately from the intended shipboard runtime.

Inference from the directory scan and proposal-filename search: this is a research/design foundation, not a completed seven-volume filing package. I found no proposal-named files; a submission stored elsewhere remains possible. The build plan does not define a separately scheduled and costed six-month base and six-month option. It also contains assumptions affected by the newer Q&A below.

No builds, performance tests, deployment checks, benchmark reruns, or private advisor-agreement review were performed. Historical benchmark figures are repo claims, not results verified in this review. Do not present them as operator-performance evidence.

**Latest material and its effect**

Verified on the Navy public mirror; newest visible answers are dated September 1. The mirror labels itself unofficial and directs readers to DSIP.

| Date | New information | Recommended proposal treatment |
|---|---|---|
| Aug 28 | Phase I data/activity described as CUI; synthetic ASPN/pntOS data allowed. | Resolve handling and award obligations; do not promise all performance is public/releasable. |
| Aug 28 | ECDIS similarity is a UX familiarity target. | Reduce mandatory standards-certification scope. |
| Aug 28 | Synthetic data conforming to ASPN/pntOS acceptable; GPNTS messages available in Phase II. | Pin public schemas and retain adaptable interfaces. |
| Aug 28 | Iron Bank timing question answered only with synthetic-data guidance. | Timing remains unresolved; do not claim a waiver or a mandatory Phase I base-image requirement. |
| Aug 31 | Adapted commercial integration/decision-support platforms confirmed responsive. | Document existing capability and the specific adaptation. |
| Sep 1 | No human research expected. | Reconcile planned participant studies with ordinary design/SME evaluation. |
| Sep 1 | Phase II facility clearance not expected. | Do not infer personnel-clearance or CUI exemptions. |

Source: [current topic/Q&A](https://www.navysbir.com/n26_5/DON26BX05-NP004.htm). The CUI answer does not by itself classify existing public repo material as CUI. The human-research answer is not an IRB determination for an arbitrary study we design.

Verified separately: CMMC Level 2 assessment guidance uses **NIST SP 800-171 Revision 2**. The build plan's equation of CMMC L2 with a Rev 3 self-assessment needs correction before reuse. Navy v2 p. 8 states CMMC requirements are due at award and requires a current NIST assessment in SPRS to be considered for award. Preface §2.6 confirms Rev 2, Level 2 assessment every three years and annual affirmation; its July 2026 suspension concerns the CMMC rollout's Phase II, not SBIR Phase II, and leaves self-assessment requirements in place. Scope the actual environment and flow-down obligations; do not claim a status not held. [Official Level 2 assessment guide](https://dodcio.defense.gov/Portals/0/Documents/CMMC/AssessmentGuideL2v2.pdf), [SPRS CMMC guidance](https://www.sprs.csd.disa.mil/cmmc.htm).

**First filing work: company readiness**

Recommendation: have the corporate official verify these immediately. An SBA login alone does not establish submission readiness.

| Item | What to verify or collect |
|---|---|
| SBA/SBIR registration | Existing company registration, SBC Control ID, and Proof of Registration/Certification required at submission (preface §2.2). |
| DSIP | Login.gov access; company association; correct firm profile; authorized corporate official able to certify; create the NP004 proposal record. |
| SAM.gov | Active entity registration, UEI, CAGE, current representations/certifications and matching address. Navy recommends registration not expire within 60 days of close; confirm registration for contracts, not only grants. Active SAM required at award (Navy v2 pp. 7–8). |
| Eligibility | Ownership/control and affiliates, size, US performance locations, PI primary employment at award/performance; document any applicable ownership exception. |
| Team | Named PI, personnel roles/hours/rates, relevant short bios, advisor/consultant commitments and rights terms, subcontractor quotes. |
| Commercialization | Existing product evidence, customers/revenue only where supportable, IP ownership, Navy transition route and credible dual-use market. |
| Disclosures | Foreign affiliations/relationships, foreign personnel as applicable, other support and overlapping proposals/awards; complete official forms accurately. |

The program guidance distinguishes DSIP, SBIR.gov and SAM registrations, requires the SBC Control ID before submission, and requires corporate-official certification to complete filing. PI primary employment and US R&D requirements are also stated there. The generic guidance is subordinate to this cycle's instructions. [Official program/submission guide](https://www.defensesbirsttr.mil/SBIR-STTR/Program/).

**Submission checklist — verified against Navy v2 and current preface**

Verified in [Navy v2 instructions, PDF pages 2–8](../docs/F/F1_NAVY_SBIR_26BX_R5_v2_2026-09-07.md), downloaded from DSIP on September 7, and the [current CSO preface](../docs/F/F4_DOW_CSO_R5_PREFACE_2026-09-07.md). Navy-specific instructions take precedence over generic preface instructions. The limits below are confirmed in v2.

| Volume | Required work under local instructions |
|---|---|
| 1 — Cover sheet | DSIP proposal/company information, abstract/benefit text and certifications required by the current form. Match topic and company identifiers. |
| 2 — Technical | At most 10 pages total; single column, single-spaced, US Letter, one-inch margins, minimum 10-point font. Include base and option tasks within the limit. Use the **Open Topics CSO** template. |
| 3 — Cost | Base: exactly 6 months, at most $200,000. Option: exactly 6 months, at most $115,000. Separate budgets; minimum two-thirds SBC work in **each**, calculated using direct and indirect costs per instructions. No cost sharing. |
| 4 — Commercialization report | If prior SBIR/STTR awards exist, firm admin uploads certified SBA CCR PDF to DSIP Firm Forms. If none, answer NO; no CCR upload required (preface §3.7(e)). |
| 5 — Supporting documents | Applicable administrative material: supporting costs, certifications, data-rights assertions, similar support, foreign personnel and ownership material. Do not place technical overflow/resumes here. |
| 6 — Fraud/waste/abuse | Proposal Owner reviews the required FWA training annually and completes Volume 6 (preface §3.7(g)). |
| 7 — Foreign affiliations | Complete and submit DSIP webform before corporate certification; PDF uploads and Volume 5 substitutes are not accepted (preface §3.7(h)). |

Navy v2 specifies one evaluated proposal per company per open topic; the latest certified/submitted version governs if multiple exist. Awards are Prototype OTs. Optional Phase I TABA is confirmed at up to $6,500 additional, subject to its separate detailed request and cost rules. Cost evidence needs prime/subcontract labor, indirect rates, materials, travel and fee detail. Consultant classification affects the two-thirds calculation.

Downloaded and extracted the [Open Topic Volume 2 template](../corpus/F/templates/DON_SBIR_Phase_I_OPEN_TOPICS_Technical_Volume_2_Template_2026-0304.docx) and [Volume 5 template](../corpus/F/templates/DON_SBIR_STTR_Ph_I_and_II_Sup_Doc_Vol_5_Template_02_12_25.docx) from the [Navy forms page](https://www.navysbir.com/links_forms.htm). [Extracted template text](../docs/F/F5_Navy_Volume_2_and_5_templates_2026-09-07.md) preserves paragraph content, not Word layout.

Use the actual Volume 2 headings: 1.0 Description of Proposed Phase I Technical Effort; 1.1 Technical Objectives; 1.2 Base and Option SOW; 1.3 Related Work; 1.4 Defense Need; 2.0 Key Personnel; 3.0 Commercialization/Transition Plan Summary; Facilities/Equipment. Remove instruction pages and bracketed guidance. The template permits smaller text in figures/tables/headers, but v2 states a 10-point minimum without that exception; recommendation: use at least 10-point throughout. The template says human-subject Phase I proposals will not be accepted, while v2 describes a conditional approval process and recommends avoiding them. For NP004, follow its no-human-research expectation and clarify any proposed participant activity. Do not treat generic template IP/clause wording as overriding the amended CSO/OT terms.

**Recommended proposal-writing sequence**

1. Freeze a one-paragraph offer and evidence inventory: existing software and interface work, adaptation needed, technical uncertainty to resolve, and operator benefit. Use the build plan's single strait scenario and deterministic alert path; label proposed capabilities and mockups honestly.
2. Build the compliance matrix against current CSO, topic/Q&A and template headings. Include where each requirement is answered and what evidence supports it.
3. Turn the engineering stages into a six-month base: requirements/interface mapping; synthetic-data fixtures; integrated low/medium-fidelity demonstration; feasibility measurements; final report and initial Phase II proposal. Map named personnel, hours, deliverables and acceptance evidence to each task.
4. Define a separate six-month option that advances Phase II readiness: refine interfaces and design, extend agreed scenario coverage, mature deployment/security artifacts and finalize integration planning. Price separately; do not promise government data/access before it is available.
5. Prepare an operator-evaluation approach compatible with the clarified scope. Propose measurable criteria and label improvement percentages as targets until measured. Seek clarification on the human-research boundary before committing to participant studies.
6. Write personnel qualifications and commercialization inside Volume 2. Explain government transition responsibilities without implying an endorsement or customer commitment that has not been obtained.
7. Reconcile technical scope, schedule and both budgets; prepare the remaining DSIP volumes.
8. Conduct PDF-format and content review, validate all DSIP forms, have the corporate official certify and submit, and retain the confirmation, final PDFs and exported proposal record. After any edits, confirm submission status again.

Use the [ten-page Volume 2 layout plan](NP004_volume2_layout.md), incorporating the user-supplied Forward Edge historical sample's presentation approach while preserving the current Navy template headings. It budgets two pages for technical effort, one for objectives, three for base/option SOW, one for related work/defense need, one for personnel, one for commercialization and one for facilities/references. All content counts.

Recommendation: prioritize the proposal and credible feasibility evidence before implementing the entire build plan. Its chart-data acquisition, full symbology conformance and expanded simulator are engineering choices to cost and justify, not automatically pre-filing prerequisites.

**Questions prepared for DSIP — not sent**

Submit technical questions before September 9 noon Eastern; use the program office for administrative solicitation questions.

- The August 28 answer describes all Phase I data/activity as CUI while allowing public-standard synthetic data. Which categories, deliverables, markings and handling obligations apply to a pre-existing public platform and synthetic demonstration, and when must the required environment/assessment be in place?
- In light of September 1's no-human-research answer, which SME walkthroughs, task-based usability activities and operator-effectiveness measurements are expected/acceptable for Phase I, and who determines whether a proposed activity is human research?
- Does the Phase I final demonstration require an Iron Bank base image, or is an isolated commercial-container proof of concept with a documented Iron Bank transition plan sufficient?

**Recommended calendar and remaining verification**

| Date | Exit condition |
|---|---|
| Sep 7–8 | DSIP/SAM/SBC identifiers verified; current CSO/preface/templates obtained; PI and proposal owners assigned. |
| Before Sep 9 noon ET | Needed technical questions submitted in DSIP. |
| Sep 9–13 | Complete first technical draft, base/option budgets, team commitments, commercialization evidence. |
| Sep 14–17 | Scope/evidence review; reconcile Q&A and costs; finish administrative volumes. |
| Sep 18–20 | Check final PDF format, all certifications, consistency and latest amendments. |
| Sep 21 | Corporate official certifies/submits; archive confirmation. |
| Sep 22–23 | Contingency only; published close Sep 23 noon ET. |

Refreshed rendered topic/Q&A text was saved to [corpus capture](../corpus/F/F2_DON26BX05-NP004_topic_2026-09-07.md) and [docs capture](../docs/F/F2_DON26BX05-NP004_topic_2026-09-07.md). August 26 versions remain for comparison. New captures are browser-extracted text, not original HTML or an authenticated DSIP export. Existing index was not rebuilt; its old snapshot does not contain the new capture.

**Retrieval update:** After the user confirmed the host crawler address, retrying `http://host.docker.internal:6792` succeeded. Downloaded Navy v2 (305,090 bytes), CSO preface (715,243 bytes), Volume 2 DOCX (47,523 bytes), and Volume 5 DOCX (37,746 bytes). PDF content was extracted through the browser PDF.js API; DOCX paragraph text through document.xml. The earlier access failure is resolved for these files. Company account state and authenticated DSIP Q&A remain unchecked. The public Q&A ambiguity on CUI scope and evaluation activities remains. No external messages, submissions, deployments or index rebuilds were performed.

**Additional verified filing details**

- Preface §3.7(e): changing the firm CCR or saving/submitting Volume 4 can reopen previously submitted Phase I/Direct-to-Phase-II proposals under any still-open solicitation. Re-certify and re-submit every affected proposal.
- Preface §3.7(b): Volume 2 is one unencrypted, unlocked PDF, with consecutive pages and company name/topic/proposal number in headers. Run a virus check before upload; check page count after DSIP upload. No embedded active media.
- Preface §2.9: collect organizational-conflict disclosures for the firm and team, including consultants; affirm whether relevant SETA/advisory support exists or ended within the preceding year, with mitigation details if applicable.
- Navy v2 pp. 9–10 clarifies three base payments: 50% at day 15, 35% at day 90, 15% at day 180; the same percentages/timing apply to an exercised option. This corrects the older local text's inconsistent base-payment description. These are the solicitation schedule, not an unconditional guarantee of payment outside the award terms.

Confirmed deadlines in preface §7.0: September 9 noon ET Q&A close and September 23 noon ET proposal close. Recheck DSIP for later amendments before submission.
