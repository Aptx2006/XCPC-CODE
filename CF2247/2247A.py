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
    a = list(II() for _ in range(n))
    if n % 2 == 0 and (n // 2) % 2 == sum(int(x == -1) for x in a) % 2:
        out.append('YES')
    else:
        out.append('NO')

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
