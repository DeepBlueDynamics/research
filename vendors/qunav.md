# QuNav LLC

**Role for NP004:** Navy-funded GPS interference **direction-finding sensor** that feeds jam/spoof SA to the ship bridge **via GPNTS**. Algorithm/sensor shop with a bridge-SA sentence in the abstract. **Complementary APS/DF source.** Mild threat if their GIDI-UP widget tries to own jam-vs-spoof presentation on the bridge — still not ECDIS/COA/BAM.

**Sources (pulled 2026-08-27):**
- Portfolio: https://www.sbir.gov/portfolio/381385
- Awards (verified): https://www.sbir.gov/awards/205483 (GIDI-UP Ph I), https://www.sbir.gov/awards/211837 (GIDI-UP Ph II).
- Related, not the landscape focus: AIM-PNT Ph I https://www.sbir.gov/awards/205556 (N231-023) — **Phase I only on this pull; do not upgrade to I→II.**
- Company site: https://www.qunav.com/ (verified).

---

## Firm

| | |
|---|---|
| Legal | QUNAV LLC |
| UEI | C4ZNLZXJWNJ8 |
| Address | 2 Park Cir SE Unit B, Fort Walton Beach, FL 32548 |
| Site | https://www.qunav.com/ |
| Employees | **6** (sbir.gov portfolio) |
| Certifications | Not HUBZone. Not woman-owned. Not SDB. |
| First SBIR | 2011 |

**SBIR rollup (portfolio, as of pull):** 25 Phase I, 13 Phase II, **52%** conversion. Dollars: Phase I $3,448,732 · Phase II $13,348,467 · **total $16,797,199**.

Self-description (qunav.com): software-defined, hardware-agnostic GNSS / inertial / sensor-fusion. Products: QuGIVE (GPS-challenged vehicles), QuCore (GNSS signal processing), QuShield (multi-element anti-jam antenna), QuBlend (plug-and-play fusion), QuGate (outlier mitigation). Logos claimed: Northrop Grumman, Army, USAF, Navy, DARPA, Honeywell, u-blox, Bosch, JAVAD, Fugro, NextNav, Supernal. **Those logos are marketing; the verified Navy PNT award below is GIDI-UP.**

**Named people (award pages):** Chun Yang (PI, GIDI-UP); Andrey Soloviev (business contact, soloviev@qunav.com).

---

## PNT / NAVWAR cluster (the NP004 overlap)

### 1. GIDI-UP — Navy DF sensor + bridge SA via GPNTS  (focus)

**Topic N224-130** · track **N224-130-0013** · sol. 22.4. Verified I→II.

| Phase | FY | Title | Contract | $ | sbir.gov |
|---|---|---|---|---|---|
| I | 2023 | GPS interference direction finding sensor for GIDI-UP | N68335-23-C-0202 | $239,920 | https://www.sbir.gov/awards/205483 |
| II | 2024 | Prototyping and Demonstration of GPS Interference DOA Initiative for User Purposes (GIDI-UP) | N64267-24-C-0028 | **$1,749,738** | https://www.sbir.gov/awards/211837 |

**What they actually claimed:**
- Hardware prototype: antenna **array**, multi-channel **USRP SDR**, external clock, PC DAQ/processing, power. This is a **sensor**, not a display.
- Software: cascaded pre/post-correlation processing. Pre-correlation jam detect/suppress (nullspace projection + jam DOA). Post-correlation spoof detect/track (master-slave, known-PRN and **codeless** angular tracking).
- Shipboard multipath + array self-cal.
- Ph I: experimental data to validate algorithms. Claimed DOA **better than 1 deg** az and el (Ph II abstract, from Ph I sims + experiment).
- Ph II goal: prototype to **TRL 6**. "Upon successful testing, GIDIUP can serve as a direction-finding sensor for **surface and subsurface vessels** to provide **situational awareness of GPS jamming and spoofing threats to ship bridge and other ship systems via … GPNTS**."
- Contracting office on Ph II is **N64267** (NSWC Crane-style DoDAAC), not the N68335 ONR/NAVAIR SBIR shop used on Ph I — transition flavor, not a different topic.

### 2. AIM-PNT — Navy alt-PNT fusion (related, Ph I only)

| Phase | FY | Title | Contract | $ | sbir.gov |
|---|---|---|---|---|---|
| I | 2023 | Assured Integrated Mechanization of Positioning, Navigation and Timing (AIM-PNT) System | N68335-23-C-0515 | $139,999 | https://www.sbir.gov/awards/205556 |

Topic **N231-023** · track **N231-023-0507** (same topic TrustPoint won I→II on — LEO APNT). QuNav's AIM-PNT: INS core + LEO SOOP (SUPER SDR) + Earth-anomaly map-matching / SLAM; MOSA via **ASPN 2.2** into EGI-M common application space. **No Phase II for QuNav on N231-023 found on this pull.** Do not say they transitioned it.

### Other PNT (Army/USAF — complementary sensors, not glass)

From the portfolio teaser, not re-fetched line-by-line:

| Title | Topic | Phase | FY | $ | Award |
|---|---|---|---|---|---|
| GPS-denied Alternative Integrated Navigation (GAIN) | A22-009 | I | 2023 | $111,487 | /awards/207093 |
| Jam-Resistant AltNav SDR (JANS) | A17-119 | II | 2023 | $1,730,710 | /awards/206883 |
| Multi-constellation High-sensitivity Integrated LEO-PNT | A21C-T017 | I (STTR) | 2022 | $172,930 | /awards/198105 |
| Integrity-enabling Generic Estimation Manager (iGEM) | A19B-T002 | II (STTR) | 2021 | $1,099,097 | /awards/190310 |

iGEM is the interesting *integrity* cousin: generic fusion + outlier-aware filtering + solution-separation protection levels; Ph II names Northrop MAGNOM card / Army MAPS. Still a filter, not an HMI.

---

## Rest of the shop

QuNav is a **PNT algorithm house**. Site products are engines (fusion, anti-jam, outlier gates), not WECDIS. Small headcount (6). Transition path they advertise: Northrop partnership (iGEM abstract + homepage logo). GIDI-UP is the Navy shipboard insertion.

---

## What this means for NP004

**Verdict: COMPLEMENTARY sensor (DF + jam/spoof observables into GPNTS). Mild threat on a bridge SA *feed*, not on our glass.**

**Analogous:**
- Navy, recent, I→II, **surface + subsurface**, explicit **ship bridge SA** and **GPNTS** in the Phase II abstract. That is the same stack Caliola/BlueRISC plug into, from the RF end.
- They distinguish **jamming vs spoofing** in the processing chain (cascaded jam-then-spoof). Our triage taxonomy (fault / jam / spoof) can *consume* a GIDI-UP-like DOA as evidence, not replace it.

**Not overlap:**
- The award is an **array + SDR + DSP**. Topic N224-130 is GIDI-UP (direction of arrival), not navigator decision support.
- "SA to the ship bridge via GPNTS" is a **message into the PNT service**, not an ECDIS overlay, BAM, or COA.
- No ENC, no procedure corpus, no composite multi-source confidence UI, no air-gap container HMI.

**Proposal use:**
- Cite as the **DF-sensor prior art**: *QuNav GIDI-UP estimates jammer/spoofer DOA and hands SA to the bridge through GPNTS. We do not build a DF array. If/when that message exists, it is an ingest. Our pane is what the navigator does with it (agreement, triage, COA) on the plot.*
- ASPN 2.2 mention in AIM-PNT is useful framing (open messages) — but that award is Ph I only; do not imply a QuNav ASPN product on ships.
- Teaming: yes, later, as an APS. Not a glass competitor. They are six people with a deep DSP book; we should not try to out-DOA them.

**Honesty limits:** Homepage logos are not awards. 1° DOA is an abstract performance claim, not a test report. N64267 vs N68335 is a contracting-office change, not a new program of record. AIM-PNT remains Phase I only.
