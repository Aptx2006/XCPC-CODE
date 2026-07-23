import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    a = SI()
    b = SI()
    n = len(a)
    m = len(b)

    pre1 = [0] * (n + 1)
    for i in range(1, n + 1):
        pre1[i] = (pre1[i - 1] + (ord(a[i - 1]) - 48)) % 10
    pre2 = [0] * (m + 1)
    for j in range(1, m + 1):
        pre2[j] = (pre2[j - 1] + (ord(b[j - 1]) - 48)) % 10

    if pre1[n] != pre2[m]:
        out.append("-1")
        return

    inf = -10 ** 9

    # a[i - 1] b[j - 1] 转移出的最大段数
    dp = [[inf] * (m + 1) for _ in range(10)]
    dp[0][0] = 0

    for i in range(1, n + 1):
        dp_ = [[inf] * (m + 1) for _ in range(10)]
        for d in range(10):
            cur = inf
            for j in range(m + 1):
                dp_[d][j] = cur
                cur = fmax(dp[d][j], cur)

        for j in range(1, m + 1):
            d = (pre1[i] - pre2[j] + 10) % 10
            ans = dp_[d][j]
            if ans != inf:
                cur = ans + 1
                dp[d][j] = fmax(cur, dp[d][j])

    ans = max(dp[d][m] for d in range(10))
    out.append(ans)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))