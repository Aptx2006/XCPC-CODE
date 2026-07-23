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
    n, q = II(), II()
    s = SI()
    pre = [0] * (n + 1)
    for i in range(2, n + 1):
        pre[i] = pre[i - 1] + int(s[i - 2] == s[i - 1])
    
    for _ in range(q):
        l, r, k = II(), II(), II()
        need = (pre[r] - pre[l] + 1) // 2
        out.append('YES' if need <= k else 'NO')

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))