import sys
import math
from collections import defaultdict, deque
input = lambda: sys.stdin.readline()
MOD = 998244353
def main():
	n = int(input())
	a = list(map(int, input().split()))
	pre = [1] * (n + 1)
	for i in range(1, n + 1):
		x = pre[i - 1]
		y = a[i - 1]
		pre[i] = (x * y // math.gcd(x, y)) % MOD
	suf = [1] * (n + 5)
	for i in range(n - 1, -1, -1):
		x = suf[i + 1]
		y = a[i]
		suf[i] = (x * y // math.gcd(x, y)) % MOD
	ans = []
	for i in range(n):
		x = pre[i]
		y = suf[i + 1]
		ans.append( (x * y // math.gcd(x, y)) % MOD )
	for x in ans:
		print(x, end = ' ')
	print()
	
for _ in range(int(input())):
	main()