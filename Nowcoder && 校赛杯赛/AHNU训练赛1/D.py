import sys
from itertools import combinations 
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []


def main():
    n, m = II(), II()
    a = [ [0, 0, 0] ] + list([II(), II(), II()] for _ in range(n))
    dp = list([0] * (m + 5) for _ in range(n + 5))
    a.sort(key = lambda A: A[1])
    for i in range(1, n + 1):
        p, v, w = a[i]
        for j in range(m, w - 1, -1):
            nc = dp[i - 1][j - w] * (1 - p / 100) + p / 100 * v
            dp[i][j] = fmax(dp[i - 1][j], nc)
        for j in range(min(w, m + 1)):
            dp[i][j] = dp[i - 1][j]
    out.append(max(dp[n]))
    

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
