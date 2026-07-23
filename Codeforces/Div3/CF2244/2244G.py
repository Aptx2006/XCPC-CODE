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

class BIT:
    __slots__ = ('n', 'tr')
    def __init__(self, n):
        self.n = n
        self.tr = [0] * (n + 1)
    def upd(self, i, val):
        n, tr = self.n, self.tr
        while i <= n:
            if val > tr[i]:
                tr[i] = val
            i += i & -i
    def qry(self, i):
        res = 0
        tr = self.tr
        while i:
            if tr[i] > res:
                res = tr[i]
            i -= i & -i
        return res

def main():
    n = II()
    a = list(II() for _ in range(n))
    G = [[] for _ in range(n + 2)]

    for j in range(1, n + 1):
        t = j + a[j - 1] + 1
        if t <= n:
            G[t].append(j)
    
    bit = BIT(n)
    dp = [0] * (n + 1)
    
    for i in range(1, n + 1):
        for j in G[i]:
            bit.upd(j, dp[j])
        m = i - a[i - 1] - 1
        add = 0
        if m > 0:
            add += bit.qry(m)
        dp[i] = a[i - 1] + add
    
    out.append(max(dp))

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))