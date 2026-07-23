import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())


fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

class BIT:
    def __init__(self, n):
        self.n = n
        self.tr = [0] * (n + 1)

    def upd(self, i, d):
        while i <= self.n:
            self.tr[i] += d
            i += i & (-i)
    
    def qry(self, i):
        res = 0
        while i > 0:
            res += self.tr[i]
            i -= i & (-i)
        return res
    
    def range_qry(self, l, r):
        return self.qry(r) - self.qry(l - 1)
    
class DSU:
    def __init__(self, n):
        self.fa = list(range(n))
        self.sz = [1] * n
    
    def find(self, x):
        while self.fa[x] != x:
            self.fa[x] = self.fa[ self.fa[x] ]
            x = self.fa[x]
        return x

    def union(self, x, y):
        fx, fy = self.find(x), self.find(y)
        if self.sz[fx] < self.sz[fy]:
            fx, fy = fy, fx
        self.fa[fy] = fx
        self.sz[fx] += self.sz[fy]



def main():
    n = II()

main()

print(' '.join(map(str, out)))
