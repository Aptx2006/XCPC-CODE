from collections import defaultdict
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
    b = list(II() for i in range(n))
    a = [1] * n
    mp = defaultdict(list)
    for i, x in enumerate(b):
        mp[x].append(i)
    b = sorted(set(b))
    lastans = 0
    if b[0] != 0:
        out.append(-1)
        return
    for i in range(1, len(b)):
        sz = len(mp[b[i - 1]])
        cur = b[i] - b[i - 1]
        ans = cur // sz
        if cur % sz != 0 or ans <= lastans:
            out.append(-1)
            return
        for j in mp[b[i - 1]]:
            a[j] = ans
        lastans = ans
    for j in mp[b[-1]]:
        a[j] = lastans + 1
    out.append(' '.join(map(str, a)))


for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
