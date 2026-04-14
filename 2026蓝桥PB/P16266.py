import sys
input = lambda: sys.stdin.readline().strip()

n, k = map(int, input().split())
mod = 10**9 + 7

#dp[i][j]长度为i, 总得分为j的方案数
dp = [[0] * (k + 1) for _ in range(n + 2)]
dp[0][0] = 1

for i in range(1, n + 2):
    for j in range(k + 1):
        if dp[i - 1][j] == 0 and sum(dp[i - 1]) == 0:
            continue
        for L in range(i):
            pi = i - L - 1
            if dp[pi][j] > 0:
                sc = j + L * (L + 1) // 2
                sc = min(sc, k)
                dp[i][sc] = (dp[i][sc] + dp[pi][j]) % mod

print(dp[n + 1][k])    
