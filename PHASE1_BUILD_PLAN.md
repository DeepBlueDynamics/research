# NP004 Phase I Build Plan — Unified APNT Operator Awareness & Decision Support

**Topic:** DON26BX05-NP004 (NAVWAR). **Scope:** Phase I feasibility — a low-to-medium-fidelity, air-gapped, containerized PoC on representative *simulated, unclassified* data, demonstrating the single deep use case: **a destroyer transit through a GPS-degraded / spoofed strait.** Public/unclassified throughout.

This plan synthesizes five workstream plans (each produced against the corpus at `docs/`): **Data Model & Interfaces**, **Sim & Arena**, **APNT Analytic Core**, **Retrieval / Display / HMI**, **Deployment / Eval / Compliance**. It reconciles the shared contracts they converged on, sequences the build, and lists what must still be acquired.

Companion refs: architecture **NP004-ARCH-01** (component list), **NP004-ARCH-02** (latency law).

---

## 0. Thesis — the deliverable is the glass

The topic is **mostly glass and widgets.** Its own text: *"This topic does **not** seek development of new PNT or APNT sensing technologies, **navigation algorithms**, timing sources, or hardware systems"* — it seeks *"UX, HMI design, … visualization, and decision-support."* Every graded metric is an operator/HMI metric (speed-to-decision, degradation-comprehension, transfer-of-training, cognitive workload). So the Phase I innovation, the demo's wow-factor, and our win theme are all the **operator console** — not the detection math.

This is also the differentiation against the closest funded competitor (Caliola Engineering, `vendors/caliola-engineering.md`), who already owns the analytic-core slice (GLRT NAVWAR SA on GPNTS, funded through Phase II). We do **not** compete there. We own the glass.

**Consequence — the product is a widget toolkit:** a reusable, ECDIS/S-52/1472H-conformant, day/dusk/night-themed component library, each widget bound to a PNT-state field by a **deterministic connector** (component #6). Widget catalog:

| Widget | Renders | State binding | Standards baseline |
|---|---|---|---|
| Confidence tiles | POSITION / NAV / TIMING / OVERALL state + confidence% + R95 | composite level + per-domain confidence | MIL-STD-1472H HSI |
| Source roster | per-source health / age / mode | source vector (never collapsed) | MSC.401(95) integrity indications |
| Agreement matrix | pairwise ✓/✗ cross-check | cross-family residuals | MSC.1/Circ.1575 |
| Divergence scatter | sources vs DR center | per-source position residuals | — (offeror) |
| Degradation banner | BAM alert + acknowledge + escalation | triage_class + severity | MSC.302(87) BAM §6–7.6 |
| Evidence panel | composite confidence + finding, minimal-subset + drill-down | composite + driver list | Q&A explainability |
| COA / action cards | recommended actions, accept/reject | coa_id (informational only) | Q&A Phase I aids-only |
| Procedure panel | retrieved runbook + page citation | canonical_query → lume | — (offeror + corpus) |
| Advisory overlay | interference polygon on chart | Arena advisory feed | MARAD/NAVCEN |
| Replay scrubber | anomaly-state timeline | audit trace | Q&A replay |

A visual reference implementation of this console (nominal + degraded, S-52 day/dusk/night) ships as an artifact and replaces the `DO-NOT-USE` concept images in `notes/hmi-mockups/`.

**Right-sizing the APNT server (#3): still real work, not our claimed innovation.** We still have to *write* the analytic core — it produces the state every widget renders, and the composite-confidence + disparate-source normalization are named Q&A expectations. But per the topic it is **data integration + transparent analytics**, built on the open PNT-Integrity library and transparent rules (Caliola won Phase II on deterministic, no-ML GLRT — determinism is the proven-winning posture). Frame it as competent, auditable plumbing that feeds the glass; claim **zero** algorithmic novelty. Full core design is §5-W3 below — unchanged in substance, repositioned in emphasis.

---

## 1. Component register (canonical)

| # | Component | Owner workstream | Class |
|---|---|---|---|
| 1 | Sim (ship + sensor models) | Sim & Arena | scaffolding (→ GPNTS in Ph II) |
| 2 | Arena (scenario/threat driver + labeled-eval generator) | Sim & Arena | scaffolding |
| 3 | APNT server (deterministic analytic core) | Data Model + Analytic Core | **product** |
| 4 | Agentic retrieval (lume resident service + local model) | Retrieval/Display | product |
| 5 | Display (ECDIS-conformant) | Retrieval/Display | product |
| 6 | Display apps + deterministic connectors | Retrieval/Display | product |
| 7 | Chart substrate (S-52 + ENC cells) | Retrieval/Display | product |
| 8 | Time + audit/replay store | Deployment/Eval | product |
| 9 | Eval / instrumentation harness | Deployment/Eval | Phase I deliverable |
| 10 | Container deployment (Iron Bank, air-gapped) | Deployment/Eval | wraps all |
| — | **Transport bus** (local pub/sub; the event backbone all services publish to) | Data Model (pntOS transport shape) | product, cross-cutting |

The bus was implicit in ARCH-01's "stream"; all five workstreams now depend on it explicitly, so it is called out as a first-class cross-cutting element (mirrors the pntOS Transport plugin boundary).

**Product vs scaffolding line:** everything from the transport bus rightward is the product and survives to Phase II; Sim + Arena are scaffolding, replaced by GPNTS. The sim emits ASPN/pntOS on the wire so that boundary is a plug-swap, not a rewrite.

---

## 2. Reconciled shared contracts

The five workstreams independently converged on these — freezing them is the first job, because every component builds against them.

1. **ASPN is the internal model.** Rust structs are **code-generated** from the ASPN-ICD YAML (`docs/A/A1_ASPN-ICD_2023/measurements|types|metadata`), enum-`length`-tolerant for forward-compat. Every stream validates against `A1/validation/aspn_schema.json`. SignalK is an **input adapter only** and is lossy — it cannot carry C/N0, AGC, RAIM, pseudorange variance, carrier phase, subframe/nav-data, or SV ephemeris, so SignalK-origin measurements are tagged *integrity-unavailable* and never drive triage.

2. **Project `integrity_method` code block.** ASPN's `type_integrity` is a generic `{method enum, value}` and does **not** predefine RAIM/HPL/CN0/AGC codes. The team defines and publishes a project code block (RAIM_FLAG, HPL_METERS, CN0_DBHZ, AGC, SOLUTION_STATUS, …). **Co-owned:** Sim emits it, Data-Model owns its encoding, Analytic Core consumes it, Eval interprets it. This is on the critical path.

3. **Assurance levels (from the DHS/Navy PNT-Integrity library).** `{Unavailable, Unassured(−1), Inconsistent(0), Assured(+1)}` per check (`docs/C/C4_.../AssuranceCheck.hpp`). Composite = transparent normalized weighted-sum with a positive-weighting exception and single-sided hysteresis (anti-flicker). Source-level values are **never collapsed** into the composite (hard Q&A constraint: visualize source *and* derive composite).

4. **Anomaly-state key → deterministic handoff.** Key = `(triage_class ∈ {NOMINAL,FAULT,JAM,SPOOF,INDETERMINATE}, composite_level ∈ {ASSURED,INCONSISTENT,UNASSURED}, degraded_source_set)`. A compiled static table maps each key → `{canonical_query_id, pinned_procedure_id, coa_id}`. This is a sub-millisecond lookup on the hot path; semantic/embedding search is **drill-down only**, reached after the pinned procedure is already on screen.

5. **Labeled-ground-truth contract (Arena → Eval).** Every scenario run bundle ships: true PVT track + per-epoch anomaly class {nominal, fault, jam, spoof(+coherent)} + correct COA + the scenario file. This is what scores triage decision accuracy (a named graded metric).

6. **Audit-trace schema.** Append-only, hash-chained: `condition → source data → recommendation → operator decision → outcome`, with full NIST 800-171r3 audit content and a monotonic non-GPS clock. Written by the Analytic Core over the bus; read by the replay UI and the eval harness; persisted to an external volume (outside container layers).

7. **The COA set (informational only, Phase I):** CONTINUE / CROSS-CHECK-VERIFY / SELECT-ALTERNATE-SOURCE / CONFIRM-INS-ONLY / INITIATE-DEGRADED-OPS / SERVICE-ADVISORY. The system **presents**; it never auto-routes or actuates.

---

## 3. Latency law (NP004-ARCH-02, binding)

Two classes. **Sub-second deterministic hot path:** ingest → normalize → agreement/consistency → composite confidence → triage → initial COA → *render* — no embeddings, no LLM. **Relaxed agentic drill-down:** retrieve backing procedure → synthesize rationale → assemble evidence, after the COA is on screen. The display renders a **cached COA keyed by anomaly-state** so it never blocks on retrieval or the model. Retrieval runs as a resident `lume serve` (index memory-mapped once, Shivvr embedder kept warm) — never a per-query CLI (the ~1 s cost is index-load-per-process, eliminated by staying resident).

---

## 4. The coherent-regional-bias case (the load-bearing scenario)

The real-world Hormuz signature — **both GNSS receivers agree while both are wrong** — defeats cross-*receiver* checks (they share true SV geometry / are captured together). It is caught only by cross-*family* comparison: GNSS-composite vs an error-independent source (INS dead-reckoning, eLoran, radar fix, OCXO clock holdover). The Sim generates it as a common-mode offset feeding both receivers; the Arena labels it; the Core catches it via uncertainty-normalized cross-family residuals exceeding a protection bound while all intra-receiver checks read Assured. This is the scenario a naive cross-receiver-only design provably fails — and the reason the sim carries independent sources at all.

---

## 5. Workstream summaries

**W1 — Data Model & Interfaces.** ASPN codegen crate; metadata/clock normalizer (rejects headerless streams); stream-identity + sequence-gap detector; SignalK→ASPN adapter with the integrity-coverage matrix as a proposal artifact; pntOS boundary shims (Transport = bus, Platform Integration = display/COP sink, Registry = SA surface — conform to *shape*, keep a stable internal API behind it, since the PIP header is marked UNSTABLE); the compiled anomaly-state lookup; frozen interface fixtures shared by all five.

**W2 — Sim & Arena.** Deterministic seeded truth trajectory (notional DDG-51; Defiant treated as notional variant); per-source models — GPS-A/B (SPS-PS error budget: 7.0 m 95% URE, C/N0, RAIM/HPL), INS drift, eLoran, radar fix, OCXO clock (RFC 5905 holdover, PHI≈15 ppm); Arena threat injection (barrage/sweep jam, spoof, coherent bias, AIS displacement, advisory polygons); declarative seeded scenario format; labeled-ground-truth emitter; SignalK boat emitter. LLM confined to authoring scenario variety — never in the decision path.

**W3 — APNT Analytic Core.** Two-tier analytics (intra-family plausibility + cross-family agreement); transparent weighted-level composite with hysteresis; explainable fault/jam/spoof decision tree keyed on C/N0-collapse (jam) vs strong-but-false / cross-family-divergent (spoof) vs single-source-degraded-no-RF-signature (fault); COA lookup + canonical-query map; per-epoch audit event stream. Whole flow mapped to **NIST IR 8323r1 Detect→Respond→Recover** for proposal citation. Everything deterministic and auditable.

**W4 — Retrieval / Display / HMI.** `lume serve` resident (Hit@10 91.7% baseline); canonical (keyed, deterministic) + drill-down (semantic) query paths returning procedure + citation (resolves to `corpus/…pdf#page=N`) + evidence; rationale synthesized by the local model in the relaxed class. ECDIS display: S-52 day/dusk/night palettes with redundant coding; degradation banner mapped clause-by-clause to MSC.302(87) BAM (four priorities, A/B/C categories, flashing/steady/ack, 30 s re-alarm, ≤5 min escalation); minimal-subset-first explainability (source list, agreement matrix, evidence panel, recommended actions); per-step display apps with deterministic connectors; short-term replay. A conformance annex marks each element standards-conformant vs offeror-added.

**W5 — Deployment / Eval / Compliance.** Container substrate: every image rebased onto an Iron Bank base (the hardening mechanism), internet-disconnected two-stage build, air-gapped runtime, 800-190 hardening (nonroot, read-only rootfs, dropped caps, no-SSH, external-volume state); `docker compose` topology for Phase I, K8s manifests as the Phase II artifact; **hardening-ready, not accredited**. Time+audit store (local NTP clock, hash-chained trace, replay). Eval harness (headless container) computing the graded metrics from the audit trail + Arena labels, baseline (fragmented displays) vs unified prototype, with NASA-TLX/SUS/SAGAT instruments. Compliance: CMMC L2 / NIST 800-171r3 self-assessment (emphasis on 03.03 Audit and 03.04 Config Mgmt), mapped to the CSO Volume 2 structure.

---

## 6. Integrated build sequence

**Stage 0 — Freeze the contracts (unblocks everyone).** ASPN codegen + `aspn_schema.json` validation + the project `integrity_method` code block + the anomaly-state key space + frozen golden fixtures. *(W1, with W2/W3 co-signing the integrity block.)*

**Stage 1 — Parallel foundations.** Sim/Arena emit against the frozen schema (W2); Analytic Core consumes it (W3); container/build substrate + local registry + Iron Bank base selection (W5); transport bus stood up (W1).

**Stage 2 — Product spine.** Core → audit store (W3→W8); Core state + query key → Display + resident `lume serve` (W3→W4); chart substrate rendering ENC cells (W4).

**Stage 3 — Measure & integrate.** Eval harness over Arena labels + audit trail (W5/W9); the integrated air-gapped compose demo; SME usability sessions.

**Critical-path items to front-load:** (a) freeze the ASPN contract + integrity block; (b) **download NOAA ENC cells** for the chosen strait (blocks chart rendering); (c) **acquire the category-D HF instruments** (blocks eval-instrument wording).

---

## 7. Consolidated gaps — acquire before/early in build

| Gap | Blocks | Priority |
|---|---|---|
| **Category D** — MIL-STD-1472H, NASA-TLX, SUS, SAGAT, HCD method papers (D dir is empty) | Eval instruments (W5 T8), display HSI baseline (W4) | **P0** |
| **NOAA ENC cells** for the demo strait (B3 — only the portal captured) | Chart substrate render (W4 T5) | **P0** |
| **S-52 digital presentation library / LUT (.dai) colour tables** (text only in corpus) | Conformant S-52 rendering (W4) | P1 |
| **MIL-STD-2525E** tactical symbology | Threat/emitter overlay (W4) | P1 |
| **Full SignalK `navigation.gnss` schema** (only intro page captured) | SignalK adapter field map (W1) | P1 |
| **ASPN / pntOS post-award version specifics** | Codegen version pin (W1) — post-award, design modular | Ph II |
| **DoD DevSecOps Reference Design; Kubernetes STIG** | Phase II ATO path + K8s hardening (W5 option) | P2 |
| External data — INS-grade specs, eLoran ASF, TEXBAT/Jammertest RF | Sim fidelity / Ph II validation (W2) | P2 |

---

## 8. Phase I deliverable & how it is measured

**Deliverable:** all components running under `docker compose` in an **isolated / air-gapped runtime** on Iron Bank-rebased images, driven by the Arena's **destroyer-GPS-degraded-strait** scenario library (including the coherent-bias case) on representative simulated data; the decision-trace/replay store and the eval harness operating live; the resident `lume serve` backing the retrieved-procedure panel.

**Graded metrics (measured, baseline vs unified prototype):**
- **Speed-to-decision** — anomaly onset → operator decision, from the audit clock (hot-path target < 1 s to COA render).
- **Degradation-comprehension accuracy** & **decision/fallback accuracy** — operator response vs Arena ground truth (confusion matrix per fault/jam/spoof, explicit success criterion on the coherent-bias scenario).
- **Transfer-of-training** — proportion of the interface an ET/ETSW operates correctly with no APNT-specific training (the ECDIS/S-52/BAM reuse bet; conformance annex is the evidence).
- **Cognitive workload** (NASA-TLX) & **usability** (SUS) & **SA** (SAGAT freeze-probe over replay).

Every decision on screen carries its driver/evidence list and threshold-config version — the auditability the design is built to prove.

---

## 9. Top consolidated risks

| Risk | Mitigation |
|---|---|
| Coherent bias missed with only correlated GNSS sources | Require ≥1 error-independent family in the ingest contract; else cap composite and surface "cross-family verification unavailable" |
| ASPN/pntOS post-award version differs | Codegen from YAML; boundary shims not deep coupling; pin post-award |
| Air-gapped build breaks on a hidden fetch | Two-stage build + pinned local mirror; CI gate fails on any egress |
| Latency-law violation (render waits on retrieval/LLM) | Cached-COA render; retrieval + rationale strictly async/drill-down |
| Team over-reads Phase I as "accredited" | "Hardening-ready, not ATO" framing throughout; ATO deferred to Phase II |
| LLM leaking into the decision path | Hard boundary: LLM authors scenario variety + drill-down rationale only; deterministic core owns every triage/COA decision |
| False-alarm flicker eroding operator trust | Single-sided hysteresis; positive-weighting exception; INDETERMINATE class + verify COA rather than a forced label |

---

*Full per-workstream detail (task-level breakdowns, exact corpus line citations) is retained from the five planning runs; this document is the reconciled master. Regenerate/extend by re-running the planning agents against an updated corpus.*
