import sys
from collections import defaultdict
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n = II()
    e, m, id = II(), II(), II()
    a = [0] + list(II() for i in range(n))

    G = list([] for _ in range(n + 1))
    for _ in range(e):
        u, v = II(), II()
        G[u].append(v)
        G[v].append(u)
        
    b = list(II() for i in range(m))

    st = set(G[id])
    
    fa = list(range(n + 1))
    info = [[i] if i in st else [] for i in range(n + 1)]
    
    def find(x):
        while x != fa[x]:
            fa[x] = fa[fa[x]]
            x = fa[x]
        return fa[x]

    def union(x, y):
        fx = find(x)
        fy = find(y)
        if fx != fy:
            if len(info[fx]) < len(info[fy]):
                fx, fy = fy, fx
            fa[fy] = fx
            info[fx] += info[fy]
            info[fy] = []

    A = defaultdict(list)
    B = defaultdict(list)
    
    for i in range(1, n + 1):
        if i != id:  
            A[a[i]].append(i)
            
    for x in b:
        B[a[x]].append(x)
        
    vis = [False] * (n + 1)  
    isok = [False] * (n + 1)     
    
    v = sorted(set(A.keys()).union(B.keys()))
    
    for val in v:
        for u in A[val]:
            isok[u] = True
            for v in G[u]:
                if v != id and isok[v]:
                    union(u, v)
                    
        root = set()
        for s in B[val]:
            f = find(s)
            if f not in root:
                root.add(f)
                for x in info[f]:
                    vis[x] = True
                info[f] = []
                    
    ans = 0
    for x in st:
        if vis[x]:
            ans += 1
            
    out.append(ans)

main()

print('\n'.join(map(str, out)))
