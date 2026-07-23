import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)

n = II()
a = [II() for _ in range(n)]
dp = [0] * (n + 1)
for i in range(n, 0, -1):
	dp[i] =(i if a[i - 1] == i else dp[a[i - 1]])
for x in dp[1:]:
	print(x, end = ' ') 
