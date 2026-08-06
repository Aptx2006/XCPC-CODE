import sys
from collections import defaultdict
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n = II()
    m = II()
    G = []
    for _ in range(m):
        u, v, w = II(), II(), II()
        G.append((u, v, w))

    mx = n // 2 - 1
    if mx < 1:
        out.append(-1)
        return

    inf = 10**18
    dp = [inf] * (n + 1)
    dp[1] = 0

    ans = inf

    for i in range(1, mx + 1):
        ndp = [inf] * (n + 1)
        for u, v, w in G:
            if dp[u] != inf:
                ndp[v] = fmin(ndp[v], dp[u] + w)
        dp = ndp
        ans = fmin(ans, dp[n])

    if ans == inf:
        out.append(-1)
    else:
        out.append(ans)


main()

print('\n'.join(map(str, out)))