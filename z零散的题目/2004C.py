import sys, math
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, k = II(), II()
    a = list(II() for _ in range(n))
    a.sort(reverse = True)
    ans = sum(a[i] for i in range(0, n - 1, 2)) - sum(a[i] for i in range(1, n, 2))
    ans = fmax(0, ans - k)
    if n & 1:
        ans += a[-1]
    out.append(ans)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
