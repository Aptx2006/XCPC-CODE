# Problem: Cyclists
# Contest: Codeforces
# URL: https://m1.codeforces.com/contest/2208/problem/B
# Memory Limit: 256 MB
# Time Limit: 1000 ms
# 
# Powered by CP Editor (https://cpeditor.org)

import sys
input = lambda: sys.stdin.readline().strip()
def main():
	n, k, p, m = map(int, input().split())
	a = list(map(int , input().split()))
	x, y = a[p - 1], a[p - 1]
	if k < p:
		b = a[:p - 1]
		b.sort()
		x += sum(b[i] for i in range(p - k))
	if k < n:
		b = list()
		for i in range(n):
			if i != p - 1:
				b.append(a[i])
		b.sort()
		y += sum(b[i] for i in range(n - k))
	if m < x:
		print(0)
	else:
		print(1 + (m - x) // y)
	 
for _ in range(int(input())):
	main()