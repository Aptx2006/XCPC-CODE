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
    a = [0] + sorted([II() for i in range(n)])
    if max(a) > 2 or a[-1] + a[-2] >= 4:
        out.append('Yes')
    else:
        out.append('No')

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
