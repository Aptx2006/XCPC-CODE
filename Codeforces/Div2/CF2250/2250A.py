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
    a = list(II() for i in range(n))
    if n & 1:
        out.append('NO')
    else:
        mnr = min(a[i] for i in range(0, n, 2))
        mxl = max(a[i] for i in range(1, n, 2))
        if mnr - mxl <= 1:
            out.append('NO')
        else:
            out.append('YES')

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
