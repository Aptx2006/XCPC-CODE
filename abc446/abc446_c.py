import sys
import math
from collections import defaultdict, deque, Counter
input = lambda: sys.stdin.readline()
def main():
	n, m = map(int, input().split())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	Q = deque()
	ans = 0
	for day in range(1, n+1):
		i = day - 1
		buy = a[i]
		cs = b[i]
		nday = day + m
		Q.append((buy, nday))
		ans += buy
		ncs = cs
		while ncs > 0 and Q:
			cur, exp = Q[0]
			if cur <= ncs:
				ncs -= cur
				ans -= cur
				Q.popleft()
			else:
				ans -= ncs
				Q[0] = (cur - ncs, exp)
				ncs = 0
	
		while Q and Q[0][1] <= day:
			nexp, _ = Q.popleft()
			ans -= nexp
	
	print(ans)
	  
for _ in range(int(input())):
	main()