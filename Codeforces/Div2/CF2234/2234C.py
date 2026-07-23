import sys
from itertools import accumulate

input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())


fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n = II()
    h = [II() for _ in range(n)]
    h2 = h + h
    res = []
    for l in range(n):
        tmp = h2[l : l + n]
        pre = list(accumulate(tmp, max))
        suf = list(accumulate(tmp[::-1], max))[::-1]
        ans = sum(p if p < s else s for p, s in zip(pre, suf[1:]))
        res.append(ans)
        
    out.append(" ".join(map(str, res)))

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))