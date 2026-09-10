#!/usr/bin/env python3
"""Vendor the pinned Meridian map runtime and Latin-label glyphs for offline use."""
import base64
import hashlib
import json
import shutil
import tarfile
import tempfile
from urllib.parse import quote

from acquire_hormuz_tiles import ROOT, download, sha256

VENDOR = ROOT / "code" / "maps" / "vendor"
FONT_REVISION = "028c18f713baecad011301ff7a69acc39bcc2ae7"
FONT_BASE = f"https://raw.githubusercontent.com/protomaps/basemaps-assets/{FONT_REVISION}/fonts/"
PACKAGES = {
    "maplibre-gl": {
        "version": "4.7.1",
        "assets": {
            "package/dist/maplibre-gl.js": "maplibre-gl.js",
            "package/dist/maplibre-gl.css": "maplibre-gl.css",
            "package/LICENSE.txt": "maplibre-gl.LICENSE.txt",
        },
    },
    "pmtiles": {
        "version": "3.2.1",
        "assets": {"package/dist/pmtiles.js": "pmtiles.js"},
        "license_url": (
            "https://raw.githubusercontent.com/protomaps/PMTiles/"
            "d7357088c5b971b6d756a43b798182bb6777043d/LICENSE"
        ),
    },
}


def main() -> None:
    VENDOR.mkdir(parents=True, exist_ok=True)
    records = []
    with tempfile.TemporaryDirectory(prefix=".map-runtime-", dir=VENDOR.parent) as scratch:
        from pathlib import Path
        scratch = Path(scratch)
        for package, specification in PACKAGES.items():
            version = specification["version"]
            assets = specification["assets"]
            package_info = scratch / f"{package}.json"
            download(f"https://registry.npmjs.org/{package}/{version}", package_info)
            info = json.loads(package_info.read_text())
            archive = scratch / f"{package}.tgz"
            download(info["dist"]["tarball"], archive)
            algorithm, expected = info["dist"]["integrity"].split("-", 1)
            with archive.open("rb") as file:
                digest = hashlib.file_digest(file, algorithm).digest()
            if base64.b64encode(digest).decode() != expected:
                raise SystemExit(f"npm integrity mismatch for {package}@{version}")
            with tarfile.open(archive, "r:gz") as bundle:
                for member_name, filename in assets.items():
                    target = VENDOR / filename
                    with bundle.extractfile(member_name) as source, target.open("wb") as destination:
                        shutil.copyfileobj(source, destination)
                    records.append({"file": filename, "sha256": sha256(target),
                                    "package": package, "version": version,
                                    "source": info["dist"]["tarball"],
                                    "npm_integrity": info["dist"]["integrity"]})
            if "license_url" in specification:
                target = VENDOR / f"{package}.LICENSE.txt"
                download(specification["license_url"], target)
                records.append({"file": target.name, "sha256": sha256(target),
                                "package": package, "version": version,
                                "source": specification["license_url"]})
        font_name = "Noto Sans Regular"
        font_directory = VENDOR / "fonts" / font_name
        font_directory.mkdir(parents=True, exist_ok=True)
        # The renderer requests explicit English names, including Latin diacritics
        # and general punctuation, rather than silently substituting place names.
        for start in [0, 256, 512, 768, 7680, 8192]:
            filename = f"{start}-{start + 255}.pbf"
            source = FONT_BASE + quote(font_name) + "/" + filename
            target = font_directory / filename
            download(source, target)
            records.append({"file": str(target.relative_to(VENDOR)),
                            "source": source, "sha256": sha256(target), "license": "OFL-1.1"})
        font_license = VENDOR / "fonts" / "OFL.txt"
        download(FONT_BASE + "OFL.txt", font_license)
        records.append({"file": str(font_license.relative_to(VENDOR)),
                        "source": FONT_BASE + "OFL.txt", "sha256": sha256(font_license),
                        "license": "OFL-1.1"})
    manifest = {"purpose": "Offline Meridian-derived Hormuz map runtime", "files": records}
    (VENDOR / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")
    print(json.dumps({"directory": str(VENDOR), "files": len(records),
                      "packages": {name: value["version"] for name, value in PACKAGES.items()}}, indent=2))


if __name__ == "__main__":
    main()
