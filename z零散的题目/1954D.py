import sys
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

MOD = 998244353

def main():
    n = II()
    a = [II() for i in range(n)]
    s = sum(a)
    
    dp = [0] * (s + 1)
    dp[0] = 1
    
    for i in range(n):
        for j in range(s - a[i], -1, -1):
            dp[j + a[i]] += dp[j]
            if dp[j + a[i]] > MOD:
                dp[j + a[i]] %= MOD

    ans = 0
    for j in range(s + 1):
        ans += (j + 1) // 2 * dp[j]
        if ans > MOD:
            ans %= MOD

    for i in range(n):
        for j in range(a[i]):
            ans += (a[i] - (a[i] + j + 1) // 2) * dp[j]
            if ans > MOD:
                ans %= MOD
    
    out.append(ans)

for _ in range(1):
    main()

print('\n'.join(map(str, out)))
