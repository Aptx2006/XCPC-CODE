import sys
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n = II()
    d = [0] * (n + 5)
    for i in range(2 * n - 2):
        d[II()] += 1
        
    mod = 1000000007
    ans = 0

    N = n + 5
    fact = [1] * N
    inv = [1] * N
    for i in range(1, N):
        fact[i] = (fact[i - 1] * i) % mod

    inv[N - 1] = pow(fact[N - 1], mod - 2, mod)

    for i in range(N - 2, -1, -1):
        inv[i] = (inv[i + 1] * (i + 1)) % mod

    def comb(n, k):
        if k < 0 or k > n:
            return 0
        return fact[n] * inv[k] % mod * inv[n - k] % mod
    
    L, R = II(), II()
    for u in range(1, n + 1):
        start = max(L - 1, 0)
        limit = min(R - 1, d[u])
        
        for k in range(start, limit + 1):
            ans = (ans + comb(d[u], k)) % mod
       
    if L <= 2 <= R:
        ans = (ans - (n - 1) + mod) % mod
        
    out.append(ans)

for _ in range(1):
    main()

print('\n'.join(map(str, out)))
