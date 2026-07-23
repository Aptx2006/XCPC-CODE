import sys
#input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)
sys.setrecursionlimit(1 << 20)

def main():
    n = II()
    p = [0] + [II() for _ in range(n - 1)]
    c = [0] + [II() for _ in range(n)]
    d = [0] + [II() for _ in range(n)]

    G = [[] for _ in range(n + 1)]
    for i in range(2, n + 1):
        G[p[i - 1]].append(i)

    sumd = sum(d)
    mod = 998244353
    fact = [1] * (sumd + 1)
    for i in range(1, sumd + 1):
        fact[i] = fact[i - 1] * i % mod
    ifact = [1] * (sumd + 1)
    ifact[sumd] = pow(fact[sumd], mod - 2, mod)
    for i in range(sumd, 0, -1):
        ifact[i - 1] = ifact[i] * i % mod

    def dfs(u):
        sc = c[u]
        sd = d[u]
        pool = c[u]
        prod = 1
        for v in G[u]:
            t = dfs(v)
            if t is None:
                return None
            vc, vd, vr, vw = t
            sc += vc
            sd += vd
            pool += vr
            prod = prod * vw % mod

        if sd > sc or pool < d[u]:
            return None

        k = d[u]
        num = 1
        for i in range(k):
            num = num * (pool - i) % mod
        return sc, sd, pool - k, prod * num % mod * ifact[k] % mod

    t = dfs(1)
    print(0 if t is None else t[3])

main()
