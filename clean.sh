#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$script_dir"

find . -type f -name '*.exe' -delete

if [ -d ".cph" ]; then
  find .cph -mindepth 1 -maxdepth 1 -exec rm -rf {} +
fi
