# Problem: C - Understory
# Contest: AtCoder - AtCoder Beginner Contest 451
# URL: https://atcoder.jp/contests/abc451/tasks/abc451_c
# StartTime 2026-03-28 20:15:09
# Memory Limit: 1024 MB
# Time Limit: 2000 ms
# Coder:Aptx4869
# 
# Powered by CP Editor (https://cpeditor.org)

import sys, heapq, bisect
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
def main():
	q = II()
	a = []
	for _ in range(q):
		op, x = II(), II()
		#print(a, p)
		if op == 1:
			heapq.heappush(a, x)
		else:
			while a and a[0] <= x:
				heapq.heappop(a)
		print(len(a))
			
					

main()
