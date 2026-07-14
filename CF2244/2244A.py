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
    n = II()
    s = SI()
    ct = ans = 0
    for x in s:
        if x == '#':
            ct += 1
        else:
            ans = fmax(ans, (ct + 1) // 2)
            ct = 0
    ans = fmax(ans, (ct + 1) // 2)
    out.append(ans)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))