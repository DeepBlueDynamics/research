#!/usr/bin/env python3
"""Interactive retrieval-testing REPL for the navy corpus.

Wraps the vendored lume hybrid search engine (lume/) against the .lume-index
built from docs/. Search only — the lume agent loop is deliberately not wired in.

Usage:  python3 search_repl.py [--db PATH]

Commands inside the REPL:
  <query>              hybrid search with current settings
  :alpha N             hybrid weight, 0.0 lexical-only .. 1.0 semantic-only
  :graph N             entity-graph boost weight (0 disables)
  :limit N             max hits
  :scoring MODE        SKG edge weighting: relatedness | jaccard
  :spell on|off        spelling correction
  :settings            show current settings
  :index               re-run full indexing of docs/ (semantic + entity graph)
  :help                this help
  :quit / :q           exit
"""
import argparse, shlex, subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent
DEFAULT_DB = ROOT / ".lume-index"

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
            else:
                print("unknown command — :help")
            continue
        args = ["search", "-a", str(s["alpha"]), "-g", str(s["graph"]),
                "-l", str(s["limit"]), "--scoring", s["scoring"]]
        if s["spell"]:
            args.append("-c")
        args.append(line)
        run(binary, args, db)

if __name__ == "__main__":
    main()
