from collections import Counter
import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

N = 105
mod = 998244353
fact = [1] * N
for i in range(1, N):
    fact[i] = fact[i - 1] * i
    if fact[i] > mod:
        fact[i] %= mod
inv = [pow(x, mod - 2, mod) for x in fact]

def comb(n, m):
    return fact[n] * inv[m] * inv[n - m] % mod

def main():
    print()

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
