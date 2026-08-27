#!/usr/bin/env python3
"""Interactive retrieval-testing REPL for the navy corpus.

Wraps the vendored lume hybrid search engine (lume/) against the .lume-index
built from docs/. Search only — the lume agent loop is deliberately not wired in.

The index is a snapshot of docs/ frozen at build time. This REPL tracks index
history (tools/index_manifest.py) and flags results whose source changed since
indexing: a hit from a MODIFIED file is marked VERIFY, from a DELETED file INVALID.

Usage:  python3 search_repl.py [--db PATH]

Commands inside the REPL:
  <query>              hybrid search; hits from drifted sources are flagged
  :alpha N             hybrid weight, 0.0 lexical-only .. 1.0 semantic-only
  :graph N             entity-graph boost weight (0 disables)
  :limit N             max hits
  :scoring MODE        SKG edge weighting: relatedness | jaccard
  :spell on|off        spelling correction
  :settings            show current settings
  :index               re-run full indexing of docs/ (semantic + entity graph), then snapshot
  :verify              check docs/ against the index manifest (staleness)
  :history             show the index build history
  :help                this help
  :quit / :q           exit
"""
import argparse, re, shlex, subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent
DEFAULT_DB = ROOT / ".lume-index"
DOCS = ROOT / "docs"
sys.path.insert(0, str(ROOT / "tools"))
import index_manifest  # noqa: E402

_FILE_RE = re.compile(r"\(File:\s*(.+?),\s*Line:")

def find_lume() -> Path:
    for rel in ("lume/target/release/lume.exe", "lume/target/release/lume",
                "lume/target/debug/lume.exe", "lume/target/debug/lume"):
        p = ROOT / rel
        if p.is_file():
            return p
    sys.exit("lume binary not found — build it first: cd lume && cargo build --release")

def run(binary: Path, args: list, db: Path) -> None:
    cmd = [str(binary)] + args + ["--db", str(db)]
    try:
        subprocess.run(cmd, cwd=ROOT)
    except KeyboardInterrupt:
        print("\n[interrupted]")

def run_capture(binary: Path, args: list, db: Path) -> str:
    cmd = [str(binary)] + args + ["--db", str(db)]
    try:
        r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True,
                           encoding="utf-8", errors="replace")
        return (r.stdout or "") + (r.stderr or "")
    except KeyboardInterrupt:
        return "\n[interrupted]\n"

def annotate(out: str, verify_set: set, invalid_set: set) -> str:
    """Append a staleness flag under any result line citing a drifted source file."""
    lines = []
    for ln in out.splitlines():
        lines.append(ln)
        m = _FILE_RE.search(ln)
        if m:
            rel = m.group(1).strip().replace("\\", "/")
            if rel in invalid_set:
                lines.append("      ⚠ INVALID — source removed since index; this text no longer exists in docs/")
            elif rel in verify_set:
                lines.append("      ⚠ VERIFY — source changed since index; re-index to confirm this passage")
    return "\n".join(lines)

def stale(db: Path):
    """(verify_set, invalid_set, verify_dict) or empty sets if unavailable."""
    try:
        return index_manifest.stale_set(db, DOCS)
    except Exception as e:
        return set(), set(), {"error": str(e)}

def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--db", default=str(DEFAULT_DB), help="index directory (default .lume-index)")
    opts = ap.parse_args()
    db = Path(opts.db)
    binary = find_lume()

    s = {"alpha": 0.5, "graph": 0.4, "limit": 10, "scoring": "relatedness", "spell": True}
    print(f"lume search REPL — index: {db}  binary: {binary.relative_to(ROOT)}")
    print("type a query, :help for commands, :q to quit")
    if not db.is_dir():
        print(f"NOTE: {db} does not exist yet — run :index first")

    verify_set, invalid_set, _v = stale(db)
    if db.is_dir():
        print(index_manifest._fmt_verify(_v))

    while True:
        try:
            line = input("lume> ").strip()
        except (EOFError, KeyboardInterrupt):
            print()
            break
        if not line:
            continue
        if line.startswith(":"):
            parts = shlex.split(line)
            cmd, args = parts[0].lower(), parts[1:]
            if cmd in (":q", ":quit", ":exit"):
                break
            elif cmd == ":help":
                print(__doc__)
            elif cmd == ":settings":
                print(s)
            elif cmd == ":alpha" and args:
                s["alpha"] = float(args[0])
            elif cmd == ":graph" and args:
                s["graph"] = float(args[0])
            elif cmd == ":limit" and args:
                s["limit"] = int(args[0])
            elif cmd == ":scoring" and args and args[0] in ("relatedness", "jaccard"):
                s["scoring"] = args[0]
            elif cmd == ":spell" and args:
                s["spell"] = args[0] == "on"
            elif cmd == ":index":
                print("full indexing of docs/ (semantic vectors + entity graph) — this can take a while")
                run(binary, ["index", "-s", "-o", "docs"], db)
                rec = index_manifest.snapshot(db, DOCS)
                print(f"index history recorded: {rec['run_id']} — {rec['n_files']} files @ {rec['indexed_at']}")
                verify_set, invalid_set, _v = stale(db)
            elif cmd == ":verify":
                verify_set, invalid_set, _v = stale(db)
                print(index_manifest._fmt_verify(_v))
            elif cmd == ":history":
                hp = db / "index_history.jsonl"
                if hp.is_file():
                    print(hp.read_text(encoding="utf-8").strip() or "(empty)")
                else:
                    print("no index history yet — run :index")
            else:
                print("unknown command — :help")
            continue
        args = ["search", "-a", str(s["alpha"]), "-g", str(s["graph"]),
                "-l", str(s["limit"]), "--scoring", s["scoring"]]
        if s["spell"]:
            args.append("-c")
        args.append(line)
        if verify_set or invalid_set:
            print(annotate(run_capture(binary, args, db), verify_set, invalid_set))
        else:
            run(binary, args, db)  # no drift — stream live, no post-processing

if __name__ == "__main__":
    main()
