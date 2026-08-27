# BlueRISC, Inc.

**Role for NP004:** closest *software* competitor after Caliola on the same Navy topic (N234-P07). AI/ML NAVWAR SA module + operator UI into GPNTS / PMW/A-170. Not the ECDIS glass. **Threat on the GPNTS-resident SA widget.** Complementary if we stay on the 520 plot.

**Sources (pulled 2026-08-27):**
- Portfolio: https://www.sbir.gov/portfolio/112385
- Awards: https://www.sbir.gov/awards/211303 (Ph I), https://www.sbir.gov/awards/218153 (Ph II) — both **verified as awards**, not topics.
- Company site: https://www.bluerisc.com/ (verified; cyber/assurance shop, GPS IntelliSense not on the home page).
- Secondary (not sbir.gov): Navy STP quad chart for N68335-25-C-0158 (https://workspace.navystp.com/quad-chart-vtm/N68335-25-C-0158); company press 2024-11-26. Treat as marketing unless it matches the award page.

---

## Firm

| | |
|---|---|
| Legal | BLUERISC INC |
| UEI | LVWLKDJURJL1 |
| Address | 400 Amity St. Suite 0-1-3-4, Amherst, MA 01002 |
| Site | http://www.bluerisc.com |
| Employees | **16** (sbir.gov portfolio) |
| Certifications | Not HUBZone. Not woman-owned. Not SDB. |
| First SBIR | 2003 |

**SBIR rollup (portfolio, as of pull):** 37 Phase I, 23 Phase II, **62.16%** I→II conversion. Dollars: Phase I $5,074,532 · Phase II $24,490,530 · **total $29,565,062**.

Self-description (bluerisc.com): AI / agentic-AI system-assurance (vuln discovery, in-field protection, forensics) for defense, automotive, nuclear I&C. Claims DARPA / OSD / USAF / MDA / Navy / DHS work since 2002. **Cyber shop first; PNT is one Navy line.**

**Named people (award pages):** Michael Rodriguez (PI, N234-P07); Sylvia Moritz (business contact).

---

## PNT / GPNTS / NAVWAR (the NP004 overlap)

**One thread.** Same topic as Caliola's NAVWAR SA. Verified I→II.

### GPS IntelliSense — NAVWAR SA with AI/ML on GPNTS

**Title:** Navigation Warfare Situational Awareness with AI/ML

| Phase | FY | Contract | $ | sbir.gov |
|---|---|---|---|---|
| I | 2024 | N68335-24-C-0190 | $174,903 | https://www.sbir.gov/awards/211303 |
| II | 2025 | N68335-25-C-0158 | **$1,749,972** | https://www.sbir.gov/awards/218153 |

Topic **N234-P07** · track **N234-P07-0007** · sol. 23.4 · same tracking number I→II. Caliola's parallel awards on this topic are N234-P07-0063 (see `caliola-engineering.md`). **Two funded winners on the same SA topic.**

**What they actually claimed (award abstracts — short):**
- Hardware APNT antennas are limited for *actionable* NAVWAR SA and do not scale with evolving PNT attacks.
- Software-based **AI/ML** NAVWAR SA module, targeting **integration into Navy GPNTS**.
- Ph I and Ph II abstracts are nearly identical; Ph II is the funded prototype, not a new claim set.

**Secondary (Navy STP quad / company press — not the award page):**
- Product name: **GPS IntelliSense™**.
- Sponsor: **PMW/A 170**. Transition target: Navy GPNTS. TPOC named on the quad: mclaina.mazzone.civ@us.navy.mil.
- Software-only jam/spoof detect + attribution + characterization. Claims nanosecond walk-off and multi-position deception even under jamming.
- Quad image: operator UI flags a spoof on **satellite 20** (red) with attacker intent and location/timing effect.
- Claims validation **with actual GPNTS data** and partnership with **Raytheon/Collins PNT**. Ph I PoC on a GPNTS system (TRL 5); Ph II aiming TRL 6–7 by May 2026.
- Do **not** treat Raytheon partnership, TRL, or UI screenshot as sbir.gov-verified.

PI: Michael Rodriguez.

---

## Rest of the shop (not PNT)

Portfolio teaser (10 most-recent) is **cyber / LLM / side-channel**, not nav glass:

| Title | Topic | Phase | FY | $ | Award |
|---|---|---|---|---|---|
| LLMs for System Security Engineering Analysis | A254-006 | I | 2025 | $249,987 | /awards/215701 |
| Asymmetric LLM-aided Cyber Effects | N251-062 | I | 2025 | $139,995 | /awards/217718 |
| Novel Processor Architectures for Probabilistic Computing | A21-114 | II | 2024 | $1,099,997 | /awards/209540 |
| Nuclear I&C Cyber Risk Modeling Toolkit | C58-29u | I | 2024 | $200,000 | /awards/214172 |
| Side Channels for Heterogenous ICs | HR0011SB20224-15 | II | 2024 | $1,499,970 | /awards/209804 |
| Maritime Sensor Data System (MSDS) | HR001121S0007-16 | II | 2023 | $1,499,975 | /awards/207243 |
| Third-Party Verification of COTS Software | HR001121S0007-08 | II | 2023 | $1,479,634 | /awards/206582 |

**Takeaway:** ~$30M SBIR, cyber/assurance core. GPS IntelliSense is an adjacent Navy insertion, not the firm's identity. That is the opposite of a WECDIS house.

---

## What this means for NP004

**Verdict: THREAT on the GPNTS SA module / widget. COMPLEMENTARY to our ECDIS glass.**

**Overlap (real):**
- Same topic as Caliola (N234-P07). They already sold Navy a **software NAVWAR SA** that lives *inside* GPNTS and shows the operator a spoof/jam picture.
- They name **PMW/A-170** (secondary) and GPNTS (award + secondary). Same PEO Caliola named. NP004 TPOC is **PMW/A 520**.
- They have an **operator-facing UI** (STP quad). That is closer to "glass" than Caliola's GLRT/retask story — still a GPNTS console widget, not ECDIS/BAM.

**Not overlap:**
- Method is **AI/ML**. Caliola won the sibling II on **no-ML / GLRT**. DSIP Q&A and our ARCH-02 keep the hot path deterministic. BlueRISC is the counter-example: they won *this* topic with ML. Cite as prior art; do not copy the method onto the COA path.
- No ECDIS grammar, BAM ack, S-52/ENC, composite COA on the plot, procedure retrieval, Iron Bank COP. Air-gap container story is not in the abstract.
- They are a **cyber/LLM** shop inserting a GPNTS plugin. We are a navigation-display + decision-support bid.

**Proposal use:**
- Related-work paragraph should name **both** N234-P07 winners: *Caliola (GLRT, APS compare, INS retask) and BlueRISC (AI/ML IntelliSense widget on GPNTS). Neither is a DoD Navigation Display / ECDIS APNT decision-support pane.*
- Differentiation one-liner: *They detect and characterize GPS attack *in GPNTS*. We present source agreement, triage (fault/jam/spoof), composite confidence, and a recommended COA on an air-gapped ECDIS-style HMI for the navigator. We ingest GPNTS/ASPN; we do not replace IntelliSense or GPNTS.*
- Do not pick a fight with their ML on their turf. Our no-LLM-hot-path is a *feature* vs their win theme, not a rebuttal of their award.
- Teaming: optional only if 170 access or GPNTS data matters. They already claim Raytheon/Collins (unverified here). Risk: they could bid NP004 as "IntelliSense on the plot." Counter: air-gap, ECDIS grammar, COA, BAM, 520 — none of which their abstract covers.

**Honesty limits:** Ph II abstract is thin (same paragraph as Ph I). UI, TRL, Raytheon, SAT-20 screenshot are **Navy STP / press**, not sbir.gov. Portfolio teaser is 10/60 awards. GPS IntelliSense is not advertised on the public home page as of this pull.
