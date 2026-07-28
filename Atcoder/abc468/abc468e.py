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
    a = list(II() for i in range(n))
    MOD = 998244353

    pre = [0] * (n + 1)
    for i in range(n):
        pre[i + 1] = (pre[i] + a[i]) % MOD

    pre_ = [0] * (n + 1)
    for i in range(n + 1):
        pre_[i] = (pre_[i - 1] + pre[i]) % MOD if i > 0 else pre[0]

    inv = [0] * (n + 1)
    inv[1] = 1
    for i in range(2, n + 1):
        inv[i] = (MOD - MOD // i) * inv[MOD % i] % MOD

    ans = 0
    for m in range(1, n + 1):
        sum = (pre_[n] - pre_[m - 1] - pre_[n - m]) % MOD
        ans = (ans + sum * inv[m]) % MOD

    out.append(ans)

main()

print('\n'.join(map(str, out)))