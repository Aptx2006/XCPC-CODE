import sys
import math
from collections import defaultdict, deque
input = lambda: sys.stdin.readline()
MOD = 998244353
def main():
	n, m = map(int, input().split())
	s, t = map(int, input().split())
	p = list(map(int, input().split()))
	def idto(num):
		num -= 1
		r = num // n + 1
		c = num % n + 1
		return (r, c)
	
	p = [s] + p + [t]
	G = [idto(x) for x in p]
	N = m + 2
	dist = [[0] * (N + 5) for _ in range(N + 5)]
	for	i in range(N):
		r1, c1 = G[i]
		for j in range(N):
			r2, c2 = G[j]
			dist[i][j] = abs(r1 - r2) + abs(c1 - c2)
	INF = float('inf')
	dp =[ [INF] * (N + 2) for _ in range(1 << (N + 2)) ]
	dp[0][0] = 0
	for mask in range(1 << m):
		for i in range(m + 1):
			if dp[mask][i] == INF:
				continue
			for j in range(1, m + 1):
				if mask & (1 << (j - 1)):
					continue
				nmask = mask | (1 << (j - 1))
				if dp[nmask][j] > dp[mask][i] + dist[i][j]:
					dp[nmask][j] = dp[mask][i] + dist[i][j];
	mask = (1 << m) - 1
	if m == 0:
		print(dist[0][1])
	else:
		print(min(dp[mask][i] + dist[i][m + 1] for i in range(m + 1)))
		
main()