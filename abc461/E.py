import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def cost1(x, y, a, b):
    n = x + y
    if a <= b:
        a, b, x, y = b, a, y, x
    cheap = fmin(y, (n + 1) // 2) + fmin(x, n // 2)
    return cheap * b + (n - cheap) * a

def cost2(x, y, a, b):
    c = fmin(a, b)
    if (x & 1) == (y & 1):
        k = fmax(x, y)
        if (k & 1) != (x & 1):
            k += 1
        return 2 * k * c
    elif a <= b:
        k = fmax(y, x - 1)
        if (k & 1) != (y & 1):
            k += 1
        return (2 * k + 1) * c
    else:
        k = fmax(x, y - 1)
        if (k & 1) != (x & 1):
            k += 1
        return (2 * k + 1) * c

def main():
    a, b, x, y = II(), II(), II(), II()
    x = abs(x)
    y = abs(y)

    out.append(fmin(cost1(x, y, a, b), cost2(x, y, a, b)))

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))