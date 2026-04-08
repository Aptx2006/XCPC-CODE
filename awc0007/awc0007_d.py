import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
import math
from collections import defaultdict, deque
MOD = 998244353
def main():
	n, a, b = II(), II(), II()
	diff = list([0] * (n + 5) for i in range(n + 5))
	for _ in range(a):
		r1, c1, r2, c2 = II(), II(), II(), II()
		diff[r1][c1] += 1
		diff[r1][c2 + 1] -= 1
		diff[r2 + 1][c1] -= 1
		diff[r2 + 1][c2 + 1] += 1
	for c in range(1, n + 1):
		for r in range(1, n + 1):
			diff[r][c] += diff[r][c - 1]
	for c in range(1, n + 1):
		for r in range(1, n + 1):
			diff[r][c] += diff[r - 1][c]
	diffB = list([0] * (n + 5) for i in range(n + 5))
	for _ in range(b):
		r1, c1, r2, c2 = II(), II(), II(), II()
		diffB[r1][c1] += 1
		diffB[r1][c2 + 1] -= 1
		diffB[r2 + 1][c1] -= 1
		diffB[r2 + 1][c2 + 1] += 1
	for c in range(1, n + 1):
		for r in range(1, n + 1):
			diffB[r][c] += diffB[r][c - 1]
	for c in range(1, n + 1):
		for r in range(1, n + 1):
			diffB[r][c] += diffB[r - 1][c]
	ans = 0
	for c in range(1, n + 1):
		for r in range(1, n + 1):
			if diff[r][c] and diffB[r][c]:
				ans += 1
	print(ans) 
	
	
main()
