# Caliola Engineering, LLC

**Role for NP004:** closest funded analog on Navy GPNTS — software NAVWAR SA + alt-PNT sensor (SCAPP) into PMW/A-170. Not the ECDIS operator glass. Treat as incumbent-adjacent, not invisible.

**Sources (pulled 2026-08-27):**
- Portfolio (authoritative firm rollup): https://www.sbir.gov/portfolio/1639485 — page shows **up to 10 most recent** of 41 awards; remainder via award IDs below.
- Individual awards on sbir.gov (linked).
- Company site: https://www.caliola.com/ (verified).

---

## Firm

| | |
|---|---|
| Legal | CALIOLA ENGINEERING, LLC |
| UEI | Q9DSGGYNU8J9 |
| Address | 5465 Mark Dabling Blvd, Colorado Springs, CO 80918 (older awards also list 106 Sunbird Cliffs Lane / 1045 Elkton Dr) |
| Site | http://www.caliola.com |
| Employees | **69** (sbir.gov portfolio) |
| Certifications | **Woman-owned** (WOSB). Not HUBZone. Not SDB. |
| Founded | 2019 (VentureRadar; not re-verified from SOS) |
| First SBIR | 2020 |

**SBIR rollup (portfolio, as of pull):** 19 Phase I, 22 Phase II, **115.79%** I→II conversion (II count > I because of Direct-to-Phase-II and sequential Phase IIs). Dollars: Phase I $3,201,905 · Phase II $37,335,759 · **total $40,537,664**.

Self-description (caliola.com): WOSB; MILSATCOM, waveform design, modernized HF, **alternate PNT (A-PNT)**, automated comms/mission planning, secure networking. Claims delivery to **multiple Navy Programs of Record**. Protected MILSATCOM support at Peterson SFB, Offutt AFB, Patch Barracks.

**Contract vehicles (company site, not independently verified here):** NAVAIR SBIR Phase III BOA (any federal agency can sole-source Ph III); GSA OASIS+ TS/WOSB; GSA PES (541330/541380/541420/541715); SeaPort NxG; EWAAC.

**Named people (from award pages):** Jennifer Halford (business contact); Tom Halford (PI, waveforms/OverKey/CPC); Adam Wilander (PI, NAVWAR SA N234-P07); Peter Parker (PI, SCAPP Ph I / HF planner); Newfel Seman (PI, ATNW joint detection).

---

## PNT / GPNTS / NAVWAR cluster (the NP004 overlap)

Three threads. All **Navy**. All verified as awards, not topics.

### 1. NAVWAR SA on GPNTS — closest analog to NP004

**Title:** Leveraging GPNTS for Navigation Warfare Situational Awareness

| Phase | FY | Contract | $ | sbir.gov |
|---|---|---|---|---|
| I | 2024 | N68335-24-C-0189 | $174,963 | https://www.sbir.gov/awards/211304 |
| II | 2025 | N68335-25-C-0135 | **$1,747,782** | https://www.sbir.gov/awards/218156 |

Topic **N234-P07** · track **N234-P07-0063** · sol. 23.4 · same tracking number I→II.

**What they actually claimed (abstracts):**
- Software tool that reads **GPNTS input and output messages** and IDs GPS threats near-real-time.
- Compare GPS tracks vs alternate PNT sensors (APS): **ACNS** (Automated Celestial Navigation System) and their own **SCAPP**.
- If several APS tracks agree with each other and disagree with GPS → GPS jammed or spoofed. (Ph I wording.)
- Ph II: **does not rely on ML**. Uses **GLRT** (Generalized Likelihood Ratio Test) on tracks. In parallel, GPNTS **metadata** → confidence MGUE/GPNTS place in GPS meas.
- If spoofing **not detected by MGUE**, tool **directs GPNTS to discipline the shipboard INS with the best available APS**.
- Ph II: “increasingly sophisticated **maritime demonstrations**.”
- Ph I also mentioned Mahalanobis clustering / “tools from AI”; Ph II dropped that for GLRT. Evaluator-relevant: they won the II on a **deterministic** story.

PI: Adam Wilander.

### 2. SCAPP — alt-PNT *source* into GPNTS (PMW/A-170)

**SATCOM Antenna Pointing for Positioning.** Lines of bearing / ranging from Navy Multiband Terminal while tracking GEO (and later pLEO).

| Phase | FY | Contract | $ | sbir.gov |
|---|---|---|---|---|
| I | 2023 | N68335-23-C-0205 | $246,342 | https://www.sbir.gov/awards/205486 |
| II | 2024 | N68335-24-C-0251 | **$1,744,949** | https://www.sbir.gov/awards/211786 |

Topic **N224-131** · track **N224-131-0020**. Ph I teammate named: **Advanced Space** (cislunar PNT). Ph II title on secondary aggregators: “pLEO Positioning, Navigation, and Timing.”

**Performance they published in abstracts:**
- Live DoD terminal data: **~20 m** positioning, **stationary**, **two GEO** sats in view. Dominant error: satellite ephemeris.
- Ph I M&S: **~40 m** with OneWeb pointing vectors. OneWeb chosen because transponded / future Navy-compatible; later tranche optical crosslink for time transfer.
- Interfaces with **AN/SSN-9(V) GPNTS**. Purpose of APS: position/velocity when GPS denied; secondary use = NAVWAR compare (feeds thread 1).

Ph I PI: Peter Parker. Ph I: “Since 2020, Caliola has been working with **PMW/A-170**.”

### 3. Airborne Assured PNT Hub — GPNTS-shaped, not ship

| Phase | FY | Contract | $ | sbir.gov |
|---|---|---|---|---|
| I | 2025 | N68335-25-C-0153 | $146,410 | https://www.sbir.gov/awards/217316 |

Topic **N242-084** · track **N242-084-0148**. **No Phase II found on this pull** — do not upgrade to I→II.

Architecture: modular OA hub for Navy aircraft (P-8 / F/A-18 kinematics, not WSN-7 / ship racks). Ph I design: (i) avionics IF, (ii) non-GPS PVAT IF, (iii) **software hosting env + SDK for integrity monitoring, sensor fusion, and logging**. Abstract again: shipboard APS for **PMW/A-170** + “tools that support **integrity monitoring** of shipboard GPS and non-GPS PVAT for PMW/A-170.” That integrity-monitor claim is **in the abstract**, not a separate award ID found here.

---

## Rest of the shop (not PNT, but shows they transition)

Portfolio's 10 most-recent (2024–2025) are mostly **comms/waveforms**, not nav glass:

| Title | Topic | Phase | FY | $ | Award |
|---|---|---|---|---|---|
| Universal Short FEC Codec | AF224-0015 | II | 2025 | $1,249,152 | /awards/216094 |
| OverKey: NIAP Validated Mesh VPN | AFX255-DPCSO1 | II (D2P) | 2025 | $1,249,960 | /awards/216751 |
| Network-Enabled Weapons Settings Verification | N251-009 | I | 2025 | $146,446 | /awards/217488 |
| Data Link Layer Optimization for ATNWs (2nd Ph II) | N192-090 | II | 2025 | $1,999,275 | /awards/218164 |
| Delivering Waveform Capability… (TTNT CI/CD) | N241-007 | II | 2025 | $999,951 | /awards/218268 |
| Autonomous, Mission-Based Traffic Engineering (AssuredShaper / CaaS) | N241-056 | II | 2025 | $999,841 | /awards/218239 |
| OverKey: Rapidly Deploying DCGS Next Gen | AF233-0032 | I | 2024 | $179,942 | /awards/210386 |
| Broadband Sonobuoy Uplink | N232-095 | I | 2024 | $146,348 | /awards/211188 |

**Transition they advertise (company + award abstracts, not a Phase III record pulled here):**
- **CPC** (Cross-Packet Coding) “already transitioned to Phase III”; site: **$5M OUSD(R&E) APFIT** Phase III; TTNT upgrades to fly **F/A-18, EA-18G, E-2D in 2026**.
- OverKey: mesh VPN, IPsec/CNSA 2.0, aiming NIAP + NSA CSfC list; demos on Silvus / TrellisWare / goTenna / 5G / Starlink.
- Comms planning software “will support Fleet operations starting in 2026” (PACFLT / USFF).
- HF: 300 kbps Colorado–Tampa (2024) as “PACE without space.”

Older Navy I→II also exists (not on the 10-item teaser): N213-142 Automated HF Communications Planner I N68335-22-C-0218 $246,481 → II N68335-23-C-0696 $1,749,508 (inknowvation mirror of sbir; Ph II ID not re-fetched on sbir.gov this session — treat $ as secondary until /awards page is opened). N203-150 ATNW joint-detection Ph II N68335-23-C-0138 $1,774,454 https://www.sbir.gov/awards/206377.

---

## What this means for NP004

**Overlap (real):**
- They already sell the Navy a **software NAVWAR SA** that consumes GPNTS messages, compares GPS vs APS, scores confidence, and **commands a fallback** (INS on best APS). That is the analytic-core slice of our topic, wired to **AN/SSN-9(V)** and **PMW/A-170**.
- They also **are** an APS (SCAPP). Topic says no new sensors/filters from *us*; they are a source our ingest might see later.
- Ph II NAVWAR SA won on **no-ML / GLRT**. Matches DSIP Q&A: transparent rules OK; keep LLM off the hot path.

**Not overlap:**
- No ECDIS-grammar HMI, BAM ack, S-52/ENC glass, composite COA on the plot, procedure retrieval, Iron Bank container COP.
- PEO: they name **PMW/A-170** (PNT service). NP004 TPOC is **PMW/A 520** (NAVWAR). Complementary stack if we stay on the glass.
- They are a **comms-first** shop ($40M SBIR, TTNT Ph III, OverKey). PNT is a growing line, not the whole firm.

**Proposal use:**
- Cite Caliola as prior art in the **related work / differentiation** paragraph, not as a partner unless we actually team. Evaluator who knows 170/GPNTS will expect this name.
- Differentiation one-liner: *Caliola reasons over GPNTS messages and can retask INS; we present the navigator a DoD Navigation Display-conformant pane (source agreement, triage, COA, evidence) on an air-gapped container. We ingest; we do not replace GPNTS or SCAPP.*
- Do **not** invent a GPNTS ICD we do not have (NAVDORM / Dist B). Phase I stays on public ASPN samples; Caliola’s GPNTS-message work is Phase II transition *shape*.
- Teaming is optional: they have 170 access + APS + GLRT; we have 520 topic + ECDIS/BAM + lume corpus. Only if business wants it.
- Sole-source risk: they have a NAVAIR Ph III BOA. We do not. Frame Phase III via 520/PoR, not by matching their vehicle list.

**Honesty limits:** portfolio teaser is 10/41 awards. Integrity-monitor “tools for 170” is an abstract claim, not a found contract. Conversion >100% is D2P/multi-II, not magic. Website “multiple Navy PoR” is marketing; the **verified** Navy PNT awards are the three threads above.

---

## Open-source repos — none found (checked 2026-08-27)

**Verdict:** no Caliola-owned public source. GPNTS/SCAPP/NAVWAR SA/OverKey/TTNT are closed (SBIR + PoR + CMMC L2). Do not expect a GitHub drop we can reuse.

**Checked (negative):**
- GitHub users/orgs 404: `caliola`, `CaliolaEngineering`, `caliola-engineering`.
- GitHub repo search `caliola` in name/description/readme: 2 hits, **neither is them** (a coffee-shop app; a summer-internship list).
- Phrase search `"Caliola Engineering"` OR `caliola.com` OR `OverKey Caliola`: **0 repos**.
- `github.com/Overkey` exists but is a 2016 account with a **yuzu-android** fork — not the firm (founded 2019; OverKey® is their mesh VPN).
- GitLab explore search `caliola`: no company project (page has no matching listing).
- caliola.com / about / careers: **no GitHub/GitLab/SourceHut link**. YouTube “Caliola Engineering” has product demos only (`OverKey by Caliola in 100 seconds`).
- OverKey is described as patent-pending commercial VPN (IPsec/CNSA 2.0, NIAP/CSfC path) — the opposite of OSS.
- Tom Halford: ~50 papers, 12+ patents (about page). Academic coding-theory papers are not a company GitHub org; TrellisWare TSM/RoCCE/TTNT work is **not** Caliola source.

**Not searched exhaustively:** private GitHub Enterprise, Repo1.dso.mil (Iron Bank contributor space — would still not be public OSS), PyPI (search page challenged). If something exists it is not advertised.

**NP004 takeaway:** no public GLRT / GPNTS-message parser / SCAPP code to vendor or clone. Phase I stays on public ASPN + our own rules.
