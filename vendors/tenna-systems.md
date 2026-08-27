# Tenna Systems Inc. (Tip & Cue)

**Role for NP004:** operator-facing GNSS RFI COP — maps, jam/spoof UI, emitter geolocation. Army I→II + USAF Direct-to-Phase-II. **Complementary theater COP.** Mild threat only if they pitch the same SaaS as shipboard glass (architecture mismatch: cloud fusion vs air-gap).

**Sources (pulled 2026-08-27):**
- Portfolio: https://www.sbir.gov/portfolio/2316431 — legal name **Tenna Systems Inc.**; 3 awards, all verified.
- Awards: https://www.sbir.gov/awards/209403 (Army Ph I), https://www.sbir.gov/awards/215396 (Army Ph II), https://www.sbir.gov/awards/216809 (USAF D2P Ph II).
- Sites: http://www.tennasys.com (portfolio); tipandcue.com redirects to tennasys.com. Public home is thin ("The Signal Source of Truth").

**Naming flag:** award pages name **Tenna Systems Inc.** (UEI GXCFXGK365K9). Product/brand in every abstract is **Tip & Cue**. Some secondary search listings show "TIP & CUE INC." for the Army Ph II — the **award page itself is Tenna Systems Inc.** Treat as one firm. Do not invent a second company.

---

## Firm

| | |
|---|---|
| Legal | Tenna Systems Inc. |
| Brand | Tip & Cue |
| UEI | GXCFXGK365K9 |
| Address | 100 Crossways Park West #403, Woodbury, NY 11797 |
| Site | http://www.tennasys.com |
| Employees | **20** (sbir.gov portfolio) |
| Certifications | Not HUBZone. Not woman-owned. Not SDB. |
| First SBIR | **2024** (new shop) |

**SBIR rollup (portfolio, as of pull):** 1 Phase I, 2 Phase II, **200%** conversion (D2P + sequential II). Dollars: Phase I $236,822 · Phase II $3,149,151 · **total $3,385,973**. Entire book is GNSS/LTE RFI SA.

**Named people (award pages):** Avner Bendheim (PI Ph I / USAF II, business contact, avner@tipandcue.com); Ronen Shatz (PI Army Ph II).

---

## GNSS RFI SA / operator UI (the NP004 overlap)

Three awards. Two branches. All **verified**.

### 1. Army — coverage maps + jam/spoof UI → emitter geolocation

Topic **A234-P010** · sol. 23.4.

| Phase | FY | Title | Contract | $ | sbir.gov |
|---|---|---|---|---|---|
| I | 2024 | Tip & Cue: GNSS and LTE Signal Mapping to Provide the Army with the Signal Source of Truth | W51701-24-C-0090 | $236,822 | https://www.sbir.gov/awards/209403 |
| II | 2025 | Project Boomerang: Novel GNSS RFI Emitter Detection and Geolocation Through Already-Deployed Receiver Data | W51701-25-C-A108 | **$1,899,180** | https://www.sbir.gov/awards/215396 |

Track Ph I: **A234-P010-1357**. Ph II track: **A2-10525** (sequential II on the same topic).

**Ph I abstract (operator-facing claims):**
- SaaS: "The Signal Source of Truth" for GNSS **and LTE** coverage gaps and interference.
- Two pieces: **detailed coverage maps** + **interference/anomaly detection**.
- **User interface** lets the operator pick frequency, AOI, timeframe; jam/spoof detection algorithms in the UI.
- Event Reports for airlines, regulators, operators.
- Evolving into a web platform for real-time fusion from more sources.

**Ph II (Boomerang) abstract:**
- Real-time detect / geolocate / track spoof and jam **sources**.
- Inputs: already-deployed GNSS receivers — ATAK, aircraft, satellites. TDOA, pseudorange differencing, crowd-sourcing. No special DF hardware.
- Army needs named: mitigate GNSS RFI, recon/targeting, 24/7 global RFI coverage.
- Claims interest from Army, Air Force, DHS, and commercial. Market figure in abstract ($7.13B GNSS anti-RFI by 2028) is **marketing**, not a DoD requirement.

### 2. USAF Direct-to-Phase-II — AFSOC C2 in INDOPACOM

| Phase | FY | Title | Contract | $ | sbir.gov |
|---|---|---|---|---|---|
| II (D2P) | 2025 | Spoofer Targeting via Disparate Ubiquitous Sensor Telemetry (STARDUST) … | FA8649-25-P-0264 | **$1,249,971** | https://www.sbir.gov/awards/216809 |

Topic **AFX255-DPCSO1** · track **F2D-16417** · sol. X25.5. **No Phase I on this topic** — that is D2P, not missing data.

**Abstract:** server-side prototype fusing battlefield / air / LEO assets to ID, detect, track, geolocate GNSS RFI emitters for **AFSOC** C2 in a contested INDOPACOM. Same product family as Boomerang, different customer (special ops C2 vs Army RFI COP).

---

## Rest of the shop

There isn't one on sbir.gov. All three awards are this product. First award FY24. Young firm, one thesis: crowd-sourced GNSS RFI SA as SaaS.

---

## What this means for NP004

**Verdict: COMPLEMENTARY (theater RFI COP). Not a shipboard-glass incumbent. Mild threat only as a narrative competitor ("we already show jam/spoof to operators").**

**Analogous (why they're in this landscape):**
- They actually ship an **operator UI** for jam vs spoof vs coverage — the HMI half we care about, which most PNT SBIRs do not.
- Decision-support flavor: AOI, frequency, time window, event reports, geolocated emitters.
- Recent, funded, I→II + a second-branch D2P. Real awards.

**Not overlap:**
- **SaaS / web / crowd-sourced offboard fusion.** NP004 is 100% air-gapped, shipboard, containerized, Iron Bank. Their architecture is disqualified as a drop-in.
- Army / USAF AFSOC, not Navy GPNTS / ECDIS / PMW/A 520.
- They geolocate the **emitter** (NAVWAR targeting). We triage **ownship PNT state** (fault vs jam vs spoof) and recommend a **nav COA** on the plot. Different question.
- No ENC/S-52, BAM, ASPN/pntOS ingest, composite confidence of ship sensors, INS-only fallback as a navigator procedure.

**Proposal use:**
- Cite as the **open-network RFI COP** analog: *Tenna/Tip & Cue maps GNSS RFI for Army/AFSOC from crowd-sourced receivers over a SaaS. We cannot use that pattern on an air-gapped ETV. Our pane is ownship integrity + COA on ECDIS, not a theater jammer COP.*
- If an evaluator knows Tip & Cue, the differentiator is **onboard vs offboard** and **ownship COA vs emitter hunt**.
- Teaming is plausible later (their COP as a reach-back feed into a connected variant). **Not** a Phase I partner for the air-gap prototype.
- Do not call them Navy. Do not call D2P a Phase I→II on AFX255 — it is D2P.

**Honesty limits:** public website is a stub. No GPNTS/ECDIS claim found on sbir.gov. "TIP & CUE INC." in some search indexes is a label mismatch; award records are Tenna Systems Inc. UI screenshots not pulled from sbir.gov (abstract describes the UI; that is the verified part).
