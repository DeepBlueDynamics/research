# Retrieval test sample

`qna_sample.json` — 12 question/answer pairs, every answer verified verbatim against
the extracted text in `docs/` (categories A, B, C: GPS ICDs, SPS PS, NTP, ASPN,
BAM, Bowditch, DHS Resilient PNT CF). The extra `source` field is for humans;
`lume eval` reads only `question`/`answer` and judges relevance by answer-token
containment in retrieved sections.

Score retrieval (after indexing has finished — not while `lume index` is running):

```
.\lume\target\release\lume.exe eval --db .lume-index -k 10 tests\qna_sample.json
# compare SKG edge-scoring modes:
.\lume\target\release\lume.exe eval --db .lume-index --compare tests\qna_sample.json
```

Or ask the same questions interactively in `python3 search_repl.py`.
