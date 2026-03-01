n = int(input())
a = list(map(int, input().split()))
dp = [0] * (n + 1)
for i in range(n, 0, -1):
	dp[i] =(i if a[i - 1] == i else dp[a[i - 1]])
for x in dp[1:]:
	print(x, end = ' ') 