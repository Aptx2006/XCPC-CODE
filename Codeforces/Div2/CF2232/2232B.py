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
    ans = []
    sum = 0
    mn = 10**18
    for i in range(n):
        sum += a[i]
        mn = fmin(mn, sum // (i + 1))
        ans.append(mn)
    out.append(' '.join(map(str, ans)))

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))

