import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

MOD = 998244353

def main():
    n = II()
    m = II()
    r = II()
    c = II()
    mi = n * m - (n - r + 1) * (m - c + 1)
    out.append(pow(2, mi, MOD))

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
