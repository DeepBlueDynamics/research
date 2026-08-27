#!/usr/bin/env python3
"""Local doc browser for the navy corpus — browse docs/ and click to read.

A zero-dependency (stdlib only) HTTP server: a collapsible tree of docs/ on the
left, click a file to render it (markdown, code, or text) on the right. Per-page
markers in the extracted docs link back to the source PDF at that page.

Usage:  python3 tools/docs_browser.py [--port 7070] [--host 0.0.0.0]
Then open http://localhost:7070/  (bind is 0.0.0.0 so it works from a container).
"""
import argparse, html, re
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from urllib.parse import urlparse, parse_qs, quote

ROOT = Path(__file__).resolve().parent.parent
DOCS = ROOT / "docs"
SERVE_ROOTS = (ROOT / "docs", ROOT / "corpus")  # only these are servable

def esc(t): return html.escape(t, quote=False)

# ---------- path safety ----------
def resolve(rel: str):
    try:
        p = (ROOT / rel).resolve()
    except Exception:
        return None
    if not any(str(p).startswith(str(r.resolve())) for r in SERVE_ROOTS):
        return None
    return p if p.is_file() else None

# ---------- tree ----------
def build_tree(base: Path):
    root = {}
    for p in sorted(base.rglob("*")):
        if p.is_file():
            parts = p.relative_to(base).parts
            node = root
            for d in parts[:-1]:
                node = node.setdefault(d, {})
            node.setdefault("__files__", []).append((parts[-1], p.relative_to(ROOT).as_posix()))
    return root

def render_tree(node, top=False):
    out = []
    for k in sorted(k for k in node if k != "__files__"):
        op = " open" if top else ""
        out.append(f"<details{op}><summary>{esc(k)}</summary><div class='indent'>")
        out.append(render_tree(node[k]))
        out.append("</div></details>")
    for fname, rel in node.get("__files__", []):
        out.append(f"<a class='f' href='/view?path={quote(rel)}' target='doc'>{esc(fname)}</a>")
    return "".join(out)

# ---------- markdown -> html (pragmatic, for our extracted docs) ----------
INLINE_TAGS = ("sup", "sub", "u", "mark", "b", "i", "em", "strong", "code")

def md_link(href: str) -> str:
    href = href.strip()
    if href.startswith(("http://", "https://", "mailto:")):
        return href
    m = re.search(r"((?:corpus|docs)/.*)$", href)
    if m:
        path, frag = m.group(1), ""
        if "#" in path:
            path, f = path.split("#", 1); frag = "#" + f
        return f"/raw?path={quote(path)}{frag}"
    return href

def inline(t: str) -> str:
    t = html.escape(t, quote=False)
    for tag in INLINE_TAGS:
        t = t.replace(f"&lt;{tag}&gt;", f"<{tag}>").replace(f"&lt;/{tag}&gt;", f"</{tag}>")
    t = t.replace("&lt;br&gt;", "<br>").replace("&lt;br/&gt;", "<br>")
    t = re.sub(r"\*\*(.+?)\*\*", r"<strong>\1</strong>", t)
    t = re.sub(r"(?<!\*)\*(?!\*)([^*]+?)\*(?!\*)", r"<em>\1</em>", t)
    t = re.sub(r"`([^`]+)`", r"<code>\1</code>", t)
    t = re.sub(r"\[([^\]]+)\]\(([^)]+)\)", lambda m: f"<a href='{md_link(m.group(2))}'>{m.group(1)}</a>", t)
    return t

PAGE_RE = re.compile(r"^---\s*\[page\s*(\d+)\]\((.+?)\)\s*---\s*$")

def convert_md(text: str) -> str:
    # split provenance header comments off the top
    prov = []
    lines = text.split("\n")
    while lines and lines[0].strip().startswith("<!--") and lines[0].strip().endswith("-->"):
        prov.append(lines.pop(0).strip()[4:-3].strip())
    body, i, n = [], 0, len(lines)
    while i < n:
        ln = lines[i]
        # fenced code
        if ln.startswith("```"):
            j = i + 1; buf = []
            while j < n and not lines[j].startswith("```"):
                buf.append(lines[j]); j += 1
            body.append("<pre class='code'>" + esc("\n".join(buf)) + "</pre>")
            i = j + 1; continue
        # page marker
        pm = PAGE_RE.match(ln.strip())
        if pm:
            body.append(f"<div class='pagemark'><a href='{md_link(pm.group(2))}'>page {pm.group(1)} ↗</a></div>")
            i += 1; continue
        # table
        if ln.lstrip().startswith("|") and i + 1 < n and re.match(r"^\s*\|?[\s:|-]+\|?\s*$", lines[i+1]):
            rows = []
            while i < n and lines[i].lstrip().startswith("|"):
                rows.append(lines[i]); i += 1
            body.append(render_table(rows)); continue
        # heading
        h = re.match(r"^(#{1,6})\s+(.*)$", ln)
        if h:
            lvl = len(h.group(1)); body.append(f"<h{lvl}>{inline(h.group(2))}</h{lvl}>"); i += 1; continue
        # blockquote
        if ln.startswith(">"):
            buf = []
            while i < n and lines[i].startswith(">"):
                buf.append(lines[i][1:].lstrip()); i += 1
            body.append("<blockquote>" + inline(" ".join(buf)) + "</blockquote>"); continue
        # hr
        if re.match(r"^---+$", ln.strip()):
            body.append("<hr>"); i += 1; continue
        # list
        if re.match(r"^\s*[-*]\s+", ln) or re.match(r"^\s*\d+\.\s+", ln):
            buf = []
            while i < n and (re.match(r"^\s*[-*]\s+", lines[i]) or re.match(r"^\s*\d+\.\s+", lines[i])):
                buf.append(re.sub(r"^\s*(?:[-*]|\d+\.)\s+", "", lines[i])); i += 1
            body.append("<ul>" + "".join(f"<li>{inline(x)}</li>" for x in buf) + "</ul>"); continue
        # blank / paragraph
        if not ln.strip():
            i += 1; continue
        para = [ln]
        while i + 1 < n and lines[i+1].strip() and not lines[i+1].lstrip().startswith(("|", "#", ">", "```", "- ", "* ")) and not PAGE_RE.match(lines[i+1].strip()):
            i += 1; para.append(lines[i])
        body.append("<p>" + inline(" ".join(para)) + "</p>"); i += 1
    prov_html = ""
    if prov:
        prov_html = "<div class='prov'>" + " · ".join(esc(p) for p in prov) + "</div>"
    return prov_html + "\n".join(body)

def render_table(rows):
    def cells(r): return [c.strip() for c in r.strip().strip("|").split("|")]
    head = cells(rows[0]); out = ["<div class='tw'><table>"]
    out.append("<thead><tr>" + "".join(f"<th>{inline(c)}</th>" for c in head) + "</tr></thead><tbody>")
    for r in rows[2:]:
        out.append("<tr>" + "".join(f"<td>{inline(c)}</td>" for c in cells(r)) + "</tr>")
    out.append("</tbody></table></div>"); return "".join(out)

def render_code(text, name):
    return f"<pre class='code'>{esc(text)}</pre>"

# ---------- pages ----------
def shell():
    tree = render_tree(build_tree(DOCS), top=True)
    return SHELL.replace("__TREE__", tree)

def view(rel: str) -> str:
    p = resolve(rel)
    if p is None:
        return "<p class='err'>Not found or not permitted.</p>"
    raw = p.read_text(encoding="utf-8", errors="replace")
    body = convert_md(raw) if p.suffix.lower() in (".md", ".markdown") else render_code(raw, p.name)
    return DOCPAGE.replace("__TITLE__", esc(p.name)).replace("__BODY__", body).replace("__REL__", esc(rel))

# ---------- server ----------
class H(BaseHTTPRequestHandler):
    def _send(self, body, ctype="text/html; charset=utf-8", code=200):
        if isinstance(body, str): body = body.encode("utf-8")
        self.send_response(code); self.send_header("Content-Type", ctype)
        self.send_header("Content-Length", str(len(body))); self.end_headers()
        self.wfile.write(body)
    def do_GET(self):
        u = urlparse(self.path); q = parse_qs(u.query)
        if u.path == "/":
            self._send(shell())
        elif u.path == "/view":
            self._send(view(q.get("path", [""])[0]))
        elif u.path == "/raw":
            p = resolve(q.get("path", [""])[0])
            if p is None: self._send("not found", "text/plain", 404); return
            ct = "application/pdf" if p.suffix.lower() == ".pdf" else "text/plain; charset=utf-8"
            self._send(p.read_bytes(), ct)
        else:
            self._send("not found", "text/plain", 404)
    def log_message(self, *a): pass  # quiet

SHELL = """<!doctype html><html lang=en><head><meta charset=utf-8>
<title>Navy Corpus — Doc Browser</title><style>
:root{--bg:#070f17;--panel:#0d1a26;--ink:#c9d6de;--strong:#eaf1f5;--muted:#6f8593;--hair:#1a2c3a;--accent:#5bb0cb}
*{box-sizing:border-box}html,body{margin:0;height:100%}
body{display:flex;background:var(--bg);color:var(--ink);font:14px/1.5 'IBM Plex Sans',system-ui,sans-serif}
nav{width:320px;flex:none;overflow:auto;border-right:1px solid var(--hair);padding:12px;background:var(--panel)}
nav h1{font:600 12px/1 'Saira Condensed',system-ui;letter-spacing:.12em;text-transform:uppercase;color:var(--muted);margin:4px 0 12px}
details{margin:1px 0}summary{cursor:pointer;color:var(--strong);font-weight:600;padding:2px 0;list-style:none}
summary::before{content:'▸ ';color:var(--accent)}details[open]>summary::before{content:'▾ '}
.indent{padding-left:12px;border-left:1px solid var(--hair);margin-left:5px}
a.f{display:block;color:var(--ink);text-decoration:none;padding:2px 4px;border-radius:3px;font-size:12.5px;word-break:break-all}
a.f:hover{background:#102434;color:var(--accent)}
iframe{flex:1;border:0;background:#0a1622}
</style></head><body>
<nav><h1>docs/ — navy corpus</h1>__TREE__</nav>
<iframe name=doc src=/view?path=docs/README.md></iframe>
</body></html>"""

DOCPAGE = """<!doctype html><html lang=en><head><meta charset=utf-8><title>__TITLE__</title><style>
:root{--bg:#0a1622;--panel:#0d1a26;--ink:#cdd9e1;--strong:#eaf1f5;--muted:#6f8593;--hair:#1c2f3d;--accent:#5bb0cb}
*{box-sizing:border-box}body{margin:0;background:var(--bg);color:var(--ink);
font:15px/1.65 'IBM Plex Sans',system-ui,sans-serif;padding:28px 40px;max-width:900px}
.prov{font:11px/1.5 'IBM Plex Mono',ui-monospace,monospace;color:var(--muted);background:var(--panel);
border:1px solid var(--hair);border-radius:5px;padding:8px 10px;margin-bottom:20px;word-break:break-all}
h1,h2,h3,h4,h5,h6{color:var(--strong);line-height:1.25;margin:1.4em 0 .5em;text-wrap:balance}
h1{font-size:26px;border-bottom:1px solid var(--hair);padding-bottom:.3em}h2{font-size:21px}h3{font-size:17px}
a{color:var(--accent)}code{font-family:'IBM Plex Mono',ui-monospace,monospace;background:#102434;padding:1px 5px;border-radius:3px;font-size:.9em}
pre.code{background:#0d1a26;border:1px solid var(--hair);border-radius:6px;padding:14px;overflow:auto;font:13px/1.5 'IBM Plex Mono',ui-monospace,monospace;color:var(--ink)}
blockquote{border-left:3px solid var(--accent);margin:1em 0;padding:.2em 0 .2em 14px;color:var(--strong)}
hr{border:0;border-top:1px solid var(--hair);margin:1.5em 0}
.pagemark{margin:1.5em 0;padding-top:.5em;border-top:1px dashed var(--hair)}.pagemark a{font:11px 'IBM Plex Mono',monospace;color:var(--muted)}
.tw{overflow-x:auto;margin:1em 0}table{border-collapse:collapse;font-size:13px;min-width:100%}
th,td{border:1px solid var(--hair);padding:6px 10px;text-align:left;vertical-align:top}
th{background:var(--panel);color:var(--strong);font-family:'Saira Condensed',sans-serif;letter-spacing:.03em}
.err{color:#e06b45}
</style></head><body>__BODY__</body></html>"""

def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--port", type=int, default=7070)
    ap.add_argument("--host", default="0.0.0.0")
    a = ap.parse_args()
    srv = ThreadingHTTPServer((a.host, a.port), H)
    print(f"doc browser: http://localhost:{a.port}/  (serving {DOCS.relative_to(ROOT)}/ + corpus/ page-links)")
    print("Ctrl+C to stop.")
    try:
        srv.serve_forever()
    except KeyboardInterrupt:
        print("\nstopped.")

if __name__ == "__main__":
    main()
