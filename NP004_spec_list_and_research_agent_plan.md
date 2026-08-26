# DON26BX05-NP004 — Specs to index and research-agent collection plan

Purpose: build the document corpus behind (1) the proposal, (2) ECDIS-faithful HMI design, (3) sensor/analytics models in the sim, (4) the onboard "procedure retrieval" demo, (5) compliance statements. Everything here is public and unclassified by design; the agent must not go looking for anything marked CUI/FOUO/ITAR/Distribution B–F.

Priority key: P0 = need before proposal (9/23), P1 = need for Phase I build, P2 = nice to have.
Access key: FREE (download), PAID (record purchase link/price, do not fetch copies), RESTRICTED (post-award only; record existence, do not pursue).

---

## A. PNT data and interface standards

| # | Document | Why it matters | Access | Pri |
|---|----------|----------------|--------|-----|
| A1 | ASPN data standard, current release (ASPN 2023 / 3.x) + ASPN-C reference implementation — aspn.us | The message families your ingest layer maps to; note that from July 2026 the ISTO PNT Standards Consortium maintains it | FREE | P0 |
| A2 | pntOS 2.0 SDK, docs, plugin model — pntos.com | Government-owned open plugin architecture; implements ASPN 2023; defines what a "pntOS sink" looks like | FREE (registration likely) | P0 |
| A3 | GPNTS public materials: NAVWAR/PEO C4I fact sheets, RDT&E/OPN budget exhibits mentioning GPNTS, press releases | Public description of the integration target; ICDs are post-award only | FREE (public) / RESTRICTED (ICDs) | P0 |
| A4 | Signal K specification v1 (signalk.org) | Existing Skiff transport; document which integrity fields it lacks (C/N0, AGC, RAIM) | FREE | P1 |
| A5 | IEC 61162-1/-2 (NMEA 0183 equivalents), IEC 61162-450 (Ethernet), IEC 61162-460 (cyber) | Bridge data bus conventions an ECDIS-N-adjacent app must speak | PAID | P1 |
| A6 | NMEA 0183 v4.11, NMEA 2000 | Same, industry versions | PAID | P2 |
| A7 | IS-GPS-200, IS-GPS-705, IS-GPS-800 (current revisions, gps.gov) | Receiver observables, integrity fields, message structure for the GNSS model | FREE | P1 |
| A8 | GPS Standard Positioning Service Performance Standard, 5th ed. (2020) | Nominal accuracy/availability numbers for the "nominal" state | FREE | P1 |
| A9 | Enhanced Loran (eLoran) Definition Document v1.0 (ILA, 2007); USCG Loran-C signal spec | Representative alternate-PNT source model | FREE | P1 |
| A10 | IEEE 1588-2019 (PTP); RFC 5905 (NTP); ITU-T G.8272 (PRTC) | Timing distribution and holdover vocabulary for the clock model | PAID / FREE / FREE | P2 |
| A11 | RTCM 10403.x (RTCM 3) | Only if DGNSS corrections enter the sim | PAID | P2 |

## B. Navigation display, symbology, and alerting (transfer of training)

| # | Document | Why it matters | Access | Pri |
|---|----------|----------------|--------|-----|
| B1 | IHO S-52 (current ed.) + Presentation Library 4.0.x | ECDIS symbology, day/night palettes, display rules — the "Navy ECDIS conventions" baseline | FREE | P0 |
| B2 | IHO S-57 ed. 3.1 + supplements; IHO S-101 (current ed.); S-64 ECDIS test data; S-58 validation checks | ENC data model Meridian already reads; test cells for the demo | FREE | P0 |
| B3 | NOAA ENC cells for the demo strait (NOAA ENC Direct / chart catalog) + NOAA ENC Distribution terms | Real, free chart data for the destroyer-transit scenario | FREE | P0 |
| B4 | IMO Res. MSC.232(82) ECDIS performance standards; IEC 61174 ed. 4 | What an ECDIS must show and how | FREE / PAID | P0 |
| B5 | IMO Res. MSC.302(87) Bridge Alert Management; IMO Res. A.1021(26) Code on Alerts and Indicators; IEC 62923-1/-2 | Alarm/Warning/Caution categories, acknowledge behavior, aggregation — style the degradation banner to this | FREE / FREE / PAID | P0 |
| B6 | IEC 62288 (presentation of navigation-related information on shipborne displays) | Cross-equipment display conventions | PAID | P1 |
| B7 | IMO MSC.1/Circ.1575 Guidelines for shipborne PNT data processing (2015) | The maritime multi-source PNT integrity concept in one document; cite in the proposal | FREE | P0 |
| B8 | IMO Res. MSC.401(95) (as amended by MSC.432(98)) multi-system shipborne radionavigation receivers | Integrity/status outputs a modern receiver must provide | FREE | P1 |
| B9 | Navy ECDIS-N public references: OPNAVINST 9420.2 series (ECDIS-N certification policy), NAVSEA ECDIS-N/VMS public fact sheets, Navy Voyage Management System descriptions | Whatever is public about the Navy flavor of ECDIS | FREE (verify what exists) | P0 |
| B10 | Surface Ship Navigation Department Organization and Regulations Manual (NAVDORM), COMNAVSURFPAC/COMNAVSURFLANT INST 3530.4 series (current) | Defines the navigation team, watch procedures, fix intervals, ETV/QM duties — your ETV workflow source and the backbone of the procedure-retrieval demo corpus | FREE (verify current rev and releasability) | P0 |
| B11 | OPNAVINST 3120.32D Standard Organization and Regulations of the U.S. Navy | Watch organization context | FREE | P2 |
| B12 | NGA Pub. 9, The American Practical Navigator (Bowditch), 2019 | Radar/visual fixes, DR, error theory, fix geometry — sources for the radar-fix and DR models, and demo-corpus chapters | FREE | P0 |
| B13 | NGA/NOAA Chart No. 1 (chart symbols) | Symbol cross-check for chart rendering | FREE | P2 |
| B14 | MIL-STD-2525E joint military symbology | Only for tactical overlays (interference polygon, reported emitters) | FREE | P2 |

## C. Resilient PNT policy, frameworks, and tools

| # | Document | Why it matters | Access | Pri |
|---|----------|----------------|--------|-----|
| C1 | Executive Order 13905, Responsible Use of PNT Services (2020) | Policy anchor for "resilient PNT" language | FREE | P1 |
| C2 | NIST IR 8323 Rev 1, Foundational PNT Profile (2023) | Detect/respond/recover vocabulary for PNT disruption; maps cleanly to your alert → evidence → recommendation flow | FREE | P0 |
| C3 | DHS Resilient PNT Conformance Framework v2.0 (2022) | Defines resilience levels and expected receiver behaviors under jam/spoof | FREE | P0 |
| C4 | DHS S&T PNT Integrity Library (GitHub, open source) + GPS Receiver Whitelist Development Guide; check for the companion "Epsilon" algorithm suite | Reference spoof-detection checks (position/velocity/clock consistency, ICD compliance) you can cite or adapt | FREE | P0 |
| C5 | IEEE P1952 Resilient PNT User Equipment standard (check publication status) | Emerging UE resilience standard | PAID if published | P2 |
| C6 | DoDI 4650.08 PNT and Navigation Warfare (NAVWAR) | DoD policy framing; correct use of the term NAVWAR | FREE | P1 |
| C7 | Federal Radionavigation Plan (current edition) | National PNT architecture, complementary PNT direction | FREE | P2 |
| C8 | USCG NAVCEN GPS interference reporting pages and advisories; MARAD Maritime Advisories on GNSS interference (current year) | Real-world "reported interference" feed format; source for the demo's interference-report polygon | FREE | P1 |
| C9 | UK MCA MGN 379 and similar flag-state guidance on GNSS vulnerability; Nautical Institute / RNT Foundation guidance on navigating with suspect GNSS | Representative unclassified "suspect GNSS" procedures for the onboard document store | FREE | P1 |

## D. Human factors and evaluation

| # | Document | Why it matters | Access | Pri |
|---|----------|----------------|--------|-----|
| D1 | MIL-STD-1472H Human Engineering | Display, alarm, and control design criteria evaluators expect you to cite | FREE | P0 |
| D2 | MIL-STD-46855A Human Systems Integration requirements | HCD process language for the Phase I plan | FREE | P1 |
| D3 | IMO MSC.1/Circ.1512 Guideline on software QA and human-centred design for e-navigation (2015) | Maritime HCD guideline; directly on point | FREE | P0 |
| D4 | ISO 9241-210:2019 human-centred design | Process standard | PAID | P2 |
| D5 | NASA-TLX, SUS, SAGAT/SART method papers (Hart & Staveland; Brooke; Endsley) | The workload, usability, and SA instruments behind your metrics section | FREE | P0 |

## E. Deployment, security, compliance

| # | Document | Why it matters | Access | Pri |
|---|----------|----------------|--------|-----|
| E1 | Platform One docs; Iron Bank onboarding and hardening guides (p1.dso.mil, repo1.dso.mil); DoD Container Hardening Guide; DoD Enterprise DevSecOps Reference Design | The containerization target the Q&A named | FREE | P0 |
| E2 | DISA Container Platform SRG; Kubernetes STIG | Hardening expectations for the isolated runtime | FREE | P1 |
| E3 | NIST SP 800-190 Application Container Security Guide | Container threat model | FREE | P1 |
| E4 | NIST SP 800-171 Rev 3 and 800-171A Rev 3; CMMC Program rule (32 CFR Part 170) and Level 2 Assessment Guide; DFARS 252.204-7012/-7019/-7020/-7021 | CMMC Level 2 (Self) statement and post-award CUI handling | FREE | P0 |
| E5 | DoDI 8510.01 Risk Management Framework | Transition/ATO vocabulary for the Phase II path | FREE | P2 |

## F. SBIR and proposal compliance

| # | Document | Why it matters | Access | Pri |
|---|----------|----------------|--------|-----|
| F1 | DoD SBIR 26.5 BAA (DoD-level instructions) and Navy 26.5 CSO Open Topic instructions PDF | Volume structure, page limits, cover sheet, cost volume | FREE | P0 |
| F2 | Topic page DON26BX05-NP004 and the full DSIP Topic Q&A (re-pull weekly until 9/9) | Requirements as clarified; version each pull | FREE | P0 |
| F3 | The three references cited on the topic page (pull from the page; ref 3's working link is ion.org paperID=17172) | Evaluators wrote the topic from these | FREE (abstracts) / PAID (ION full text) | P0 |
| F4 | SBA SBIR/STTR Policy Directive (current) | Eligibility, 2/3 work rule for Phase I, consultant treatment | FREE | P0 |
| F5 | DSIP Phase I submission tutorials and templates; SAM.gov and SBIR.gov registration guidance | Mechanics | FREE | P0 |
| F6 | Navy SBIR/STTR Transition Program (STP) overview | Phase II/III path language | FREE | P2 |

## G. Technical references for models and analytics

| # | Document | Why it matters | Access | Pri |
|---|----------|----------------|--------|-----|
| G1 | Psiaki & Humphreys, "GNSS Spoofing and Detection," Proc. IEEE 2016; UT RNL and Stanford GPS Lab spoof-detection papers | Detection-method literature to cite for the agreement-matrix and baseline-collapse checks | FREE (many) | P1 |
| G2 | TEXBAT spoofing dataset (UT Austin); Jammertest (Norway) public reports | Validation data and realistic jam/spoof signatures for the injector | FREE | P1 |
| G3 | Groves, Principles of GNSS, Inertial, and Multisensor Integrated Navigation Systems; Kaplan & Hegarty, Understanding GPS/GNSS | INS error models, GNSS observables, RAIM | PAID (books) | P1 |
| G4 | NIST/USNO time and frequency references on oscillator holdover (OCXO/Rb/CSAC) | Clock model parameters | FREE | P2 |
| G5 | DDG-51 public specifications (Navy Fact File); public reporting on the Trump-class/Defiant | Destroyer parameter set for the demo; notional-hull caveats | FREE | P2 |

---

## Research-agent plan

### Mission
Produce a verified, licensed, versioned corpus manifest for the items above, download what is free, record access paths for what is paid, and flag what is restricted. Output feeds the Nemesis 8 index and the proposal bibliography.

### Rules (hard)
1. Public and unclassified only. Skip and log anything marked CUI, FOUO, ITAR/EAR, Distribution B–F, or requiring a DoD CAC/DTIC-restricted login. Do not attempt to obtain GPNTS ICDs, M-code ICDs, or WSN-series INS specifications.
2. Respect licenses. For PAID standards (IEC, ISO, IEEE, NMEA, RTCM, ION full text, books) record the official purchase URL, price, and edition; do not fetch mirrored or pirated copies.
3. Authoritative sources only: issuing body sites (iho.int, imo.org, nist.gov, dhs.gov, gps.gov, esd.whs.mil, quicksearch.dla.mil, secnav.navy.mil/doni, dodsbirsttr.mil, p1.dso.mil, aspn.us, pntos.com). Aggregators only as pointers.
4. Obey robots.txt and site terms. No credential-based scraping.
5. Record provenance for every file: URL, retrieval timestamp, SHA-256, page count, edition/date as printed on the document.
6. One level of citation discovery only: candidates found inside a collected document's references may be added if they fit categories A–G; do not recurse further.

### Procedure
1. Seed: load the tables above as the initial queue (IDs A1–G5).
2. Locate: for each item, find the issuing body's current edition. Search the document number and title; confirm the edition is not superseded (check the issuing body's catalog page, not a third-party listing).
3. Acquire: FREE → download PDF/HTML; PAID → record purchase link, price, edition; RESTRICTED → record existence and the access condition (e.g., "provided post-award per Q&A").
4. Extract: convert to text (pdftotext or equivalent), keep page boundaries, store alongside the original.
5. Tag: apply the metadata schema below, including use_for tags.
6. Discover (bounded): scan each collected document's references for additional in-scope items; add to queue with source_of_lead = parent ID.
7. QA: dedupe by hash and by document number; verify editions against issuing catalogs; confirm no restricted markings in the first and last pages of every file.
8. Report: manifest + gap list + a one-page summary of what changed since the last run (this runs again weekly through 9/9 for F2).

### Metadata schema (one record per document)
```
id, title, issuing_body, doc_number, edition, doc_date, category (A–G), priority (P0–P2),
license (FREE|PAID|RESTRICTED), url, purchase_url, price, retrieved_at, sha256, pages,
use_for [proposal|hmi|alerts|analytics|sim|compliance|procedure_demo], demo_corpus (Y/N),
supersedes, superseded_by, source_of_lead, notes
```

### Demo corpus subset (the "onboard document store" for procedure retrieval)
Mark demo_corpus = Y for: NAVDORM (navigation watch and fix-interval sections), Bowditch chapters on DR, radar and visual fixes, and error theory; IMO MSC.1/Circ.1575; NIST IR 8323 Rev 1 respond/recover sections; the current USCG/MARAD GNSS interference advisories; flag-state suspect-GNSS guidance (C9). From these, DeepBlue writes its own representative "Operations with Suspect GNSS" checklist for the demo, labeled as representative and non-Navy.

### Search hints for the hard ones
- B9: "ECDIS-N certification" OPNAVINST; "Voyage Management System" NAVSEA; expect little; record what exists and stop.
- B10: "NAVDORM" 3530.4; check the DONI/SURFPAC public instruction library; capture the current letter revision.
- A3: NAVWAR "GPNTS" fact sheet; "PMW/A 170" GPS navigation; FY26/FY27 RDT&E justification books (search "GPNTS" within the Navy exhibits).
- C4: DHS S&T PNT Integrity Library GitHub; also "GPS Receiver Whitelist Development Guide"; check for the Epsilon algorithm suite under the same program.
- F3: the topic page lists three references; verify each link, and use ion.org paperID=17172 for the ASPN/pntOS paper.

### Deliverables
1. `manifest.csv` and `manifest.json` per the schema.
2. `/corpus/<category>/<id>_<short_title>_<edition>.pdf` plus `.txt` extraction.
3. `gaps.md`: every PAID item with price and purchase link; every RESTRICTED item with the access condition; every item where the current edition could not be confirmed.
4. `changes.md`: diff against the prior manifest (new, updated, superseded).

### Paste-ready agent prompt
```
You are collecting a public, unclassified document corpus for a Navy SBIR Phase I proposal on assured-PNT operator awareness (topic DON26BX05-NP004). Use the attached seed list (categories A–G). For each item: find the issuing body's current edition; if free, download it and record URL, retrieval time, SHA-256, edition, and page count; if paid, record the official purchase link, price, and edition and do not fetch copies; if restricted (CUI/FOUO/ITAR/Distribution B–F/CAC-only), record its existence and access condition and stop. Never scrape behind logins or ignore robots.txt. Add newly discovered in-scope references from collected documents one level deep only. Tag each record with the metadata schema and use_for tags, and mark demo_corpus=Y for the procedure-retrieval subset. Output manifest.csv, manifest.json, gaps.md, and changes.md. Re-pull the DSIP topic Q&A on every run and diff it.
```
