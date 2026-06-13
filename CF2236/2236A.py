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
    out.append(max(a) + 1 - min(a))

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))