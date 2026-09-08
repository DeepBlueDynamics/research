# ACME sample vs assembled NP004 draft — Grok comparison

**Date:** 2026-09-07  
**Sample (writing example only):** Forward Edge “Sample Winning Phase I SBIR (DOD),” published 28 Jan 2024; local crawl `crawl_cache/support.forwardedge.ai/en_articles_8864982-sample-winning-phase-i-sbir-dod_1788786326690_2e3af68e.md`; original https://support.forwardedge.ai/en/articles/8864982-sample-winning-phase-i-sbir-dod. Publisher states the content is over 20 years old. Award status not independently verified. Cartoon names (Acme Dynamite, Road Runner, etc.). Solicitation N091-076, not NP004.  
**Our draft:** `notes/proposals/submission_draft.md` (read in full this session; includes nemesis8 container language and technical-approach / combative-training additions).  
**Not controlling:** sample section numbers, web-service architecture, consultant percentages, IP split, “existing customers,” or any claim about our capabilities.  
**Must retain:** current NP004 rules; secured air-gap; deterministic initial alert/recommendation path; offeror **&lt;100 ms** gate (Government requirement remains **under one second**); no invented baselines, endorsements, human-research exemption, or new ownship-fix algorithms.  
**Draft not modified.**

---

## 1. What the sample does well (steal the *shape*, not the content)

1. **First paragraph names the team, the product, and the buyer.** ACME 1.1: firm + consultants + “develop a Big Network Reporting system” + Navy topic number + named end-user office (MCSC PM Intel). A reviewer knows the offer in ~80 words.
2. **Contractor experience sits *before* the work plan.** 1.3.1 ties named people to named artifacts (TREK award, Prajna, VULCAN/DIA, DILITHIUM/NSA, Tibbetts, ISO 9001 / 8(a)). Related Work (4.1–4.3) then *reuses* those artifacts (“base the reasoner on VULCAN… Jena”).
3. **Objectives are a numbered list that the work plan can tick.** Five functional objectives; tasks 3.1–3.6 implement them in order; 3.7 is feasibility; 3.8 reporting; 3.9 continuation.
4. **Figures have captions that argue.** Fig. 1 object model; Fig. 2 architecture *and* a six-month schedule; Figs. 3–5 show what the analyst would see. Captions state the design point (“known and unknown values,” “modular architecture reduces interdependencies”).
5. **Work-plan tasks name who, where, and a customer review gate.** Ellicott City lab; SME vs PI split; “provide to Navy COTR for review before next task.”
6. **Commercialization names a first product story and (in the sample) existing customers.** 6.1 applications; 6.2 customers. We must **not** invent customers; we should copy the *clarity* of a first segment, not the claim.

What **not** to copy: ACME 1.2 is long, off-topic (MySpace teen studies), and slow to reach the Marine intel requirement. Their architecture is web services—incompatible with NP004 air-gap. Their numbering is old BAA, not Navy Open Topic 1.0–3.0. Cartoon names and unverified “winning” status are not evidence.

---

## 2. Where our draft is already stronger

- **Problem is the topic.** Three operator questions, shared-dependency scenario, INDETERMINATE vs forced diagnosis, product vs simulator. ACME spends pages on social-network literature before the requirement.
- **Evaluation honesty.** 60-case coverage (not reliability), critical-case oracles, surrogate not fleet baseline, no operator-performance %, no human research, CUI/Iron Bank questions left open. ACME promises analyst utility without a measurement protocol.
- **Runtime constraints are explicit.** Air-gapped full stack; deterministic path if the local model is absent; **&lt;100 ms** offeror gate vs **&lt;1 s** Government requirement, reported separately; keyed retrieval off the hot path (30 µs *target*, labelled unmeasured).
- **Defense Need is sourced.** OPNAVINST 9420.1C 5a(3)/5a(11), P-40 LI 2657, GAO-22-106010, NAVCEN Jun–Aug 2026, MARAD 2026-008. ACME’s “significance” is mostly opportunity language.
- **Scope discipline.** No new sensors / ownship-fix algorithms / ship control; informational COAs; ECDIS familiarity not certification; GPNTS named without endorsement.

Do not dilute these to sound more like ACME.

---

## 3. Dimension-by-dimension

### Narrative clarity

| ACME | Ours |
|---|---|
| Intro → problem → opportunity → *who we are* → approach + figure | Operator scene → hypothesis → scenario → Figure 1 file path → evaluation philosophy → constraints → *then* technical approach / combative training |

**Gap.** A reviewer meets our evaluation theory and training loop before a one-sentence “what ships in the container.” ACME’s 1.1 + 1.3.2 would put *offer + architecture* first.

**Exact improvement (1.0, after the MARAD sentence, before the shared-dependency story):**

> DeepBlue Dynamics, with [named PI] as Principal Investigator, proposes a unified APNT operator interface for DON26BX05-NP004. The Phase I product is a single air-gapped container (Iron Bank base; retrieval tools, reference data, index, compiled rules, display driver) that preserves per-source health, computes an explainable composite, and presents an informational alert and initial recommendation on a deterministic path (offeror-proposed under 100 ms; Government requirement under one second). Phase I measures that stack on synthetic ASPN/pntOS streams; it does not integrate live GPNTS or claim a fielded APNT system.

Keep the shared-dependency paragraph. Move the four-step “combative training” list from 1.0 into 1.2 B3 (it already lives there). In 1.0, leave **two sentences**: development-time rule synthesis; **no model on the shipboard alert path**.

### Technical specificity

ACME names Jena, Prefuse, GraphML, SOA/Tomcat, on-demand vs background reasoner. Ours names ASPN/pntOS, 3–8 sources at 1–10 Hz, monotonic-clock frame-presented latency, observation-conditioned INDETERMINATE, keyed retrieval, Iron Bank packaging, nemesis8 prototype.

**Gap.** 1.0 Figure 1 is a *path* (`notes/hmi-mockups/remarkable/fig_console_sketch-8.png`), not a captioned architecture. ACME’s Fig. 2 is the missing piece the layout plan already asked for.

**Exact improvement:**
- **Figure 1 (console):** caption arguing the operator sequence, not the filename. Example: “Notional ETV console: degradation banner and acknowledge; source roster (health, age); composite tiles; informational COA cards with prerequisites; evidence on drill-down. Schematic chart, not ENC. Not a certified ECDIS.”
- **Figure 2 (architecture):** ingest (3–8 synthetic streams) → normalize (source state never collapsed) → deterministic composite/triage/rules → first displayed alert+initial COA (&lt;100 ms offer / &lt;1 s Government) → async local retrieval/explanation → audit/replay. Simulator and held-out labels **outside** the operational path. Caption: “Hot path has no language model; retrieval is keyed and off the initial render.”
- Label the 30 µs keyed-lookup number as **offeror target, not measured** (already true; keep it out of 1.0 body if space is tight).

### Existing work and credibility

ACME Related Work is *named prior systems* (TREK toolkit, VULCAN social-network utility for DIA, DILITHIUM SOA prototype for NSA) plus *what will be reused*. Ours 1.3 is honest (corpus, vendored retrieval, notional console, nemesis8 Iron Bank container) but reads like a repository inventory. Placeholders remain: `[PI publications, firm product/IP…]`.

**Gap.** Credibility comes from *named software + what Phase I reuses*, not from claiming Intel-community awards we do not have.

**Exact improvement to 1.3 (keep not-fielded / not-accredited):** after the container sentence, add one reuse sentence:

> Phase I reuses that container, the local hybrid retrieval service, and the notional display driver as the starting runtime; adapters, compiled decision rules, the frozen evaluation harness, and measured latency/isolation/security evidence are the new work.

Fill or delete the PI/IP placeholder before filing. Do **not** add ACME-style customer names, ISO/8(a), or awards unless the firm supplies them. Do **not** cite lume Hit@10 or any unre-run benchmark.

### Objectives → tasks → deliverables

| Our O | Implied B tasks | ACME analogue |
|---|---|---|
| O1 Integrate | B2 adapters/fixtures | 3.2 data model |
| O2 Support decisions | B3 display + rules + traces | 3.3–3.6 rules, reasoner, UI |
| O3 Feasibility | B4 gates + B5 report | 3.7–3.8 |

Base B1–B5 and option O1–O3 already have months and deliverables. **Gaps vs ACME:** no one-line O↔B map; no named performer per task; no hours; location still `[U.S. performance location to confirm]`; no graphic schedule.

**Exact improvement:** insert after the O1–O3 list:

> O1 is demonstrated by B2; O2 by B3; O3 by B4–B5. Option tasks O1–O3 do not reopen the frozen base evaluation set except as versioned regression.

In 1.2, add “Performer: DeepBlue Dynamics ([role])” on each B/O row once hours exist. Add a six-month bar (Figure 3) matching B1–B5 / option. Do not add a COTR “approve before next task” gate the CSO does not require.

### Personnel

ACME: PI expertise mapped to visualization/reasoning; SME owns the rule taxonomy; commercialization consultant with a fielded product story. Ours: two people, strong commercial search/crawler/full-stack bios, Navy EM4 context correctly *not* sold as GPNTS expertise. **Gaps:** `[PI designation to confirm]`, hours, foreign-person, degree conferral, consultants “[confirm whether any]”, PI primary employment.

**Exact improvement:** resolve those brackets before PDF. If no consultants, file “None.” Map Kord → O2/B3/B5 (architecture, retrieval, transition writing); Clint → O1/O3/B2/B4 (ingest, runtime, gates). Do not invent a behavioral-science SME; NP004 does not need one. Do not paste ACME’s royalty/IP bullets into Volume 2 (Volume 5).

### Commercialization

ACME 6.1–6.2: applications **and** existing customers. Ours: GPNTS pathway with disclaimer, full topic Phase III list, “all commercial opportunities are prospective,” IP bracket. **Correctly refuses invented sales.**

**Gap.** No first *commercial* offer (who buys what in year one after Phase II). The ten-item list is the topic’s, but ACME leads with 2–3 segments.

**Exact improvement:** after the GPNTS disclaimer, one paragraph:

> The first dual-use segment is commercial shipping and logistics operations centers that already fuse multiple navigation feeds and must plan for GPS disruption (MARAD 2026-008). Aviation operations and critical-infrastructure monitoring are the next segments on the topic Phase III list. No commercial customer or revenue is claimed.

Keep the full list only if space remains. Fill the IP Volume 5 pointer with a real assertion or “none.”

### Figures and layout

ACME: five captioned figures, including schedule. Ours: one figure *reference* plus a 70-character wrapped manuscript. Layout plan asked for architecture **and** annotated console; only the sketch is cited. `apnt-console.html` is the better visual than the remarkable PNG if it can be typeset as a still (nominal + degraded), without claiming ECDIS certification.

**Exact improvement:** two stills from the console (nominal / degraded) as Figure 1a/1b **or** keep the sketch but write a real caption; add architecture Figure 2; add schedule Figure 3. Do not use `hmi-0*_DO-NOT-USE.png`. Filename paths must not appear in the filed PDF.

---

## 4. Concrete gaps (priority)

| Pri | Gap | Do | Do not |
|---|---|---|---|
| P0 | Brackets (PI, hours, location, consultants, IP, foreign person) | Fill or state “none” | Invent customers, awards, GPNTS selection |
| P0 | 1.0 lead is evaluation-first | Offer + container + 100 ms/1 s in the second paragraph | Drop air-gap, deterministic path, or INDETERMINATE |
| P1 | No architecture or schedule figure | Fig. 2 data path; Fig. 3 six-month bars | Web-service diagrams; DO-NOT-USE art |
| P1 | O↔B not explicit | One mapping sentence | Extra objectives that the SOW cannot test |
| P1 | Related Work is inventory, not reuse | One sentence: container + retrieval + display are the start; rules/harness/measures are new | Lume Hit@10; fielded APNT product |
| P2 | Combative-training procedure occupies 1.0 | Two sentences in 1.0; steps stay in B3 | Model on the hot path |
| P2 | Commercialization is a topic list | First dual-use segment + “no sales claimed” | ACME-style “existing customers” |
| P2 | Figure 1 is a repo path | Caption + operator sequence | Claiming certified ECDIS |

---

## 5. What we already do that ACME would fail under NP004

If we imitated the sample’s web-service interface, SME interviews as Phase I knowledge acquisition, or “existing customers,” we would violate Q&A (air-gap; no human research expected; no invented commercial evidence). Keep those refusals. The sample is a *pacing and caption* example, not a compliance template.

---

## 6. Bottom line

Our technical and evaluation spine is more NP004-correct than ACME’s. The sample still beats us on **offer-in-the-first-screen**, **captioned architecture**, **named reuse of existing software**, and **objectives that visibly drive tasks**. Close those four without adding customers, awards, live GPNTS, models on the alert path, or a percentile miss on the **&lt;100 ms** offer (Government **&lt;1 s** still reported separately).
