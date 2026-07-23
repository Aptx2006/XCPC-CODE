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
    A = n % 12
    B = n // 12 * 12
    if A != 10:
        out.append(f'{A} {B}')
    elif B >= 12:
        A += 12
        B -= 12
        out.append(f'{A} {B}')
    else:
        out.append(-1)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
