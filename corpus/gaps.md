# Short-run gaps — 2026-08-26

Scope of this run: P0 locators A1, A2, C2, C3, F2. One URL at a time. No `crawl_batch`. Grub via `http://host.docker.internal:6792`.

## Restricted — recorded, not fetched
- **A1-GOV** Government ASPN 2023. Citizenship + contractor gate at https://www.aspn.us/access-government-aspn. Repo `git.aspn.us/aspn/aspn-icd`. Access condition: verify status then request account. Stop.

## Paid — not fetched
- **F3** ION GNSS+ 2023 “ASPN and pntOS…” (topic ref 3). Abstract: https://www.ion.org/publications/abstract.cfm?articleID=17172. Full text is ION/paywall. Record only this run.

## Failed then recovered
- **C3 PDF** Direct GET → Akamai `Access Denied` (502-byte HTML). Recovered: `download_file` with `use_browser=true`. File is `%PDF-1.7`, 2,045,376 bytes.

## Incomplete / confirm next run
- **F2 official** navysbir.com copy is self-labeled unofficial. Official: https://www.dodsbirsttr.mil/submissions/solicitation-documents/active-solicitations. Not pulled (likely login). Q&A answer 2 looks garbled on the unofficial page.
- **C2/C3 page counts** linearized `/N` (132 / 37). `pdftotext` not in this image — extract `.txt` next run.
- **ASPN SHA of working tree** zip is GitHub `main` snapshot 2026-08-26, not a tagged edition. 0 tags on the repo.
- **pntOS version** no GitHub releases; not confirmed as “2.0 SDK”. Public artifact is pntOS-C API on `main`.
- **C3 catalog via Hyperia web pane** resolved. Pane 9863d913 loaded the PDF (200, application/pdf, 2045376, `%PDF-`). Matches `corpus/C/C3_DHS_Resilient_PNT_Conformance_Framework_v2.0.pdf`.

## Display + index pass (2026-08-26 later)
Fetched: B1 S-52 6.1.1 + PresLib 4.0.3 addendum + App1; B2 S-57 suite + S-58 + S-64 locator; B3 NOAA ENC official page (locator only, no cells); B4 MSC.232(82) + Circ.1503/Rev.1; B5 MSC.302(87); B7 Circ.1575; B9 OPNAVINST 9420.2B; B12 Bowditch 2024 Vol I+II LoRes (curl; grub evicted large NGA bodies); C8 MARAD 2026-008 + NAVCEN GPS test schedule; C9 MGN 379 Amd 1.

Still open
- **B1 full PresLib 4.0(.4) Part I/II** not a separate public PDF on iho.int/uploads (have 6.1.1 + 4.0.3 addendum). Annex A:100 Ed 5.0 gated on S-100 security scheme — skip.
- **B3 ENC cells** not downloaded. Locator: https://charts.noaa.gov/InteractiveCatalog/nrnc.shtml and https://charts.noaa.gov/ENCs/ENCs.shtml. Pick strait cells later.
- **B10 NAVDORM** (COMNAVSURFPAC/LANT INST 3530.4) — no public PDF found this pass. Record existence; do not scrape CAC/DONI-restricted.
- **B6 IEC 62288 / IEC 61174** PAID.
- **A.1021(26)** alerts code not pulled this pass.
- **Bowditch full-res** Vol I 175 MB still at NGA API; LoRes copies on disk for the index.

## Not in this pass
A3–A11, remaining C (C4 Integrity Library), D*, E*, F1/F3–F6, G*.
