#!/usr/bin/env python3
"""Extract an attributed, offline Hormuz basemap; never fetch OSM raster tiles."""

import hashlib
import json
import shutil
import subprocess
import tarfile
import tempfile
import urllib.request
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
OUTPUT = ROOT / "code" / "maps"
SOURCE = "https://build.protomaps.com/20260910.pmtiles"
TOOL_URL = (
    "https://github.com/protomaps/go-pmtiles/releases/download/v1.31.2/"
    "go-pmtiles_1.31.2_Linux_x86_64.tar.gz"
)
TOOL_SHA256 = "3ed7dbf4ec2e6dfe5e25b6f70d1ffc932729f93c86db353bf514dd71010a312f"
BOUNDS = [55.0, 25.0, 57.5, 27.5]  # west, south, east, north; degrees
MAX_ZOOM = 12


def download(url: str, path: Path) -> None:
    request = urllib.request.Request(url, headers={
        "User-Agent": "DeepBlueDynamics-Navy-Hormuz-Basemap/1.0"
    })
    with urllib.request.urlopen(request, timeout=120) as response, path.open("wb") as target:
        shutil.copyfileobj(response, target)


def sha256(path: Path) -> str:
    with path.open("rb") as source:
        return hashlib.file_digest(source, "sha256").hexdigest()


def main() -> None:
    OUTPUT.mkdir(parents=True, exist_ok=True)
    target = OUTPUT / "hormuz.pmtiles"
    if target.exists():
        raise SystemExit(f"Refusing to overwrite existing tile archive: {target}")
    # Keep download/extraction scratch on the host-backed workspace.
    with tempfile.TemporaryDirectory(prefix=".hormuz-acquire-", dir=OUTPUT) as scratch:
        scratch = Path(scratch)
        archive = scratch / "pmtiles.tar.gz"
        download(TOOL_URL, archive)
        if sha256(archive) != TOOL_SHA256:
            raise SystemExit("PMTiles release checksum does not match the pinned upstream digest")
        executable = scratch / "pmtiles"
        with tarfile.open(archive, "r:gz") as bundle:
            member = next(item for item in bundle.getmembers()
                          if item.isfile() and Path(item.name).name == "pmtiles")
            with bundle.extractfile(member) as source, executable.open("wb") as destination:
                shutil.copyfileobj(source, destination)
        executable.chmod(0o755)
        pending = scratch / "hormuz.pmtiles"
        subprocess.run([str(executable), "extract", SOURCE, str(pending),
                        "--bbox=" + ",".join(map(str, BOUNDS)),
                        f"--maxzoom={MAX_ZOOM}", "--download-threads=4"], check=True)
        subprocess.run([str(executable), "verify", str(pending)], check=True)
        header = json.loads(subprocess.check_output(
            [str(executable), "show", str(pending), "--header-json"], text=True))
        metadata = json.loads(subprocess.check_output(
            [str(executable), "show", str(pending), "--metadata"], text=True))
        pending.replace(target)
        manifest = {
            "name": "Strait of Hormuz",
            "file": target.name,
            "source": SOURCE,
            "tool": {"version": "1.31.2", "url": TOOL_URL, "sha256": TOOL_SHA256},
            "requested_bounds": BOUNDS,
            "center": [56.35, 26.45],
            "requested_maxzoom": MAX_ZOOM,
            "bytes": target.stat().st_size,
            "sha256": sha256(target),
            "header": header,
            "metadata": metadata,
            "attribution": "Map data: OpenStreetMap contributors; basemap: Protomaps.",
            "copyright_url": "https://www.openstreetmap.org/copyright",
            "license": "ODbL 1.0 Produced Work",
            "license_url": "https://opendatacommons.org/licenses/odbl/1-0/",
            "download_policy": "https://docs.protomaps.com/basemaps/downloads",
            "purpose": "Proposal demonstrator geographic context only. Not an ENC or a navigation chart.",
        }
        manifest_path = OUTPUT / "hormuz.manifest.json"
        manifest_path.write_text(json.dumps(manifest, indent=2) + "\n")
        print(json.dumps({"archive": str(target), "manifest": str(manifest_path),
                          "bytes": manifest["bytes"], "sha256": manifest["sha256"]}, indent=2))


if __name__ == "__main__":
    main()
