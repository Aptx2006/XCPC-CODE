# Problem: Stamina and Tasks
# Contest: Codeforces
# URL: https://m1.codeforces.com/contest/2208/problem/C
# Memory Limit: 256 MB
# Time Limit: 2000 ms
# 
# Powered by CP Editor (https://cpeditor.org)

import sys
input = lambda: sys.stdin.readline().strip()
def main():
	n = int(input())
	a = []
	for _ in range(n):
		c, p = map(float, input().split())
		a.append( (c, p) )
	ans = 0
	for i in range(n - 1, -1, -1):
		c, p = a[i]
		ans = max(ans, c + (1 - p / 100) * ans)
	print(ans)
for _ in range(int(input())):
	main()