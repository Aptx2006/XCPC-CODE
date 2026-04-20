import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
sys.setrecursionlimit(10000)

def main():
    G = [[] for _ in range(505)]
    r = [[0] * 505 for _ in range(505)]
    ans = [0] * 1080
    l = m = 0

    n = II()
    for _ in range(n):
        x, y = II(), II()
        G[x].append(y)
        G[y].append(x)
        m = max(m, x, y)
        r[x][y] += 1
        r[y][x] += 1

    for i in range(1, m + 1):
        G[i].sort()

    def dfs(p):
        nonlocal l
        for v in G[p]:
            if r[p][v] > 0:
                r[p][v] -= 1
                r[v][p] -= 1
                dfs(v)
        l += 1
        ans[l] = p
    f = 0
    for i in range(1, m + 1):
        if len(G[i]) % 2:
            dfs(i)
            f = 1
            break
    
    if not f:
        for i in range(1, m + 1):
            if G[i]:
                dfs(i)
                break
    for i in range(l, 0, -1):
        print(ans[i])

main()
