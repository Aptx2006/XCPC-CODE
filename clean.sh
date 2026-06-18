#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$script_dir"

echo "正在清理所有子文件夹中的 .exe 文件和 .cph 文件夹..."

# 1. 递归删除所有 .exe 文件
find . -type f -name '*.exe' -delete

# 2. 递归删除所有 .cph 文件夹（包括文件夹本身及其内部所有内容）
# 使用 -prune 是为了防止 find 试图进入已经被 rm -rf 删掉的文件夹内部，从而报出警告
find . -type d -name '.cph' -prune -exec rm -rf {} +

echo "清理完成！"
