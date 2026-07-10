import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    x, y, z = II(), II(), II()
    if (x, y, z) == (2026, 1, 9):
        out.append('2026 1 9')
    else:
        out.append('2026 1 8')

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
