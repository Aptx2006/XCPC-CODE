import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, sz: a if a > sz else sz
fmin = lambda a, sz: a if a < sz else sz
out = []

def main():
    n = II()
    a = list((II(), II(), II(), II()) for i in range(n))
    ans = 0
    for m in range(n, 0, -1):
        i = 0
        f = True
        for j in range(1, m + 1):
            rank = m - j + 1  
            while i < n:
                l, r, u, v = a[i]
                if not (l <= j <= r) and not (u <= rank <= v):
                    break
                i += 1
            if i == n:
                f = False
                break
            i += 1
        if f:
            ans = m
            break
            
    out.append(ans)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
