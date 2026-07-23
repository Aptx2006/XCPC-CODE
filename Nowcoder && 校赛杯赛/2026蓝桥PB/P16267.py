import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
a = list(map(int, input().split()))
a = [0] + a
dp = list([0] * (n + 5) for _ in range(n + 5))
mod = 998244353

for L in range(1, n + 1):
    dp[L][L] = a[L]
    for R in range(L + 1, n + 1):
        dp[L][R] = max(a[R], dp[L][R - 1])

ans = 0
for L in range(1, n + 1):
    for R in range(L, n + 1):
        le = len(str(R - L + 1))
        ans = (ans + (le * dp[L][R]) % mod) % mod

print(ans % mod)
