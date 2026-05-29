import sys
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, k = II(), II()
    ans = list(k if (n - 1) & i == i else 0 for i in range(n))
    out.append(' '.join(map(str, ans)))

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
