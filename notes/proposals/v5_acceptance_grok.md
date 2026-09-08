# Grok acceptance of v5, telemetry / analogue / oracle track

Date: 2026-09-07. Reviewed `notes/proposals/submission_draft_v5.md` (5,647 words excluding the HTML comment; 5,670 including it) and `notes/proposals/v5_synthesis_notes.md` against `notes/proposals/v4_forward_telemetry_grok.md`. The draft was not modified. V4 was not modified.

## Decision: ACCEPT. No blocking fixes.

Every telemetry-track item from the Grok review is present, correctly hedged as **proposed / unmeasured**, and free of the overclaims the review forbade.

### Situation vector (review §4–5, prose 13.1)

**1.0.5 “Evidence-preserving composite and situation vector”** (line 41): numeric vector after ASPN normalize; residuals against a **declared comparison reference**; pairwise agreement; ages/trends; C/N0 and AGC **only when supplied**; missing vs stale distinct; versioned slots, units, masks, dependency rules; neither agreement nor source-family difference proves independence; integrity-unavailable feeds cannot justify an assured-source or definitive fault/jam/spoof recommendation (absence/age may still explain unresolved); no text embedder on telemetry; no replacement ownship fix. Matches the required engineered vector. B2 (line 111) generates ASPN-native fixtures with explicit masks, dependencies, and observation-conditioned labels; missing fields are shown as missing, never invented.

### Analogue fallback and abstention (review §8, prose 13.2)

**1.0.5 “Bounded analogue fallback”** (line 45) plus **Figure 2** (line 55): exact binding first; analogue is a nearby **development scenario labelled as an analogue, not a diagnosis**; eligibility uses distance, usable-feature coverage, contradictory evidence, and prerequisites; thresholds chosen on validation and frozen before final evaluation; below the similarity floor or when evidence is insufficient → INDETERMINATE **without** analogue or tool dispatch; a distance threshold alone does not prove novelty detection. First frame **including fallback and abstention** is under Section 1.1; timeouts stay in the denominator. That is the allowed Path-B-on-first-frame option from review §8, not a silent waiver of the gate.

No 84% confidence, no incident-named analogue class, no unmeasured k-NN microsecond budget. Distances “explain similarity, not causal diagnosis or calibrated confidence.”

### Optional encoder (review §9)

Same paragraph: observation-conditioned **development** labels; evaluated against the **engineered-vector baseline**; off the initial path unless the deployed configuration passes the same Section 1.1 gate. B3 (line 114) evaluates optional contrastive encoding on development scenarios and freezes models/thresholds before final testing. B2 states Skiff recordings, **if supplied** with provenance and field coverage, are an additional adapter test, **not** a prerequisite or an existing labelled-dataset claim. Matches the Skiff-absence blocker: no training corpus is claimed.

### Observable-evidence oracle and family-separated held-outs (review §6–7, 13.3–13.7)

- Combative-training paragraph (line 47): training/validation/final separated by scenario family and seed; observation-equivalent cases cannot acquire distinct definitive labels from hidden truth.
- B1 (line 108): freeze vector schema, missingness/dependency rules, observable labels, and family-separated partitions; final scenario sets frozen before tuning; thresholds from validation only.
- B2: isolated evaluator truth; observation-equivalent and absent-integrity cases.
- **1.1 Situation similarity gate** (line 84): family-separated held-outs plus an unseen-family/ambiguous challenge set; report class separation, neighbour purity, false-analogue rate, abstention coverage, and feature contributions vs engineered-vector baseline. **Fails if** any critical unsupported analogue, hidden-truth leakage, missing-field citation, or definitive distinction between observation-equivalent cases. Distances are not probabilities.
- **1.1 Tool selection** (line 85): observable-evidence oracle; exact/fallback/coverage/abstention reported separately.
- The 60-case usefulness gate remains; encoder/analogue metrics do not replace it. B4 scores the added gates on **final** held-outs and keeps analogue/abstention events in the latency denominator.

### Compiled tools vs encoder (review §11.5, §12)

**1.0.5 “Compiled tools”** (line 43): anomaly-state key + direct lookup; 30 µs is a **lookup-only design target, not a measurement**; vectors select from an enumerated set; they never generate code; no model composes a tool call on the hot path. Aligns with “rules emit the key; vector/encoder only retrieve analogues.”

## Proposed vs demonstrated (do not upgrade in retelling)

| Claim in v5 | Status |
|---|---|
| Engineered situation vector, analogue fallback, optional encoder, τ / similarity floor | **Proposed** design |
| Family-separated splits, observation-conditioned labels, 60-case oracle, similarity-gate metrics | **Proposed** evaluation |
| <100 ms first frame including fallback/abstention | **Proposed** offeror gate; unmeasured |
| Under 30 µs lookup | **Design target only**; labelled unmeasured |
| Skiff labelled scenarios | **Not claimed**; adapter test if later supplied |
| Class separation, purity, false-analogue rate | **Unmeasured** until B4 |
| Document recall@5 0.90 | Outside this track; labelled a proposed target |

Nothing on this track is a demonstrated measurement.

## Page budget (unresolved)

5,647 words excluding the HTML comment. v4 was already tight for ten pages before figures. v5 is longer. **No verified PDF page-fit.** That is a filing/typesetting risk, not a telemetry-content defect. This acceptance does not assert the volume fits ten pages.

## Non-blocking suggestions (exact text, optional)

None of these is required for ACCEPT. Use only if a later cut/pass still has room.

1. **Unused slots.** After “Missing and stale are distinct.” in 1.0.5:

   > Unused source slots are missing, not zero-filled as if a healthy source reported zero.

2. **AGC-only.** After the integrity-unavailable sentence in 1.0.5:

   > AGC without discriminating C/N0, acquisition, or independent-family evidence cannot support a jam-versus-spoof recommendation.

3. **Analogue identifiers.** In the analogue paragraph, after “labelled as an analogue, not a diagnosis.”:

   > Analogue library entries use observation-conditioned class and fixture identifiers, not operational-incident names.

If page budget forbids the adds, the existing fail row (missing-field citation; observation-equivalent split; distances are not probabilities) still carries the track.
