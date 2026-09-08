# Volume 2 section assembly (coordinated by Claude, 2026-09-07 afternoon)

**Status at close of coordination (2026-09-07, 13:30):** `../submission_draft.md` is content-complete: 1.0 (v4, 100 ms) with the technical-approach subsection and Figure 1 reference, 1.1 (v4), 1.2 with training-loop deltas, 1.3, 1.4, 2.0, 3.0, Facilities/Equipment, References [1]–[7]. Remaining work is not drafting: company facts in the bracketed placeholders (2.0, Facilities, reference [5]), Clint's checklist confirmations, the three DSIP questions before 9 Sep noon ET, and typesetting in 10-point proportional type with Figure 1 (`../../hmi-mockups/remarkable/fig_console_sketch-8.png`) and a page check under ten pages. See `../final_pass_claude.md`.

Each agent writes only its own files here. Codex assembles `../submission_draft.md` from them. Page budget follows `../../NP004_volume2_layout.md`; all content, including references and any personnel material, counts toward the ten-page limit (Navy v2, p. 3).

| Navy Volume 2 heading | File | Owner | Budget | Status |
|---|---|---|---|---|
| 1.0 Description of Proposed Phase I Technical Effort | `../opening_pages/shared_pages_1_2.md` page 1 (v3, four-agent accepted) | Codex (assembler) | 2 pages | Accepted v3 |
| 1.1 Phase I Technical Objectives | `../opening_pages/shared_pages_1_2.md` page 2 (v3) | Codex (assembler) | 1 page | Accepted v3 |
| 1.2 Phase I (Base and Option) Statement of Work | `1_2_sow.md` | Codex | 3 pages | Drafted (741 words); uses the proposed <100 ms target, see latency note below |
| 1.3 Related Work | `1_3_related_work.md` | Grok | half page | Final: 209 words, tags and repo paths removed, 100 ms two-figure wording applied; labelled version kept as `1_3_related_work_labelled.md` |
| 1.4 Defense Need | `1_4_defense_need.md` | Grok | half page | Final: 292 words, clean; labelled version kept as `1_4_defense_need_labelled.md` |
| 2.0 Key Personnel | `2_0_key_personnel.md` | Claude | 1 page | Drafted (655 with table); company confirmations bracketed |
| 3.0 Commercialization/Transition Plan Summary | `3_0_commercialization.md` | Antigravity | 1 page | Revised after coordinator review (P-40 citation, MARAD date, SME wording, market list, data-rights wording); ~540 words |
| Facilities/Equipment | `facilities_equipment.md` | Antigravity | quarter page | Drafted (211); assembler treats equipment and environmental statements as placeholders |
| References | `references.md` | Claude | quarter to half page | Trimmed to the seven cited sources |

**Latency figure (user decided 2026-09-07: file the 100 ms version).** The assembled volume uses `../opening_pages/proposed_v4_pages_1_2_100ms.md` and `proposed_v4_protocol_100ms.md`. Wording rule for every section: the Government requirement is under one second; the offeror-proposed gate is under 100 ms from input receipt at the system boundary to the first displayed frame containing both the alert and the initial recommendation; any event at or above 100 ms fails the proposed gate; the under-one-second requirement is reported separately; a failed proposed gate is a reported feasibility limitation, not a waiver. The 100 ms figure is a user decision, not peer-measured; the four-agent acceptance record applies to v3 and the v4 delta is the number only.
| Compliance matrix (internal, not filed) | `compliance_matrix.md` | Claude | n/a | Drafted |

Rules in force for every section: no invented baselines, measurements, customers, revenue, endorsements, or accreditation status; every assumption labelled; the three firm constraints (air-gapped, secured runtime, strictly under one second to displayed alert and initial recommendation) unchanged; no human-research exemption implied; Clint Robison's service wording stays pending his confirmation.

Company facts still required before any section can be finalized: legal entity name, UEI/CAGE, SBC Control ID, PI designation and primary employment, base/option hours and rates for each person, Clint's title and start date, performance location, existing CUI-capable environment status, and any prior or pending support.
