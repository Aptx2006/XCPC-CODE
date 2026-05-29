import sys
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)
sys.setrecursionlimit(10**6)
fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    mod = 10**9 + 7
    n, k = II(), II()
    G = list([] for _ in range(n + 1))

    for _ in range(n - 1):
        u, v = II(), II()
        G[u].append(v)
        G[v].append(u)

    if k == 1:
        out.append("1")
        return

    sz = [0] * (n + 1)
    S2 = 0          # k=2 用
    S3 = 0          # k=3 用

    def dfs(u, fa):
        nonlocal S2, S3
        sz[u] = 1
        for v in G[u]:
            if v == fa:
                continue
            dfs(v, u)
            sz[u] += sz[v]
            s = sz[v]
            t = n - s

            # k=2 的边贡献
            S2 += s * t

            # k=3 的边贡献：1个在一侧，2个在另一侧
            if s >= 1 and t >= 2:
                S3 += s * (t * (t - 1) // 2)
            if s >= 2 and t >= 1:
                S3 += (s * (s - 1) // 2) * t

    dfs(1, 0)

    if k == 2:
        den = n * (n - 1) % mod
        inv = pow(den, mod - 2, mod)
        ans = (1 + 2 * S2 % mod * inv) % mod
        out.append(str(ans))
        return

    if k == 3:
        den = n * (n - 1) * (n - 2) // 6
        ans = (1 + S3 / den)  # 这里只是思路表达，下面要改成模意义
        # 模运算版：
        denm = den % mod
        inv = pow(denm, mod - 2, mod)
        ans = (1 + S3 % mod * inv) % mod
        out.append(str(ans))
        return

main()

print('\n'.join(map(str, out)))
