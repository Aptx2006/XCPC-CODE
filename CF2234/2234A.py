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
    b = [II() for i in range(n)]
    b.sort(reverse = True)
    if sum(b[i + 2] == b[i] % b[i + 1] for i in range(n - 2)) == n - 2:
        out.append(f'{b[0]} {b[1]}')
    else:
        out.append(-1)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
