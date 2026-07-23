# Problem: Bingo Candies
# Contest: Codeforces
# URL: https://m1.codeforces.com/contest/2208/problem/A
# Memory Limit: 256 MB
# Time Limit: 1000 ms
# 
# Powered by CP Editor (https://cpeditor.org)

import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
from collections import Counter
def main():
	n = II()
	a = list([] for _ in range(n))
	for _ in range(n):
		a[_] = [II() for _ in range(n)]
	mp = Counter()
	for v in a:
		for x in v:
			mp[x] += 1
	if max(mp[x] for x in mp) <= n * (n - 1):
		print('YES')
	else:
		print('NO')
		
for _ in range(II()):
	main()
