import sys
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

def main():
    n = II()
    m = II()
    fa = list(range(n))
    rank = [0] * n

    def find(x):
        while fa[x] != x:
            fa[x] = fa[fa[x]]
            x = fa[x]
        return x

    def union(x, y):
        rx = find(x)
        ry = find(y)
        if rx == ry:
            return False
        if rank[rx] < rank[ry]:
            fa[rx] = ry
        else:
            fa[ry] = rx
            if rank[rx] == rank[ry]:
                rank[rx] += 1
        return True

    ans = 0
    op = []
    for _ in range(m):
        p = II()
        u = II() - 1
        v = II() - 1
        w = II()
        if p == 1:
            ans += w
            union(u, v)
        else:
            op.append((w, u, v))

    op.sort()
    for w, u, v in op:
        if union(u, v):
            ans += w
    print(ans)

for _ in range(1):
    main()
