import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, k, m = II(), II(), II()
    if k > m:
        out.append('NO')
        return
    out.append('YES')
    ans = []
    for i in range(1, n + 1):
        if i % k == 0:
            ans.append(m - k + 1)
        else:
            ans.append(1)
    out.append(' '.join(map(str, ans)))

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
