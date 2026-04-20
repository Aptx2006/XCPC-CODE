import sys
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

def main():
    w = II()
    f = II()
    n = II()
    a = list(II() for _ in range(n))
    m = sum(a)
    dp = [False] * (m + 5)
    dp[0] = True
    for x in a:
        for j in range(m, x - 1, -1):
            dp[j] = dp[j] or dp[j - x]
    ans = 10**9
    for i in range(m + 1):
        if dp[i]:
            ans = min(ans, max((i + w - 1) // w, (m - i + f - 1) // f))
    print(ans)

for _ in range(II()):
    main()
