import itertools
import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n = II()
    s = SI()
    MOD = 998244353

    if s[0] == 'x' or s[-1] == 'x':
        out.append(0)
        return

    dp = [[0] * (n + 2) for _ in range(n + 2)]
    dp[1][0] = 1

    for i in range(2, n + 1):
        c = s[i - 1]
        sum = 0
        for d in range(n - i + 1):
            sum += dp[i - 1][d]
            res = (dp[i - 1][d + 1] * (d + 1) + 2 * sum) % MOD
#           for j in range(d + 1):
#               res = (res + 2 * dp[i - 1][j]) % MOD
            if c == 'o' and d != 0:
                res = 0
            if c == 'x' and d == 0:
                res = 0
            dp[i][d] = res

    out.append(dp[n][0])

main()

print('\n'.join(map(str, out)))