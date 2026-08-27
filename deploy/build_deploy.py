#!/usr/bin/env python3
"""Build the deployable static site for the APNT console + its Twitter/OG card.

- Rasterizes a 1200x630 social card (og-card.png) with PyMuPDF built-in fonts
  (no external font dependency, robust in a bare container).
- Wraps notes/hmi-mockups/apnt-console.html into a standalone deploy/index.html
  with a proper <!doctype> + <head> carrying Open Graph + Twitter Card meta.

Usage: python3 build_deploy.py [DEPLOY_URL]
  DEPLOY_URL fills og:url/og:image absolutely (Twitter needs absolute URLs).
  Omit to leave the __DEPLOY_URL__ placeholder (deploy.ps1 bakes it after first deploy).
"""
import sys
from pathlib import Path
import fitz  # PyMuPDF

ROOT = Path(__file__).resolve().parent.parent
SRC = ROOT / "notes" / "hmi-mockups" / "apnt-console.html"
OUT = ROOT / "deploy"
URL = sys.argv[1].rstrip("/") if len(sys.argv) > 1 else "__DEPLOY_URL__"

def hx(h):
    h = h.lstrip("#"); return tuple(int(h[i:i+2], 16) / 255 for i in (0, 2, 4))

# ---- 1. social card ----
def build_card():
    W, H = 1200, 630
    bg, panel, ink, muted, good, caution, accent, hair = (
        hx("070f17"), hx("0d1a26"), hx("eaf1f5"), hx("6f8593"),
        hx("43b17f"), hx("e0a53a"), hx("5bb0cb"), hx("1a2c3a"))
    doc = fitz.open(); page = doc.new_page(width=W, height=H)
    sh = page.new_shape()
    sh.draw_rect(fitz.Rect(0, 0, W, H)); sh.finish(fill=bg)
    sh.draw_rect(fitz.Rect(48, 48, W-48, H-48)); sh.finish(fill=panel, color=hair, width=1)
    # accent rule
    sh.draw_line(fitz.Point(88, 250), fitz.Point(360, 250)); sh.finish(color=accent, width=3)
    # compass rose glyph (drawn, not emoji)
    cx, cy, r = 1050, 150, 46
    sh.draw_circle(fitz.Point(cx, cy), r); sh.finish(color=accent, width=2)
    for ang in (0, 90, 180, 270):
        import math
        a = math.radians(ang)
        sh.draw_line(fitz.Point(cx, cy), fitz.Point(cx + r*math.sin(a), cy - r*math.cos(a)))
    sh.finish(color=accent, width=1.5)
    sh.draw_polyline([fitz.Point(cx, cy-r-4), fitz.Point(cx-9, cy), fitz.Point(cx, cy+8),
                      fitz.Point(cx+9, cy), fitz.Point(cx, cy-r-4)]); sh.finish(fill=caution)
    # status pills (mini confidence-tile motif) — draw boxes now, text after commit
    pills = [("POSITION  DEGRADED", caution), ("NAV  NOMINAL", good), ("TIMING  NOMINAL", good)]
    pill_labels = []
    px = 88
    for txt, col in pills:
        w = 26 + len(txt) * 8.6
        sh.draw_rect(fitz.Rect(px, 470, px+w, 508)); sh.finish(color=col, width=1.5)
        pill_labels.append((px+13, 494, txt, col))
        px += w + 16
    sh.commit()
    for lx, ly, txt, col in pill_labels:
        page.insert_text(fitz.Point(lx, ly), txt, fontname="hebo", fontsize=13, color=col)
    page.insert_text(fitz.Point(88, 150), "ASSURED-PNT", fontname="hebo", fontsize=76, color=ink)
    page.insert_text(fitz.Point(88, 226), "CONSOLE", fontname="hebo", fontsize=76, color=ink)
    page.insert_text(fitz.Point(88, 310), "Notional ECDIS-N operator awareness & decision support",
                     fontname="helv", fontsize=24, color=muted)
    page.insert_text(fitz.Point(88, 344), "for assured PNT in GPS-degraded / contested waters",
                     fontname="helv", fontsize=24, color=muted)
    page.insert_text(fitz.Point(88, 560), "DON26BX05-NP004", fontname="hebo", fontsize=16, color=accent)
    page.insert_text(fitz.Point(300, 560), "alert -> evidence -> COA -> retrieved procedure",
                     fontname="helv", fontsize=16, color=muted)
    pix = page.get_pixmap(matrix=fitz.Matrix(2, 2))  # 2x for crispness (2400x1260)
    OUT.mkdir(exist_ok=True)
    pix.save(str(OUT / "og-card.png"))
    print(f"card: {OUT/'og-card.png'} ({pix.width}x{pix.height})")

# ---- 2. standalone index.html with OG/Twitter meta ----
def build_index():
    html = SRC.read_text(encoding="utf-8")
    marker = '<div class="console">'
    i = html.index(marker)
    head_src, body_src = html[:i], html[i:]
    desc = ("Notional ECDIS-conformant assured-PNT operator console — flip nominal vs "
            "GNSS-degraded, S-52 day/dusk/night. DON26BX05-NP004.")
    og = f'''<meta charset="utf-8">
<meta property="og:type" content="website">
<meta property="og:title" content="Assured-PNT Console">
<meta property="og:description" content="{desc}">
<meta property="og:image" content="{URL}/og-card.png">
<meta property="og:image:width" content="2400">
<meta property="og:image:height" content="1260">
<meta property="og:url" content="{URL}/">
<meta name="twitter:card" content="summary_large_image">
<meta name="twitter:title" content="Assured-PNT Console">
<meta name="twitter:description" content="{desc}">
<meta name="twitter:image" content="{URL}/og-card.png">
'''
    doc = ("<!doctype html>\n<html lang=\"en\">\n<head>\n" + og + head_src.strip()
           + "\n</head>\n<body>\n" + body_src.strip() + "\n</body>\n</html>\n")
    (OUT / "index.html").write_text(doc, encoding="utf-8")
    print(f"index: {OUT/'index.html'} ({len(doc)} bytes, url={URL})")

if __name__ == "__main__":
    build_card()
    build_index()
