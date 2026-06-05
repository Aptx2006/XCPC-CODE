import sys
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []


class BIT:
    def __init__(self, n):
        self.n = n
        self.tree = [0] * (n + 2)   

    def add(self, i, d):
        while i <= self.n:
            self.tree[i] += d
            i += i & -i

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s

    def range_sum(self, l, r):
        if l > r:
            return 0
        return self.sum(r) - self.sum(l - 1)



def main():
    n, m, x = II(), II(), II()
    a = [0] + [II() for _ in range(n)]  

    pre = [0] * (n + 1)
    mp = {}                
    for i in range(1, n + 1):
        tag = a[i] ^ x
        if tag in mp:
            pre[i] = mp[tag]
        mp[a[i]] = i

    pos = []
    for i in range(1, n + 1):
        if pre[i] > 0:
            pos.append((pre[i], i))

    qry = [(II(), II(), i) for i in range(m)]

    qry.sort(key = lambda q: -q[0])
    pos.sort(key = lambda p: -p[0])

    bit = BIT(n)
    ans = ['no'] * m
    p = 0
    for l, r, i in qry:
        while p < len(pos) and pos[p][0] >= l:
            _, right = pos[p]
            bit.add(right, 1)
            p += 1
        if bit.range_sum(l, r) > 0:
            ans[i] = 'yes'

    sys.stdout.write("\n".join(ans))

main()

print('\n'.join(map(str, out)))
