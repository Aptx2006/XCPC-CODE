# Problem: A - illegal
# Contest: AtCoder - AtCoder Beginner Contest 451
# URL: https://atcoder.jp/contests/abc451/tasks/abc451_a
# StartTime 2026-03-28 20:08:30
# Memory Limit: 1024 MB
# Time Limit: 2000 ms
# Coder:Aptx4869
# 
# Powered by CP Editor (https://cpeditor.org)

import sys
input = lambda: sys.stdin.readline().strip()
def main():
	s = input()
	if len(s) == 5 or len(s) == 10:
		print('Yes')
	else:
		print('No')

main()