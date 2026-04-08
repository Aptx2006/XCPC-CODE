import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
import math
from collections import defaultdict, deque
MOD = 998244353
def main():
	n, m = II(), II()
	e = [II() for _ in range(n)]
	c = [II() for _ in range(n)]
	ans = sum(x for x in c) * min(x for x in e)
	print(ans)
	
main()
