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
    s = SI()
    c = list([1] * 2 for i in range(2))
    for i in range(n):
        if s[i] != '?':
            c[i & 1][int(s[i]) == (i // 2) & 1] = 0
    out.append((c[0][0] + c[0][1]) * (c[1][0] + c[1][1]))

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
