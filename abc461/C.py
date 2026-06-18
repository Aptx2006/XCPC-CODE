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
    a = list((II(), II()) for i in range(n))
    a.sort()
    mn = a[0][1]
    ans = 1
    for (x, y) in a:
        if y < mn:
            ans += 1  
        mn = fmin(mn, y)
    out.append(ans)

main()

print('\n'.join(map(str, out)))
