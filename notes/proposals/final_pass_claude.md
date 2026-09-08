# Final consistency pass on submission_draft.md (Claude, 2026-09-07, after v4 assembly)

Checked: `notes/proposals/submission_draft.md` at 12:30 (3,731 words, 581 lines, references [1]–[7]).

## Result

Content passes. No rejected claims remain (no invented baselines, no 100 percent detection, no ECDIS-conformance or accreditation claim, no participant study or IRB language, no unsourced market numbers). Latency wording is consistent in every section: Government requirement under one second, offeror-proposed gate under 100 ms to the first displayed frame with both alert and initial recommendation, any event at or above 100 ms fails the proposed gate, failure is a reported limitation not a waiver. All seven references are cited and every citation resolves. Headings match the Navy Open Topic template order.

## Blocking: page length

The draft is hard-wrapped ASCII at about 70 characters per line, 581 lines including blank lines. Single-spaced Courier New with one-inch margins fits roughly 51 lines per page at 11 point and 56 at 10 point, so the current file is about 11.4 pages at 11 point and about 10.4 at 10 point. Both exceed the ten-page limit, which causes rejection without evaluation (Navy v2 p. 3).

Two ways out, user decision:

1. **Typeset in a 10-point proportional font** (Times New Roman or Arial) with the same one-inch margins. 3,731 words of prose with a small table runs about 7.5 to 8 pages, leaving room for the two figures the layout plan recommends. This is the normal Volume 2 format and is what the page budget in `NP004_volume2_layout.md` assumed.
2. **Keep Courier** and cut about 110 lines (roughly 20 percent), which means dropping substantive content from 1.2 or 3.0.

Recommendation: option 1. Fixed-width text is not required by the instructions; the only font rule is a 10-point minimum.

## Non-blocking fixes for the assembler (line numbers from the 12:30 file)

1. B4 has broken wraps from an edit: lines 254–255 ("proposed <100 ms" alone on a line), 260–263 ("spoofing" and "repeated" alone), 270–271 ("against a synthetic" alone). Re-wrap the paragraph.
2. B4 states the load tests twice: "Include source/rate corner loads, mixed rates, bursts, and a 60-minute maximum-load soak" and then "Run four 30-minute source/rate corners, a 30-minute intermediate/mixed-rate sweep, and at least 1,000 scored event transitions." Merge into one sentence.
3. Heading style is mixed: 1.0, 1.1, 1.2, 2.0 are upper case with rules; 1.3, 1.4, 3.0 are title case. Normalize to the template's form ("1.3 Related Work" etc.) throughout, and use one separator convention or none.
4. Double blank lines at 189–190, 465–466, 577–578.
5. 1.0 paragraph 7: "the repository's retrieval and interface foundations" is internal jargon. Suggest "the firm's existing retrieval and interface software".
6. 1.3: delete "Unusable concept images will not appear here." It tells a reviewer nothing.
7. Reference [5] carries a bracketed drafting note. Before filing, replace with the official Navy FY2025 OPN justification-book citation and URL.
8. Facilities/Equipment is entirely placeholders. It must be filled with real facts before certification; reviewers will read brackets as an incomplete proposal.

## Company items still open (unchanged)

PI designation and primary employment; Clint Robison's title, start date, hours; Kord Campbell's hours; foreign-person answers; degree wording; performance location and equipment; CUI environment status; prior/pending support; background IP for Volume 5; disclosure legend decision. Clint's service wording stays out of 2.0 until he confirms the checklist. DSIP questions on CUI scope, evaluation activities, and Iron Bank close 9 Sep 2026 noon ET.
