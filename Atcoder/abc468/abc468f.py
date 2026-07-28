import itertools
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
    a = [II() for _ in range(n)]

    inf = 10**9
    bit = [-inf] * (n + 2)

    def upd(i, v):
        i += 1
        while i <= n + 1:
            if v > bit[i]:
                bit[i] = v
            i += i & -i

    def qry(i):
        res = -inf
        i += 1
        while i > 0:
            if bit[i] > res:
                res = bit[i]
            i -= i & -i
        return res

    upd(0, 0)
    add = cur = 0

    for v in a:
        if v > cur:
            mx = qry(cur)
            add += 1
            upd(cur, mx)
            cur = v
        else:
            mx = qry(v - 1)
            upd(v, mx + 1)

    out.append(qry(cur) + add)

main()

print('\n'.join(map(str, out)))