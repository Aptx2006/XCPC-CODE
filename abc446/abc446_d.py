import sys
import math
from collections import defaultdict, deque, Counter
input = lambda: sys.stdin.readline()
def main():
	n = int(input())
	a = list(map(int, input().split()))
	dp = Counter()
	ans = 0
	for x in a:
		dp[x] = dp[x - 1] + 1
		ans = max(ans, dp[x])
	print(ans)
	
main()