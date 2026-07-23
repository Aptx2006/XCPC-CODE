import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())


fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, x, y, z = II(), II(), II(), II()
    A = fmin(z, (n + x - 1) // x) + fmax(0, (n - z * x + (x + 10 * y - 1)) // (x + 10 * y))
    B = fmax(0, (n + x + y - 1) // (x + y))
    out.append(fmin(A, B))
    

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
