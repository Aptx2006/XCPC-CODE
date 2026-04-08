# Problem: F - Make Bipartite 3
# Contest: AtCoder - AtCoder Beginner Contest 451
# URL: https://atcoder.jp/contests/abc451/tasks/abc451_f
# StartTime 2026-03-28 21:27:00
# Memory Limit: 1024 MB
# Time Limit: 4000 ms
# Coder:Aptx4869
# 
# Powered by CP Editor (https://cpeditor.org)
import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
input = sys.stdin.readline

def main():
    n, q = II(), II()

    fa = list(range(n + 1))
    Gx = [0] * (n + 1)       
    rank = [1] * (n + 1)     
    sz0 = [1] * (n + 1)     
    sz1 = [0] * (n + 1)     
    total = 0              
    isok = True              
    
    def find(u):
        if fa[u] == u:
            return u
        path = []
        while fa[u] != u:
            path.append(u)
            u = fa[u]
        for v in reversed(path):
            F = fa[v]
            fa[v] = u
            Gx[v] ^= Gx[F]
        return u

    res = []  
    for _ in range(q):
        if not isok:
            res.append("-1")
            continue 
        
        u, v = II(), II()
        ru = find(u)
        rv = find(v)

        if ru == rv:
            if Gx[u] == Gx[v]:
                isok = False
                res.append("-1")
            else:
                res.append(str(total))
        else:
            w = Gx[u] ^ Gx[v] ^ 1
            if rank[ru] > rank[rv]:
                fa[rv] = ru
                Gx[rv] = w
                if w:
                    a0, a1 = sz1[rv], sz0[rv]
                else:
                    a0, a1 = sz0[rv], sz1[rv]

                total -= min(sz0[ru], sz1[ru])
                total -= min(sz0[rv], sz1[rv])
                sz0[ru] += a0
                sz1[ru] += a1
                total += min(sz0[ru], sz1[ru])

                if rank[ru] == rank[rv]:
                    rank[ru] += 1
            else:
                fa[ru] = rv
                Gx[ru] = w
                if w:
                    a0, a1 = sz1[ru], sz0[ru]
                else:
                    a0, a1 = sz0[ru], sz1[ru]
                total -= min(sz0[ru], sz1[ru])
                total -= min(sz0[rv], sz1[rv])
                sz0[rv] += a0
                sz1[rv] += a1
                total += min(sz0[rv], sz1[rv])
                if rank[ru] == rank[rv]:
                    rank[rv] += 1
            res.append(str(total))
    
    print('\n'.join(res))

main()
