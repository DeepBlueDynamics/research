#!/usr/bin/env python3
"""Index-history + staleness tracking for the lume docs index.

An index is a snapshot of docs/ frozen at build time. When docs/ later changes,
retrieval can return text that no longer matches the source. This tool records
what was indexed and, later, flags which files drifted so results from them can
be marked "verify" (source changed) or "invalid" (source removed).

Two artifacts live inside the index dir (default .lume-index):
  docs_manifest.json   — current-state map {relpath: {sha256, bytes, mtime}} at last index
  index_history.jsonl  — append-only trail: one line per index run (the history)

CLI:
  python3 index_manifest.py snapshot [--db D] [--docs docs]   # record after `lume index`
  python3 index_manifest.py verify   [--db D] [--docs docs]   # diff docs/ vs manifest
  python3 index_manifest.py history  [--db D]                 # print the index-run trail
"""
import argparse, hashlib, json, sys
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

def _now(): return datetime.now(timezone.utc).strftime("%Y-%m-%dT%H:%M:%SZ")

def _sha256(p: Path) -> str:
    h = hashlib.sha256()
    with open(p, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()

def scan_docs(docs_dir: Path) -> dict:
    """Hash every file under docs/. Keys are ROOT-relative, forward-slashed."""
    files = {}
    for p in sorted(docs_dir.rglob("*")):
        if p.is_file():
            rel = p.relative_to(ROOT).as_posix()
            st = p.stat()
            files[rel] = {"sha256": _sha256(p), "bytes": st.st_size,
                          "mtime": datetime.fromtimestamp(st.st_mtime, timezone.utc).strftime("%Y-%m-%dT%H:%M:%SZ")}
    return files

def manifest_fingerprint(files: dict) -> str:
    blob = "".join(f"{k}:{v['sha256']}\n" for k, v in sorted(files.items()))
    return hashlib.sha256(blob.encode()).hexdigest()

def snapshot(db: Path, docs_dir: Path) -> dict:
    files = scan_docs(docs_dir)
    fp = manifest_fingerprint(files)
    total = sum(v["bytes"] for v in files.values())
    rec = {"indexed_at": _now(), "run_id": "idx-" + fp[:12],
           "db": db.name, "docs_dir": docs_dir.relative_to(ROOT).as_posix(),
           "n_files": len(files), "total_bytes": total, "manifest_sha256": fp}
    db.mkdir(parents=True, exist_ok=True)
    (db / "docs_manifest.json").write_text(json.dumps({**rec, "files": files}, indent=2), encoding="utf-8")
    with open(db / "index_history.jsonl", "a", encoding="utf-8") as f:
        f.write(json.dumps(rec) + "\n")
    return rec

def load_manifest(db: Path):
    p = db / "docs_manifest.json"
    if not p.is_file():
        return None
    return json.loads(p.read_text(encoding="utf-8"))

def verify(db: Path, docs_dir: Path) -> dict:
    """Compare current docs/ to the recorded manifest."""
    man = load_manifest(db)
    now = scan_docs(docs_dir)
    if man is None:
        return {"has_manifest": False, "modified": [], "deleted": [],
                "added": sorted(now.keys()), "unchanged": 0, "drift": True,
                "message": "no docs_manifest.json — index provenance not recorded (run snapshot)"}
    old = man["files"]
    modified = sorted(k for k in now if k in old and now[k]["sha256"] != old[k]["sha256"])
    deleted  = sorted(k for k in old if k not in now)   # indexed but source gone → invalid
    added    = sorted(k for k in now if k not in old)   # present but never indexed
    unchanged = sum(1 for k in now if k in old and now[k]["sha256"] == old[k]["sha256"])
    return {"has_manifest": True, "indexed_at": man["indexed_at"], "run_id": man["run_id"],
            "modified": modified, "deleted": deleted, "added": added,
            "unchanged": unchanged, "drift": bool(modified or deleted or added)}

def stale_set(db: Path, docs_dir: Path):
    """Return (verify_set, invalid_set) of ROOT-relative posix paths for the REPL."""
    v = verify(db, docs_dir)
    return set(v.get("modified", [])), set(v.get("deleted", [])), v

def _fmt_verify(v: dict) -> str:
    if not v.get("has_manifest"):
        return "⚠ " + v["message"]
    if not v["drift"]:
        return f"✓ index current — {v['unchanged']} files unchanged since {v['indexed_at']} ({v['run_id']})"
    out = [f"⚠ index STALE vs docs/ — built {v['indexed_at']} ({v['run_id']})"]
    if v["modified"]: out.append(f"  MODIFIED (results need VERIFY): {len(v['modified'])}")
    for k in v["modified"][:20]: out.append(f"    ~ {k}")
    if v["deleted"]:  out.append(f"  DELETED (indexed text now INVALID): {len(v['deleted'])}")
    for k in v["deleted"][:20]: out.append(f"    - {k}")
    if v["added"]:    out.append(f"  ADDED (not yet indexed — re-run :index): {len(v['added'])}")
    for k in v["added"][:20]: out.append(f"    + {k}")
    return "\n".join(out)

def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("cmd", choices=["snapshot", "verify", "history"])
    ap.add_argument("--db", default=str(ROOT / ".lume-index"))
    ap.add_argument("--docs", default=str(ROOT / "docs"))
    a = ap.parse_args()
    db, docs = Path(a.db), Path(a.docs)
    if a.cmd == "snapshot":
        r = snapshot(db, docs)
        print(f"snapshot: {r['n_files']} files, {r['total_bytes']} bytes, {r['run_id']} @ {r['indexed_at']}")
    elif a.cmd == "verify":
        v = verify(db, docs)
        print(_fmt_verify(v))
        sys.exit(1 if v["drift"] else 0)
    elif a.cmd == "history":
        hp = db / "index_history.jsonl"
        if not hp.is_file():
            print("no index_history.jsonl yet"); return
        for ln in hp.read_text(encoding="utf-8").splitlines():
            r = json.loads(ln)
            print(f"{r['indexed_at']}  {r['run_id']}  {r['n_files']} files  {r['total_bytes']} B")

if __name__ == "__main__":
    main()
