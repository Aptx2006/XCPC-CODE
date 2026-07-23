import sys
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, m = II(), II()
    if n & 1 and m & 1:
        out.append((n - 1) // 2 * m + m // 2)
    elif n & 1:
        out.append(m // 2 * n)
    else:
        out.append(n // 2 * m)

main()

print('\n'.join(map(str, out)))
