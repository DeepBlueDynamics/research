#!/usr/bin/env python3
"""Build /workspace/navy/docs: an all-text, category-organized copy of corpus/ for indexing.

- PDFs -> .md via PyMuPDF, one visible page marker per page, provenance header
- .md/.txt captures -> copied verbatim
- .zip archives -> text members extracted under <stem>/
- Files from corpus/index/ and corpus/policy/ are re-filed by their ID letter (B12 -> B/, C6 -> C/)
"""
import hashlib, os, shutil, sys, zipfile
from datetime import datetime, timezone
from pathlib import Path

import fitz  # PyMuPDF
import pymupdf4llm

ROOT = Path("/workspace/navy")
CORPUS = ROOT / "corpus"
DOCS = ROOT / "docs"
SRC_DIRS = ["A", "B", "C", "D", "E", "F", "G", "index", "policy"]

TEXT_EXT = {".md", ".txt", ".yaml", ".yml", ".json", ".toml", ".cfg", ".ini",
            ".h", ".hpp", ".c", ".cpp", ".cc", ".py", ".sh", ".cmake", ".rst",
            ".csv", ".xml", ".html", ".css", ".mk", ".in", ".proto"}
TEXT_NAMES = {"CMakeLists.txt", "LICENSE", "README", "Makefile", "Doxyfile", ".clang-format"}

def sha256(p: Path) -> str:
    h = hashlib.sha256()
    with open(p, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()

def category_of(name: str) -> str:
    return name[0]  # IDs are like A10_, B12_, C8_ — first letter is the category

def header(src: Path, extra: dict) -> str:
    lines = [f"<!-- source: {src.relative_to(ROOT)} -->",
             f"<!-- source_sha256: {sha256(src)} -->",
             f"<!-- source_bytes: {src.stat().st_size} -->"]
    lines += [f"<!-- {k}: {v} -->" for k, v in extra.items()]
    lines.append(f"<!-- generated: {datetime.now(timezone.utc).strftime('%Y-%m-%dT%H:%M:%SZ')} by tools/build_docs.py -->")
    return "\n".join(lines) + "\n\n"

report = []   # (relpath, kind, pages, chars, note)

def convert_pdf(src: Path, dst: Path):
    # markdown with real tables (pymupdf4llm); each page marker links to the
    # source PDF at that page so index hits can open the original
    rel_pdf = os.path.relpath(src, dst.parent).replace(os.sep, "/")
    chunks = pymupdf4llm.to_markdown(str(src), page_chunks=True, show_progress=False)
    parts, total_chars = [], 0
    for i, ch in enumerate(chunks, start=1):
        text = ch["text"].strip()
        total_chars += len(text)
        parts.append(f"--- [page {i}]({rel_pdf}#page={i}) ---\n\n{text}\n")
    body = "\n".join(parts)
    note = ""
    if chunks and total_chars / len(chunks) < 200:
        note = "LOW TEXT — likely scanned/image PDF, needs OCR"
    dst.write_text(header(src, {"source_pdf_link": rel_pdf,
                                "extractor": f"pymupdf4llm {pymupdf4llm.__version__} / PyMuPDF {fitz.__version__}",
                                "pages": len(chunks),
                                "extracted_chars": total_chars}) + body, encoding="utf-8")
    report.append((str(dst.relative_to(DOCS)), "pdf->md", len(chunks), total_chars, note))

def extract_zip(src: Path, dst_dir: Path):
    n_text, n_skip = 0, 0
    with zipfile.ZipFile(src) as z:
        for m in z.infolist():
            if m.is_dir():
                continue
            name = Path(m.filename)
            if name.suffix.lower() in TEXT_EXT or name.name in TEXT_NAMES or name.stem in TEXT_NAMES:
                raw = z.read(m)
                try:
                    text = raw.decode("utf-8")
                except UnicodeDecodeError:
                    n_skip += 1
                    continue
                # strip the leading "<repo>-<branch>/" GitHub prefix for flatter paths
                rel = Path(*name.parts[1:]) if len(name.parts) > 1 else name
                out = dst_dir / rel
                out.parent.mkdir(parents=True, exist_ok=True)
                out.write_text(text, encoding="utf-8")
                n_text += 1
            else:
                n_skip += 1
    (dst_dir / "_source.md").write_text(
        header(src, {"note": f"text members extracted from zip: {n_text} kept, {n_skip} non-text skipped"}),
        encoding="utf-8")
    report.append((str(dst_dir.relative_to(DOCS)) + "/", "zip-extract", n_text, n_skip, ""))

def copy_text(src: Path, dst: Path):
    shutil.copy2(src, dst)
    report.append((str(dst.relative_to(DOCS)), "copy", "", src.stat().st_size, ""))

def main():
    if DOCS.exists():
        shutil.rmtree(DOCS)
    DOCS.mkdir()
    for d in SRC_DIRS:
        sdir = CORPUS / d
        if not sdir.is_dir():
            continue
        for src in sorted(sdir.iterdir()):
            if not src.is_file():
                continue
            cat = category_of(src.name)
            out_dir = DOCS / cat
            out_dir.mkdir(exist_ok=True)
            ext = src.suffix.lower()
            if ext == ".pdf":
                convert_pdf(src, out_dir / (src.stem + ".md"))
            elif ext == ".zip":
                extract_zip(src, out_dir / src.stem)
            else:
                copy_text(src, out_dir / src.name)
            print(f"done: {src.name}", flush=True)

    lines = ["# docs/ extraction report", "",
             f"Generated {datetime.now(timezone.utc).strftime('%Y-%m-%dT%H:%M:%SZ')} from corpus/ by tools/build_docs.py.",
             "PDFs converted with PyMuPDF (page markers `--- page N ---`); zips expanded to their text members;",
             "markdown/txt captures copied verbatim (they keep their grub crawl provenance headers).",
             "Files from corpus/index/ and corpus/policy/ are re-filed under their ID letter category.",
             "", "| file | kind | pages/kept | chars/bytes | note |", "|---|---|---|---|---|"]
    for r in report:
        lines.append("| " + " | ".join(str(x) for x in r) + " |")
    (DOCS / "README.md").write_text("\n".join(lines) + "\n", encoding="utf-8")
    flagged = [r for r in report if r[4]]
    print(f"\n{len(report)} items -> docs/; {len(flagged)} flagged")
    for r in flagged:
        print(f"  FLAG {r[0]}: {r[4]}")

if __name__ == "__main__":
    main()
