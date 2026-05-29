import sys
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, m, a = II(), II(), II()
    l = (n + a - 1) // a
    r = (m + a - 1) // a
    out.append(l * r)

main()

print('\n'.join(map(str, out)))
