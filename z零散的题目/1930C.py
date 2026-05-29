import sys
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n = II()
    a = [II() + i + 1 for i in range(n)]
    a.sort(reverse=True)
    ans = []
    mx = 10**18
    for cap in a:
        take = min(cap, mx)
        ans.append(take)
        mx = take - 1
    out.append(' '.join(map(str, ans)))

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
