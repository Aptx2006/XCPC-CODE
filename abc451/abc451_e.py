# Problem: E - Tree Distance
# Contest: AtCoder - AtCoder Beginner Contest 451
# URL: https://atcoder.jp/contests/abc451/tasks/abc451_e
# StartTime 2026-03-28 21:02:43
# Memory Limit: 1024 MB
# Time Limit: 6000 ms
# Coder:Aptx4869
# 
# Powered by CP Editor (https://cpeditor.org)

import sys
from collections import deque

def main():
    data = sys.stdin.read().split()
    p = 0
    n = int(data[p])
    p += 1

    dis = [[0] * n for _ in range(n)]
    for i in range(n - 1):
        for k in range(n - i - 1):
            val = int(data[p])
            p += 1
            j = i + k + 1
            dis[i][j] = val
            dis[j][i] = val

    inf = float('inf')
    a = [inf] * n
    a[0] = 0
    fa = [-1] * n
    isin = [False] * n

    for _ in range(n):
        mn = inf
        u = -1
        for i in range(n):
            if not isin[i] and a[i] < mn:
                mn = a[i]
                u = i
        if u == -1:  
            print("No")
            return
        isin[u] = True

        for v in range(n):
            if not isin[v] and dis[u][v] < a[v]:
                a[v] = dis[u][v]
                fa[v] = u

    G = [[] for _ in range(n)]
    for v in range(1, n):
        u = fa[v]
        w = dis[u][v]
        G[u].append( (v, w) )
        G[v].append( (u, w) )

    dp = [[0] * n for _ in range(n)]
    for st in range(n):
        q = deque()
        q.append( (st, -1, 0) )  
        while q:
            u, p, d = q.popleft()
            dp[st][u] = d
            for v, w in G[u]:
                if v != p:
                    q.append( (v, u, d + w) )

    for i in range(n):
        for j in range(i + 1, n):
            if dis[i][j] != dp[i][j]:
                print("No")
                return

    print("Yes")

main()