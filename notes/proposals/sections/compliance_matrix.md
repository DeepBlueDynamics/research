# NP004 compliance matrix (internal; not filed)

Prepared by Claude 2026-09-07 from Navy v2 instructions (`docs/F/F1_...`), CSO preface (`docs/F/F4_...`), the Volume 2 template (`docs/F/F5_...`), the topic/Q&A (`docs/F/F2_..._2026-09-07.md`), and the filing outline. Status: **Done** = drafted and four-agent accepted; **Drafting** = assigned; **Open** = needs company facts or Government clarification.

## A. Format and administrative (rejection risks)

| Requirement | Source | Where answered | Status |
|---|---|---|---|
| Volume 2 ≤ 10 pages, all content counts | Navy v2 p. 3; template | Assembler page check after typesetting | **Open, currently failing in ASCII form:** 581 hard-wrapped lines ≈ 11.4 pages at 11-pt Courier, ≈ 10.4 at 10-pt. Fits at ≈ 7.5–8 pages in 10-pt proportional type. User decision pending (see `../final_pass_claude.md`) |
| Single column, single-spaced, 8.5 × 11, 1-inch margins, ≥ 10-point everywhere | Navy v2 p. 3 (no small-font exception stated) | Typesetting; ASCII draft uses 11-point Courier | Open |
| Base exactly 6 months, ≤ $200,000; Option exactly 6 months, ≤ $115,000; tasks for both clearly identified within Volume 2 | Navy v2 p. 3 | 1.2 SOW (Codex); Volume 3 | Drafting |
| ≥ two-thirds SBC work in base and in option, by direct plus indirect cost | Navy v2 pp. 3–4 | Volume 3; 2.0 consultants line | Open (rates, hours) |
| No cost sharing; travel detail; one-day SYSCOM trip recommended | Navy v2 p. 4 | Volume 3 | Open |
| Use DON Open Topic Volume 2 template headings; remove bracketed guidance | Navy v2 p. 3; template | Assembler | Drafting |
| Disclosure legend on first page and each restricted page, if used | Template; preface | Assembler | Open (company decision) |
| One unencrypted, unlocked PDF; company name, topic, proposal number in headers; virus check; page count check after upload | Preface §3.7(b) | Final PDF | Open |
| SAM active, address match; SBC Control ID; DSIP corporate official certification | Navy v2 pp. 7–8; preface §2.2 | Company | Open |
| CMMC Level 2 (Self) due at award; NIST SP 800-171 assessment in SPRS to be considered for award | Topic header; Navy v2 p. 8 | Company compliance track | Open |
| Volume 4 CCR answer; Volume 6 FWA training; Volume 7 foreign-affiliations webform before certification | Navy v2 pp. 4–5; preface §3.7 | Company | Open |
| Volume 5: ownership certification if applicable, data-rights assertions, prior/pending support, foreign citizens, additional cost detail, TABA request if any | Navy v2 p. 4 | Company | Open |
| No human subjects in Phase I (template says will not be accepted; v2 discourages) | Template §1.2; Navy v2 p. 8; Q&A 9/1 | 1.1 and 1.2: participant research excluded | Done in 1.1; carry into 1.2 |
| GFE not proposed | Navy v2 p. 8 | 1.2, Facilities | Drafting |

## B. Topic and Q&A technical constraints

| Constraint | Source | Where answered | Status |
|---|---|---|---|
| Improve operator understanding of APNT status, confidence, threats, recovery options; unified experience; GPNTS integration target | Topic objective/description; Q&A 8/8, 8/26 | 1.0, 1.1, 1.4 | Done / Drafting (1.4) |
| No new PNT sensors, navigation algorithms, timing sources, hardware | Topic description | 1.0 ¶6 (v3) | Done |
| Visualize source-level health and derive composite confidence | Q&A 8/21, 8/25 | 1.1 O1 | Done |
| Triage fault/jam/spoof; fallback decisions (alternate source, INS-only, degraded ops) | Q&A 8/21 | 1.1 O2; protocol oracle | Done |
| Informational decision aids only in Phase I | Q&A 7/1 | 1.0 ¶6 ("No ship controls will be actuated") | Done |
| Entirely local, 100 percent air-gapped, including AI/ML inference and UI | Q&A 8/20, 8/25; user firm constraint | 1.0 ¶6; 1.1 KPP rows 2–3 | Done |
| 3–8 sources at 1–10 Hz; API-first, modular; ASPN/pntOS; versions post-award | Q&A 8/20, 8/26 | 1.1 envelope | Done |
| Sub-second ingestion to alert and initial COA; rationale may follow | Q&A 8/25; user firm constraint (no percentile allowance) | 1.1 KPP row 1; protocol; reported separately from the offeror gate | Done |
| Offeror-proposed gate: under 100 ms from input receipt to first displayed frame with alert and initial recommendation; any event ≥ 100 ms fails the proposed gate; failure is a reported feasibility limitation | User decision 2026-09-07 (v4 pages and protocol) | 1.0 ¶6, 1.1 question and KPP row, 1.2 B4, 3.0 Month 6 milestone, 1.3 | Aligning across sections |
| Explainability: rationale, composite confidence, evidence; minimum subset first | Q&A 8/20 | 1.0 ¶4; 1.1 evidence-fidelity row | Done |
| Auditable history and short-term replay | Q&A 8/19, 8/20 | 1.1 evidence-fidelity and replay row | Done |
| ECDIS conventions as UX familiarity target, not certification | Q&A 8/28 | 1.0 ¶8 (v3) | Done |
| Single deep use case: destroyer transit, GPS-degraded strait | Q&A 8/8, 8/20 | 1.0 ¶1, ¶3 | Done |
| End-of-Phase-I maturity: design concepts, feasibility evidence, low-to-medium-fidelity demo on simulated data | Q&A 8/8 | 1.1; 1.2 deliverables | Done / Drafting |
| Containerized PoC in isolated runtime encouraged; Iron Bank referenced; Phase I base-image requirement unresolved | Q&A 8/8, 8/28 | 1.1 closing paragraph | Done (flagged open) |
| Phase I data/activity is CUI; synthetic ASPN/pntOS data allowed | Q&A 8/28 | 1.1 closing paragraph; company environment | Open (scope) |
| No human research expected; not a blanket exemption | Q&A 9/1 | 1.1; protocol | Done |
| Government metrics: speed to decision, threat comprehension, decision accuracy, workload; baseline = fragmented physical displays | Q&A 8/8, 8/20, 8/25 | 1.1 (instrumented, not claimed); surrogate labelled synthetic | Done |
| Phase I deliverables: kick-off brief, progress report, final report, initial Phase II proposal | Topic Phase I | 1.2 SOW | Drafting |
| Option must further the effort toward Phase II and bridge the gap | Navy v2 p. 3 | 1.2 SOW option tasks | Drafting |

## C. Evaluation criteria coverage (Navy v2 p. 5; preface §4.2)

| Criterion (descending importance) | Where demonstrated | Gap |
|---|---|---|
| Technical merit, soundness, innovation, incremental progress | 1.0, 1.1, 1.2, protocol | 1.2 pending |
| Qualifications of PI, key staff, consultants, including ability to commercialize | 2.0 | Company confirmations (PI, hours, Clint title, degrees) |
| Commercial potential and benefits | 3.0 | Antigravity drafting; no unsourced market numbers |

## D. Open items requiring people other than agents

1. DSIP technical questions on CUI scope, evaluation activities, and Iron Bank, before 9 Sep 2026 noon ET (filing outline already lists the three questions).
2. Clint Robison's confirmations (checklist items 1–4) before any service wording enters 2.0.
3. Company legal identity, registrations, PI, rates, hours, performance location, CUI environment status, prior/pending support, foreign persons.
4. Re-verify MARAD 2026-008 currency and DSIP amendments in the week of filing.
