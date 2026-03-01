import sys
import math
from collections import defaultdict, deque
input = lambda: sys.stdin.readline()
MOD = 998244353
def main():
	n, m = map(int, input().split())
	e = list(map(int, input().split()))
	c = list(map(int, input().split()))
	ans = sum(x for x in c) * min(x for x in e)
	print(ans)
	
main()