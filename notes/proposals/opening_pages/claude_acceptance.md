# Claude acceptance decision on shared synthesis

## v3 confirmation (2026-09-07, final)

Read `v3_changes.md` and re-read the three changed passages in `shared_pages_1_2.md` (page 1 ¶6 exclusion sentence; page 1 ¶8 ECDIS sentence) and `shared_evaluation_protocol.md` (¶1 scope sentence). Findings:

- Page 1 ¶6 now excludes "new PNT sensors, timing sources, hardware, or ownship-fix / navigation-solution algorithms" and keeps "an explainable composite confidence and triage assessment that is not a replacement navigator" in scope. This preserves my B1 and matches the topic, which excludes navigation algorithms but asks for analytics and decision support. No regression.
- Protocol ¶1 replaces the ambiguous "source-independent navigation algorithms" with the same exclusion and adds that distinct-error-family cross-checks remain in scope only when those sources are present in the inputs. This is the conditional rule from my K3 and review §3. No regression.
- Page 1 ¶8 states the ECDIS-inspired layout is a familiarity target "not an S-57/S-52/NMEA or ECDIS-certification claim", matching the 28 August answer. No regression.
- Gates verified unchanged: "≥1 second fails" with no percentile exception; fixed constraints sentence; 60-case coverage with 18/20 strata and independent critical-case oracle; ≥6 recoverable cases per class.

**Claude decision on v3: ACCEPT, unconditional. No semantic regression found.** One non-blocking consistency nit only: the protocol's exclusion list omits "timing sources", which the page includes; harmless because the page is the filed text.

---

## v2 confirmation (2026-09-07, later)

Verified in `shared_pages_1_2.md` v2 and `shared_evaluation_protocol.md` v2 (via `v2_changes.md` and direct grep): B1 applied (page 1 ¶6, "develops no new PNT sensors, navigation or navigation-solution fusion algorithms, timing sources or hardware"); B2 applied (page 2 ¶3, air-gapped operation and secured runtime listed as fixed constraints); B3 applied (O3, "synthetic fragmented-display surrogate—a test control, not a validated fleet baseline"); N2, N3, N4, N5 adopted. N1 not adopted to preserve page space; acceptable. **Claude decision on v2: ACCEPT, unconditional.** Remaining items before filing are the ones already listed as non-blocking (MARAD 2026-008 currency at filing; DSIP amendment/Q&A recheck).

---

# Original decision on shared synthesis v1

Date: 2026-09-07. Reviewed: `shared_pages_1_2.md` (v1) and `shared_evaluation_protocol.md` (v1), read after completing `claude_review.md`. Shared files were not altered. Measured lengths of the shared candidate (bash `wc -w`, headings included): page 1 = 493 words; page 2 = 549 words including the table. Both fit the 450–550 drafting target.

## Decision

**ACCEPT, conditional on three blocking one-sentence edits (B1–B3).** Each is a correctness or mandated-content fix with exact replacement text. If all three are applied verbatim or with equivalent meaning, my acceptance is unconditional. Items N1–N7 are non-blocking and may be taken or left.

The synthesis satisfies the four cross-cutting points I set out in `claude_review.md`: strict sub-second with no percentile allowance (page 2 row 1; protocol "≥1 second fails", "if measurement uncertainty overlaps 1 second, pass is not established"); air-gapped secured-runtime gate with negative tests and no accreditation claim (page 2 rows 2–3; protocol "Secured airgap"); no guaranteed detection without observable evidence (page 1 "will not guarantee detection from indistinguishable inputs"; protocol observation-equivalent pairs and evaluator-owned truth); no invented baseline or human-research exemption (page 2 "Participant research is not included"; protocol "no participant performance study or blanket no-IRB exemption", "No surrogate is claimed to be a validated fleet baseline"). The 60-case suite is correctly framed as a coverage budget with critical-case oracle gates that fail independently of the 18/20 aggregate.

## Blocking edits (exact replacement text)

**B1. Page 1, paragraph 6, missing topic scope boundary.** The topic and the user both exclude new sensors, navigation algorithms, timing sources and hardware; page 1 currently excludes only ship-control actuation.

Replace:
> No ship controls will be actuated.

With:
> No ship controls will be actuated. Consistent with the topic, the work develops no new PNT sensors, navigation or fusion algorithms, timing sources or hardware; it integrates, assesses and presents what existing sources provide. [1]

**B2. Page 2, paragraph 3, firm-gate wording.** The sentence lists only the source envelope and sub-second as non-proposed, which reads as if air-gapped and secured operation were negotiable engineering targets. The user has made them firm; only the checklist content and the numbers are proposed.

Replace:
> All numerical gates below, except that envelope and the sub-second requirement, are proposed engineering targets.

With:
> The source envelope, the sub-second requirement, and air-gapped operation with a secured runtime are fixed constraints; the specific control checklist, case counts and other numerical gates below are proposed engineering targets.

**B3. Page 2, O3, surrogate labelling.** The protocol states that no surrogate is a validated fleet baseline; the page does not, and O3 is where a reviewer will read "comparison against a fragmented-display surrogate" as a baseline claim.

Replace:
> **O3—Establish feasibility:** Exercise the complete secured stack using a frozen scenario suite and an identical-input comparison against a fragmented-display surrogate.

With:
> **O3—Establish feasibility:** Exercise the complete secured stack using a frozen scenario suite and an identical-input comparison against a synthetic fragmented-display surrogate, which is a test control, not a validated fleet baseline.

## Non-blocking suggestions (optional, exact text supplied)

**N1. Page 1, paragraph 1, Government-sourced currency and policy hook (both verified 2026-09-07).** Page 1 has 57 words of headroom. Append after the MARAD sentence:
> U.S. Coast Guard NAVCEN closed marine GPS problem reports from June to August 2026 for Red Sea jamming and spoofing, Fujairah anchorage disruptions affecting multiple vessels, and Baltic interference, finding no constellation anomaly in any of them. [4] Navy policy requires a DoD-approved primary PNT means plus at least one GPS-independent alternate, and requires new PNT systems to indicate degradation from jamming or spoofing to the operator. [5]

Add sources:
> [4] USCG NAVCEN, GPS Problem Report Status, https://www.navcen.uscg.gov/gps-problem-report-status, accessed Sep 7, 2026. [5] OPNAVINST 9420.1C (30 Sep 2019) ¶5a(3), ¶5a(11), https://www.secnav.navy.mil/doni/Directives/09000%20General%20Ship%20Design%20and%20Support/09-400%20Command%20and%20Surveillance%20Systems%20Support/9420.1C.pdf.

Rationale: reviewers judge technical merit from the volume alone; a Government incident record and a Navy policy clause carry more weight than a commercial advisory alone. Clause text is quoted in `claude_research_notes.md` §7.

**N2. Page 2, sub-second row, boundary wording.** Replace "measure ingress through actual displayed alert **and** initial recommendation using a monotonic clock" with "measure from input receipt at the system boundary to the first displayed frame containing both the alert **and** the initial recommendation, using a monotonic clock". This lifts the protocol's own definition into the page so the boundary is unambiguous where a reviewer will read it.

**N3. Page 2, coverage sentence.** After "with fault/jam/spoof indicators, shared dependencies, missing/stale data and recovery transitions" add ", reported per anomaly class within the recoverable stratum". Twenty recoverable cases across three classes is about six per class; saying so avoids a reviewer inferring per-class rates.

**N4. Protocol, latency.** Add one 60-minute run at 8 sources × 10 Hz with event bursts to the four 30-minute corners, so tail behaviour under sustained load is observed once.

**N5. Protocol, scenario oracle.** State the per-class floor explicitly ("at least 6 recoverable cases per class at freeze") so the 20-case stratum cannot be filled by one class.

**N6. Source [2] MARAD 2026-008 expires 21 October 2026.** Re-verify it is still active at filing (23 September) and cite the successor if replaced.

**N7. Source [3] NIST SP 800-190 URL** (`https://csrc.nist.gov/pubs/sp/800/190/final`) was not fetched by me today; confirm it resolves before filing.

## Concessions relative to my own draft (recorded so the agreement record can close them)

- Expected calibration error and the risk-coverage reporting are dropped from the shared KPPs. Accepted: the shared design treats composite confidence as an ordinal label, and page 1 now says it will not be equated with a calibrated probability.
- The scripted "follow first alarm" policy on the fragmented surrogate is dropped. Accepted: the protocol is right that a weak automated policy on the surrogate would be labelled a human benefit.
- The commercial incident statistics are dropped from the shared page 1. Accepted; N1 offers the Government-sourced substitute.
- My hash-chained audit wording is superseded by the protocol's "protected integrity anchor" requirement. Accepted: a recomputable chain alone does not resist a privileged attacker.
- My per-class 35-case target is not adopted. Accepted as a coverage budget decision, provided N3/N5 keep per-class counts visible and the critical-case oracle stays independent of the aggregate.

## Acknowledged constraints

- Shared files not modified by me.
- Clint Robison's credentials are excluded from these sections and belong in Key Personnel later (`notes/resumes/clint_personnel_wording_pending.md` per the agreement record).
- No software, security or latency test has been run; all pass/fail language in the shared candidate describes proposed work.
