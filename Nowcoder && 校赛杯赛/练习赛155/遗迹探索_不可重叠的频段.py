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
    n = II()
    x = II()
    a = [II() for i in range(n)]
    cnt = Counter(a)
    aa = sorted(cnt)
    vis = set()
    mx = 0
    for v in reversed(aa):
        c = cnt[v]
        u = v - x
        tmax = fmax(v, u)
        tmin = fmin(v, u)
        if c == 1:
            if tmax > 0 and tmax not in vis:
                vis.add(tmax)
                mx += tmax
            elif tmin > 0 and tmin not in vis:
                vis.add(tmin)
                mx += tmin
        else:
            if tmax > 0 and tmax not in vis:
                vis.add(tmax)
                mx += tmax
            if tmin > 0 and tmin not in vis:
                vis.add(tmin)
                mx += tmin

    vis.clear()
    mn = 0
    for v in aa:
        c = cnt[v]
        u = v - x
        tmax = fmax(v, u)
        tmin = fmin(v, u)
        if c == 1:
            if tmin < 0 and tmin not in vis:
                vis.add(tmin)
                mn += tmin
            elif tmax < 0 and tmax not in vis:
                vis.add(tmax)
                mn += tmax
        else:
            if tmin < 0 and tmin not in vis:
                vis.add(tmin)
                mn += tmin
            if tmax < 0 and tmax not in vis:
                vis.add(tmax)
                mn += tmax

    out.append(f'{mn} {mx}')

main()
print('\n'.join(out))