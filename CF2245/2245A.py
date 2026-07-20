import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, k = II(), II()
    s = SI()
    if k > n // 2:
        out.append(-1)
        return
    ans = 0
    for x in s[:k]:
        ans += int(x == 'L')
    for x in s[-k:]:
        ans += int(x == 'R')
    out.append(ans)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
