import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())

from collections import defaultdict
fmax = lambda x, y: x if x > y else y

MA = (1 << 30) - 1
stk = []
mp = defaultdict(list)
s = 0
for _ in range(ii()):
    tp, *q = mii()
    if tp == 1:
        c, v = q
        stk.append((c << 30) | v)
        if not mp[c]:
            mp[c].append(0)
        s -= mp[c][-1]
        mp[c].append(fmax(mp[c][-1], v))
        s += mp[c][-1]
    elif tp == 2:
        v = stk.pop()
        c, v = v >> 30, v & MA
        s -= mp[c].pop()
        s += mp[c][-1]
    else:
        print(s)
