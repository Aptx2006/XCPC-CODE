import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

class DSU:
    __slots__ = ('fa', 'sz')
    def __init__(self, n):
        self.fa = list(range(n))
        self.sz = [1] * n
    def find(self, x):
        while self.fa[x] != x:
            self.fa[x] = self.fa[self.fa[x]]
            x = self.fa[x]
        return x
    def union(self, a, b):
        a = self.find(a)
        b = self.find(b)
        if a == b:
            return False
        if self.sz[a] < self.sz[b]:
            a, b = b, a
        self.fa[b] = a
        self.sz[a] += self.sz[b]
        return True

def main():
    n, x, y = II(), II(), II()
    p = [II() for _ in range(n)]

    dsu = DSU(n + 1)

    for i in range(1, n + 1):
        if i + x <= n:
            dsu.union(i, i + x)
        if i + y <= n:
            dsu.union(i, i + y)

    ok = True
    for i in range(1, n + 1):
        if dsu.find(i) != dsu.find(p[i - 1]):
            ok = False
            break

    out.append("YES" if ok else "NO")

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))