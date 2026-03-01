import sys
import math
from collections import defaultdict, deque
input = lambda: sys.stdin.readline()
MOD = 998244353
def main():
	n, a, b = map(int, input().split())
	diff = list([0] * (n + 5) for i in range(n + 5))
	for _ in range(a):
		r1, c1, r2, c2 = map(int, input().split())
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
		r1, c1, r2, c2 = map(int, input().split())
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