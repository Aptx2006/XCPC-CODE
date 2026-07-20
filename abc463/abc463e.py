import sys
import heapq

input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.buffer.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, m, y = II(), II(), II()
    G = [[] for _ in range(n + 1)] 

    for _ in range(m):
        u, v, t = II(), II(), II()
        G[u].append((v, t))
        G[v].append((u, t))

    a = [0] + [II() for _ in range(n)]

    for i in range(1, n + 1):
        G[i].append((0, a[i]))
        G[0].append((i, a[i] + y))

    INF = 10 ** 18
    dis = [INF] * (n + 1)
    dis[1] = 0
    pq = [(0, 1)]

    while pq:
        d, u = heapq.heappop(pq)
        if d != dis[u]:
            continue
        for v, w in G[u]:
            nd = d + w
            if nd < dis[v]:
                dis[v] = nd
                heapq.heappush(pq, (nd, v))

    out.append(' '.join(map(str, dis[2:])))

main()

print('\n'.join(map(str, out)))