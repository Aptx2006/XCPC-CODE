import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
import math
from collections import defaultdict, deque, Counter
def main():
	n = II()
	a = [II() for _ in range(n)]
	dp = Counter()
	ans = 0
	for x in a:
		dp[x] = dp[x - 1] + 1
		ans = max(ans, dp[x])
	print(ans)
	
main()
