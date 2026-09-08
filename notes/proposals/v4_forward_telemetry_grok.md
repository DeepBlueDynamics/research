# Telemetry situation-vector and optional contrastive encoder (Grok)

**Date:** 2026-09-07  
**Author:** Grok  
**Inputs read:** `notes/proposals/submission_draft_v4.md`; `notes/proposals/v4_forward_architecture_brief.md`; `notes/proposals/v4_forward_tools_antigravity.md` (interface only); `notes/proposals/opening_pages/shared_evaluation_protocol.md`; `NP004_spec_list_and_research_agent_plan.md` A4; `docs/A/A1_ASPN-ICD_2023/README.md` and `types/type_integrity.yaml`; `docs/A/A4_SignalK_spec_1.8.2.md`; `docs/C/C4_PNT-Integrity_develop/pnt_integrity/pnt_integrity/README.md` plus `CnoCheck.hpp` / `AgcCheck.hpp`.  
**Did not modify:** `submission_draft_v4.md` or any earlier draft.  
**Status of claims:** design and inspection. Nothing here is measured.

---

## 1. Stance

Keep v4’s product: SEXTANT is an operator-awareness console, not a replacement navigator and not a new ownship-fix algorithm. Telemetry therefore exists to **preserve evidence, missingness, and shared dependency** so compiled rules can emit a discrete anomaly-state key. Distances, if used, name **diagnostic analogues**. They are not assurance, not calibrated probability, and not a spoof/jam detector.

**Required in vinfinity:** an engineered situation vector with an explicit missingness mask and dependency identifiers.

**Optional, and off the first displayed frame unless separately measured:** a contrastive encoder trained on observation-conditioned labels. Do not train it on hidden-truth diagnoses. Do not put it on the offeror <100 ms path by default.

Exact anomaly-state lookup remains the hot-path binding (v4 §1.0.5 Keyed retrieval). Analogue search is drill-down after that frame, or a gated fallback whose latency is scored under the same gate if it is allowed to write the first recommendation.

---

## 2. Evidence from this workspace

| Item | What I actually found | Kind |
|---|---|---|
| Labeled Skiff scenarios | **None.** `nuts_find` under `/workspace` for `*skiff*` and `*scenario*` returned no scenario assets. The only Skiff hits are planning sentences: spec-list A4 (“Existing Skiff transport”) and the architecture brief (“Optional contrastive encoder trained on labeled Skiff scenarios”). | Verified absence in this mount |
| Signal K local copy | `docs/A/A4_SignalK_spec_1.8.2.md` is the **1.8.2 landing page** (crawl ~4.7k characters). It does not contain GNSS quality keys (C/N0, AGC, RAIM). | Verified |
| Spec-list A4 | “document which integrity fields it lacks (C/N0, AGC, RAIM)” — a **task**, not a completed field audit against the full Signal K schema. | Planning statement |
| ASPN 2023 | Integrity is **optional on every measurement** (`type_integrity`: method enum + optional `integrity_value`). Satnav observation types exist (`measurement_satnav`, `type_satnav_obs`). Optional fields send null. | Verified in README / yaml |
| DHS PNT Integrity Library (local C4) | Built-in checks include AGC, C/N0, acquisition, AOA, range-position, position-jump, PVC, clock-jump. README states AGC **cannot discern jam from spoof**; C/N0 check looks for **uniform C/N0** as a simulator-spoof artifact; acquisition uses IF correlator peaks. CnoCheck / AgcCheck require GNSS observables / AGC values. | Verified in README and headers |
| v4 | Explicit missingness; unknown dependencies stay unknown; integrity-unavailable feeds never drive a decision; INDETERMINATE; evaluator-held truth; 60 frozen cases (20/20/20) with ≥6 recoverable per fault/jam/spoof; keyed lookup; no model on the alert path; <100 ms offeror gate. | Verified in v4 |
| Shared protocol v3 | Observation-equivalent pairs with distinct hidden truths; observable-evidence oracle; family/seed/parameter coverage including shared dependency; product must not read labels. | Verified |
| Notional console | Six named sources (GPS-A/B, INS, Alt PNT, radar fix, clock) with health/age only. No C/N0, AGC, residual, or dependency-id fields in the mockup data model (from `apnt-console.html` source lists). | Verified |

**Blocker (Codex / company):** there are no labeled Skiff scenario files in `/workspace/navy`. Contrastive training, family-separated encoder heldouts, and Skiff→ASPN transfer **cannot be claimed, scheduled as measured work, or given a sample size** until someone points at a dump (paths, label schema, license, and whether C/N0/AGC/RAIM exist on the wire).

---

## 3. What v4 already got right (do not dilute)

1. Agreement is not corroboration (v4 §1.0.2).
2. Missing fields are shown as missing, never invented (B2).
3. Hidden truth never enters the inference path (B2; protocol).
4. INDETERMINATE when jam/spoof/fault are not separable (v4 §1.0.5).
5. Composite is not a calibrated probability (v4 §1.0.5).
6. Hot path has no language model; latency gate is defined once in §1.1.

The brief’s telemetry work is **filling the vector and the oracle**, not replacing those rules with an embedding.

---

## 4. Situation vector (required)

Engineered, not stringified. Do not run the text/image embedder (brief item 1) on residuals, C/N0, or AGC. Those geometries are numeric.

**Proposed layout (design, unmeasured).** One epoch vector at the SEXTANT ingest boundary, after ASPN normalize, **before** any language model.

Pad to a declared maximum of 8 sources. Unused slots are missing, not zero-filled as if a healthy source reported zero.

Per source *i*:

| Field | Encoding | Rule |
|---|---|---|
| `source_id` | stable integer | Never hashed from a diagnosis-bearing filename |
| `family` | enum {satnav, ins, alt_pnt, radar, clock, other} | Used for family-separated agreement |
| `pos_residual_m[3]`, `vel_residual_mps[3]` | float or missing | Residual vs a **declared comparison origin** (e.g. INS/DR). That origin is not a new ownship-fix algorithm; it is a labeled reference. If the origin is missing, residuals are missing. |
| `age_s` | float or missing | Age at ingest |
| `cn0_dbhz_mean`, `cn0_dbhz_spread` | float or missing | Only if the message carried them |
| `agc_norm` | float or missing | Only if carried; band id in side channel |
| `integrity_available` | {0,1} | 0 ⇒ this source **must not** drive a decision (v4 integrity-unavailable rule) |
| `stale` | {0,1} | Predeclared timeout fired |
| `dependency_id` | int; `UNKNOWN = -1` | Shared-dependency cluster. Two GNSS on one antenna/clock share an id. Unknown stays −1, never inferred from correlation at runtime. |
| `missing_mask` | bitset | One bit per field above |

Epoch-level:

| Field | Encoding | Rule |
|---|---|---|
| `pairwise_agree[i,j]` | distance or missing | Missing if either source missing or integrity-unavailable |
| `cross_family_agree` | same, only pairs with **different** `family` | This is the corroboration channel. Same-family agreement is reported separately and must not be labeled corroboration. |
| `env_flags` | bits | e.g. interference-report present; not a diagnosis |
| `n_sources_present`, `n_integrity_available` | ints | |

**Do not:** impute C/N0 or AGC; treat missing as 0 dB-Hz; collapse source health into the composite; stringify the vector into lume.

**Do:** keep the raw ASPN messages on the bus so Figure 5 can resolve every displayed number to a field.

---

## 5. Missingness and dependency handling

v4 says the words. Vinfinity should make them machine-checkable.

1. **Missingness is a first-class coordinate.** The contrastive encoder, if trained, sees `missing_mask` as input. Otherwise “no C/N0” looks like “C/N0 = 0,” which the PNT Integrity C/N0 check would treat as an observable, not an absence (CnoCheck operates on GNSS observables that were actually supplied).
2. **Integrity-unavailable ⇒ cannot drive a decision.** Signal K (as Skiff transport) is the likely case. Until a full schema audit exists, treat Skiff GNSS position/velocity as integrity-unavailable for jam/spoof *class* decisions even if age and residual are present. They may still appear on the roster.
3. **Dependency ids are declared in the fixture, not inferred on the hot path.** Inferring “these two GNSS share a clock because they agree” is the failure mode in v4 §1.0.2. Fixtures carry `dependency_id`. If unknown, display “unknown dependency.”
4. **Stale is not missing.** A field that was present and aged out is `stale=1` with last value retained and age shown. A field that never arrived is missing. v4 B2 already requires this distinction; the vector must too.
5. **Shared-dependency cases in the suite** must include at least: (a) two satnav sources, same `dependency_id`, both healthy-looking, alt-PNT contradicts; (b) same geometry with alt-PNT stale/missing → required INDETERMINATE or bounded degraded-ops, never “spoof confirmed.”

---

## 6. Observable-evidence oracle

Reuse the shared protocol; tighten the encoder/analogue path so it cannot cheat.

For every scored case, freeze **before tuning**:

- `obs_window`: the exact ASPN (or adapter) fields SEXTANT may read.
- `hidden_truth`: evaluator-only (fault / jam / spoof / mixed / nominal / recovery). **Not an encoder label.**
- `obs_class`: observation-conditioned class in  
  `{nominal, stale, missing_integrity, shared_dep_visible, jam_indicators_present, spoof_indicators_present, ambiguous}`.
- `acceptable_reco_set` and `prohibited_claims`.
- `critical` flag.

**Oracle rules:**

- Score tool/recommendation selection against `obs_class` and `acceptable_reco_set`, never against `hidden_truth`.
- Observation-equivalent pairs (same `obs_window`, different `hidden_truth`) must not receive two different **definitive** classes. INDETERMINATE (or the same acceptable set) is the pass.
- If `jam_indicators_present` requires C/N0 or AGC or acquisition peaks, and those fields are missing, the case is `ambiguous` regardless of hidden jam.
- AGC-only, per the PNT Integrity README, cannot support a jam-versus-spoof claim. An analogue card that says “spoof” from AGC alone fails the oracle.
- Product code, indexes, and analogue library **must not** contain case names, seeds, or filenames that encode `hidden_truth`.

The existing 60-case product gate stays. Encoder/analogue metrics are **additional** and must not replace it.

---

## 7. Family-separated heldouts, OOD, ambiguous

The 20/20/20 split is a coverage budget, not an encoder train/test split. If a contrastive encoder is attempted:

**Partition (proposed, freeze in B1):**

| Split | Who may use it | Constraint |
|---|---|---|
| Combative-training set | Rule synthesis + optional encoder training | Observation-conditioned labels only |
| Encoder validation (versioned) | Threshold selection for τ | Not the frozen product held-out |
| Frozen product held-out (60) | B4 product oracle | Never used to train encoder or pick τ |
| Encoder OOD pack | Encoder metrics only | At least one **family never seen in training** (e.g. acquisition-peak spoof if training saw only C/N0-uniform spoof) |

**Family** here means generator family (fault-receiver, noise-jam, meacon, shared-clock GNSS, stale alt-PNT, recovery), not the 20/20/20 stratum.

**Minimum OOD / ambiguous contents (proposed):**

- Observation-equivalent jam/spoof pair (protocol already requires this).
- Integrity fields absent (Skiff-like Signal K): must not map to jam or spoof analogue below τ_match.
- Shared-dependency agreement without an independent family.
- Parameter interpolation the encoder did not see (e.g. jam power between two training values) — still in-family; report separately from true OOD.
- Malformed / extra source / unknown family enum.

**Leakage checks (B4):** grep the shipped index and analogue library for diagnosis strings; attempt to read the truth store from operational code; fail the evidence-fidelity gate on a hit.

---

## 8. Distance thresholds (proposed, freeze before held-out)

Let *d* be a declared distance on the **engineered** vector (cosine or Euclidean; pick one in B1 and do not change after freeze). If an encoder exists, its distance is a **second** declared metric with its own thresholds. Do not mix them.

| Symbol | Meaning | If true |
|---|---|---|
| τ_match | Analogue may be shown as “similar to case *k*” | *k* is an `obs_class` neighbour, not a hidden-truth name |
| τ_abstain | No analogue | INDETERMINATE / no class card |
| τ_match < *d* ≤ τ_abstain | Optional “weak analogue” | Banner: not a diagnosis; missing evidence named |

**Fails:**

- Any OOD or `ambiguous` case with *d* ≤ τ_match to a definitive jam or spoof analogue.
- Any observation-equivalent pair assigned two different definitive analogues.
- Any analogue card that cites a field that was missing in `obs_window`.
- Publishing a percentage “confidence” derived from *d*.

**Hot path:** default vinfinity prose should keep analogue **off** the first displayed frame (v4 already puts keyed lookup on that path). If Codex/Antigravity keep Path B inside the first frame, then Path B events are scored under the **same** §1.1 latency gate (any ≥100 ms fails). Do not invent a microsecond k-NN budget.

---

## 9. Optional contrastive encoder

**When it is worth doing:** after the engineered vector exists, if Skiff (or a synthetic ASPN generator) can emit the **same fields** the Navy Phase I path will see, with observation-conditioned labels, in enough volume to hold out whole families.

**When it is not:** no Skiff dump; labels are hidden-truth only; Signal K without C/N0/AGC used to “learn jam vs spoof”; encoder on the 100 ms path; using training-set silhouette as the B4 number.

**Training (proposed if unblocked):**

- Supervised contrastive / triplet on `obs_class`, not `hidden_truth`.
- Backbone: small MLP on the engineered vector. Not IF samples, not Qwen/Jina, not lume text embeddings.
- Positives: same `obs_class`, different seeds.
- Hard negatives: `ambiguous` vs `jam_indicators_present`; shared-dep vs independent corroboration.
- Stop if held-out OOD false-analogue rate exceeds a frozen cap (propose 0 on critical OOD; report all).

**Attribution the encoder is allowed:** “this epoch is closer to training neighbourhood *obs_class=jam_indicators_present* than to *ambiguous*, distance *d*, threshold τ_match.”  
**Attribution it is not allowed:** “spoofing detected,” “84% jam,” “matches Red Sea case.”

PNT Integrity’s **blended** assurance level (weighted −1/0/+1) is a different product. Do not import it as SEXTANT’s composite. v4’s composite is explained source-level evidence plus a triage class, not a blended OEM integrity score.

---

## 10. Measurable class separation (unmeasured until B4)

Report **per `obs_class` and per generator family**. No single accuracy.

| Metric | Denominator | Fail (proposed) |
|---|---|---|
| k-NN purity (k=5) on frozen encoder held-out | epochs in that split | Purity on `ambiguous` assigned to jam or spoof > frozen cap (propose 0 for critical) |
| Recall@k of same `obs_class` | analogue queries | Report; do not claim reliability |
| False-analogue rate on OOD pack | OOD epochs | Any τ_match hit to a definitive class fails |
| Abstention rate on observation-equivalent pairs | pair count | Pair that splits into two definitive classes fails |
| Field-honesty | analogue cards | Card cites a missing field fails |
| Latency if analogue writes first frame | all such events | §1.1 gate |

Silhouette or t-SNE on the **training** set is a diagnostic plot, not a gate.

The 60-case product oracle remains 18/20 nominal, 18/20 recoverable, zero unsupported claims on unresolved, critical-case independent fail. Encoder metrics cannot waive that.

---

## 11. Counterarguments (and what to do instead)

1. **“Contrastive encoder will separate jam from spoof.”**  
   Not if the wire lacks C/N0, AGC, or acquisition peaks. PNT Integrity’s own AGC check cannot tell jam from spoof. Skiff-via-Signal-K is likely that wire. **Instead:** mark those fields missing; `obs_class=ambiguous`; INDETERMINATE.

2. **“Nearest analogue on the hot path with 84% confidence.”**  
   Distance-to-percent is the calibrated-probability claim v4 forbids. Antigravity’s Path B example card (“Confidence 84%, Analogue Case #42, Red Sea Barrage Jamming”) is **not usable**. **Instead:** “nearest analogue: `jam_indicators_present`, d=…, τ_match=…; C/N0 spread used; AGC missing.”

3. **“SIMD k-NN is <50 µs so it fits in 1 ms.”**  
   Unmeasured. v4 already refuses unmeasured microsecond claims for keyed lookup. **Instead:** measure Path B under the §1.1 gate if it writes the first frame; otherwise keep it off that frame.

4. **“Train on Skiff, deploy on ASPN.”**  
   Different schema, different integrity optionality, different source families. Transfer is a **measured** B4 comparison, not an architecture premise. **Instead:** generate ASPN-native fixtures as the product suite; Skiff is an adapter test if/when files exist.

5. **“The encoder replaces compiled rules.”**  
   Then you lose citations, INDETERMINATE control, and the 100 ms deterministic path. **Instead:** rules emit the key; vector/encoder only retrieve analogues and missing-evidence lists.

6. **“More training cases will fix OOD.”**  
   Not if held-outs share the same generator family. **Instead:** family-separated splits, one unseen family in the OOD pack.

7. **“Stringify telemetry into lume.”**  
   Brief item 1 is for documents. Residuals in a sentence become a different embedding geometry every time the template changes. **Instead:** numeric vector; lume stays on guidance text after the alert.

---

## 12. Interface with the tools review

Agree with Antigravity on: signed allowlisted informational tools; no runtime-generated tool calls; prerequisite checks; INDETERMINATE when analogue is too far; analogue must not be ungated k-NN.

Disagree / constrain:

- Do not put a confidence percentage on analogue cards.
- Do not name analogues after operational incidents (Red Sea, etc.) in the shipped library; use `obs_class` + fixture id.
- Do not treat Path B as in-budget until measured. Default: Path B after first frame.
- Do not fix vector width at 32 or M at 200–500 as if sized. Freeze those in B1 from the actual schema.
- Tool selection accuracy (their TEST table, truncated in the copy I read) must use the **observable-evidence oracle** in §6, not hidden truth.

---

## 13. Exact proposed prose (for Codex synthesis — do not apply here)

### 13.1 Insert in §1.0.5 after “Evidence-preserving composite.”

> **Situation vector.** After ASPN normalization, SEXTANT builds a numeric situation vector: per-source residuals against a declared comparison origin, pairwise and cross-family agreement, ages, rates, optional C/N0 and AGC when the message carries them, and an explicit missingness mask and dependency identifier. Missing fields are never imputed. Integrity-unavailable sources remain on the roster and never drive a decision. Distances in this vector, if used, identify diagnostic analogues; they are not assurance and not a calibrated probability. An optional contrastive encoder, if trained, is trained only on observation-conditioned labels from development scenarios, is frozen before the product held-out set is scored, and does not sit on the first-displayed-alert path unless that path is measured under the Section 1.1 gate.

### 13.2 Replace the last two sentences of “Keyed retrieval” with:

> At runtime the core emits the anomaly-state key and the screen looks it up (design target under 30 microseconds, unmeasured). If no exact key exists, the console does not search documents and does not generate a tool call. It either displays INDETERMINATE or, after the first frame (or on a fallback path that is itself scored under the Section 1.1 gate), a labelled analogue whose distance is inside a threshold frozen before held-out evaluation. Above the abstention threshold the analogue is suppressed. Semantic search remains drill-down only.

### 13.3 Add a gate row in §1.1 (after Information access)

> | Situation-vector honesty and analogue abstention | On the frozen held-out set and a declared OOD pack: no analogue card cites a field marked missing; observation-equivalent pairs do not receive two definitive classes; OOD/ambiguous cases with distance ≤ τ_match to a jam or spoof analogue fail. Distances are reported as distances. | Any such event fails. Unmeasured until B4. |

### 13.4 B1 deliverable add

> Freeze the situation-vector schema, missingness encoding, dependency-id rules, observation-conditioned label set, train/validation/held-out/OOD partition, and τ_match / τ_abstain **before** encoder training or analogue-library edits.

### 13.5 B2 deliverable add

> Fixtures carry `dependency_id`, `missing_mask`, and `obs_class`. Hidden truth lives only in the evaluator store. Include observation-equivalent jam/spoof pairs and at least one integrity-unavailable (Skiff-like) family.

### 13.6 B3 constraint add

> Optional encoder training uses only the combative-training split and `obs_class`. The encoder is not a runtime tool-caller. Analogue lookup, if shipped, is versioned with the rule blob.

### 13.7 B4 add

> Report k-NN purity, OOD false-analogue rate, pair-abstention, and field-honesty as in the telemetry review. If analogue lookup writes the first displayed recommendation, those events are included in the Section 1.1 latency gate. Do not infer fleet reliability. Do not convert distance to percent confidence.

### 13.8 Sentence **not** to add

Any sentence that assigns a confidence percentage to an analogue, names a real-world incident as a class, claims Skiff-trained jam/spoof separation, or places a language model or document embedder on residuals.

---

## 14. Blockers for Codex

1. **No Skiff scenario assets in this workspace.** Encoder sample sizes, Skiff field lists, and transfer claims are blocked until a dump is mounted or declared out of Phase I.
2. **Local Signal K file is the intro page**, not the key catalog. A4’s “lacks C/N0, AGC, RAIM” is still an audit to finish against the full 1.8.2 schema.
3. **Page budget.** v4 is already tight (~10 pages before figures). The §13 inserts must replace, not stack, or they blow Volume 2.
4. **Company:** confirm whether Skiff data may be used post-award under the still-unresolved CUI scope; do not assume public Signal K logs are designated CUI or that they may go to a cloud trainer.

---

## 15. Completion

Review file: `notes/proposals/v4_forward_telemetry_grok.md`.  
V4 preserved. Encoder optional; engineered vector required; analogue distances are analogues; Skiff labeled data **not found** here.
