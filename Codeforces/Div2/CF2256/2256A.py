import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    a, b, c = II(), II(), II()
    mx = fmax(a, fmax(b, c))
    mn = fmin(a, fmin(b, c))
    mid = a + b + c - mx - mn
    out.append(fmin(mx - mn, mid))


for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
