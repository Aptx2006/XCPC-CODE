import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []
mod = 998244353

def main():
    n = II()
    m = II()
    a = list(II() for i in range(m))
    for x in a:
        if x > 2 * n:
            out.append(0)
            return
    isok = [False] * (2 * n + 1)
    for x in a:
        isok[x] = True
    dp = [1]
    for i in range(1, 2 * n + 1):
        mxj = i if i < 2 * n - i else 2 * n - i
        ndp = [0] * (mxj + 1)
        p = mxj if len(dp) > mxj else len(dp)
        ndp[1 : p + 1] = dp[:p]
        if not isok[i]:
            for j in range(len(dp) - 1):
                ndp[j] = (ndp[j] + dp[j + 1]) % mod
        dp = ndp
        
    out.append(dp[0])

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
