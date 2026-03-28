# Problem: B - Personnel Change
# Contest: AtCoder - AtCoder Beginner Contest 451
# URL: https://atcoder.jp/contests/abc451/tasks/abc451_b
# StartTime 2026-03-28 20:11:46
# Memory Limit: 1024 MB
# Time Limit: 2000 ms
# Coder:Aptx4869
# 
# Powered by CP Editor (https://cpeditor.org)

import sys
input = lambda: sys.stdin.readline().strip()
def main():
	n, m = map(int, input().split())
	ans = [0] * (m + 1)
	for _ in range(n):
		x, y = map(int, input().split())
		ans[x] -= 1
		ans[y] += 1
	for _ in range(1, m + 1):
		print(ans[_])

main()