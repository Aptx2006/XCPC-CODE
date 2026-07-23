import sys
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, x = II(), II()
    mex = 1 << 30
    mx = b = 0
    for i in range(30):
        if mex == (1 << 30) and not x & (1 << i):
            b = i
            mex = (1 << i)
        if x & (1 << i):
            mx = i
    ans = []
    if mex < n:
        for i in range(mex):
            ans.append(i)
        for i in range(mex, n):
            ans.append(x)
    else:
        cur = 0
        for i in range(n - 1):
            ans.append(i)
            cur |= i
        if cur | (n - 1) == x:
            ans.append(n - 1)
        else:
            ans.append(x)
    out.append(' '.join(map(str, ans)))

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
