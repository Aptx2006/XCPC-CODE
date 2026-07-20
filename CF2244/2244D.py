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
    n, m = II(), II()
    a = list(II() for i in range(n))
    b = list(II() for i in range(m))
    b.sort()
    ans = 0
    l = 0
    for r in b:
        sum_ = 0
        for i in range(l, r):
            sum_ += a[i]
        ans += abs(sum_)
        l = r
    ans += sum(a[l:n])
    out.append(ans)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))