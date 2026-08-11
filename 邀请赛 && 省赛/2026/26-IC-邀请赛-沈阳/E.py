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
    t = sorted(list(II() for i in range(n)))
    ans = 10**18
    for i in range(n):
        w = sorted([i - j + 1 + (n - i - 1) / 2 if j <= i else n - j for j in range(n)], reverse = True)
        ans = fmin(sum(w[j] * t[j] for j in range(n)), ans)
    out.append('%.1f' %ans)

main()

print('\n'.join(map(str, out)))
