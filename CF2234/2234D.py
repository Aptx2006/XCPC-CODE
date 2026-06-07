import sys
from functools import cache

input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

@cache
def dfs(k, u, v):
    if k == 0:
        return int(u == 2)
    return dfs(k - 1, u, u ^ v) + dfs(k - 1, u ^ v, v)

def main():
    n, k = II(), II()
    s, z = SI(), SI()

    cnt = [0] * 4
    for cs, cz in zip(s, z):
        cnt[(int(cs) << 1) | int(cz)] += 1

    ans = 0
    for i in range(4):
        if not cnt[i]: 
            continue
        for j in range(4):
            if not cnt[j]: 
                continue
            u = ((i >> 1) << 1) | (j >> 1)
            v = ((i & 1) << 1) | (j & 1)
            ans += cnt[i] * cnt[j] * (dfs(k, u, v) + int(v == 2))

    out.append(ans)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))