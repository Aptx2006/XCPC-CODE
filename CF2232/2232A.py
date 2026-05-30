import sys
from collections import Counter
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n = II()
    a = list(II() for _ in range(n))
    a.sort()
    mp = Counter(a)
    l = 0
    ans = n
    for v, c in mp.items():
        r = n - l - c
        ans = fmin(ans, fmax(l, r))
        l += c
    out.append(ans)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))

