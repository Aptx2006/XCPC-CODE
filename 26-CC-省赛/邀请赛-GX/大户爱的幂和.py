from collections import Counter
import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, m = II(), II()
    a = list(II() for _ in range(n))
    out.append(pow(max(a), m, 998244353) + n - 1)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
