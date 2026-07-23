import sys
# input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

MOD = 998244353

def main():
    n = II()
    G = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        u, v = II(), II()
        G[u].append(v)
        G[v].append(u)

    vis = [False] * (n + 1)
    stk = [n]
    vis[n] = True
    cnt = 0

    while stk:
        u = stk.pop()
        cnt += 1
        for v in G[u]:
            if not vis[v] and v < u:
                vis[v] = True
                stk.append(v)

    print(pow(2, cnt - 1, MOD))

for _ in range(II()):
    main()
