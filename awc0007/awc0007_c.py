import sys
import math
from collections import defaultdict, deque, Counter
input = lambda: sys.stdin.readline()
MOD = 998244353
def main():
	n, k = map(int, input().split())
	a = list(map(int, input().split()))
	S = list((-a[i], i + 1) for i in range(n))
	while len(S) > 1:
		rd = []
		group = []
		for s in S:
			group.append(s)
			if len(group) == k:
				rd.append(min(group))
				group = []
		if group:
			rd.append(min(group))
		S = rd
	print(S[0][1])
	
main()