import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, k = II(), II()
    a = [II() for _ in range(n)]
    
    cnt = [0] * (n + 2)
    for x in a:
        cnt[x] += 1
    
    tree = [0] * (n + 2)
    
    def add(i, delta):
        while i <= n:
            tree[i] += delta
            i += i & -i
    
    def qry(i):
        s = 0
        while i > 0:
            s += tree[i]
            i -= i & -i
        return s
    
    def range_qry(l, r):
        if l > r:
            return 0
        return qry(r) - qry(l - 1)
    
    isok = [0] * (n + 2)
    f = 0
    
    for v in range(n, 0, -1):
        if cnt[v] == 0:
            continue
        
        l = v + 1
        r = v + k
        if r > n:
            r = n
        if range_qry(l, r) > 0:
            isok[v] = 1
        
        if isok[v] or ((cnt[v] - 1) & 1):
            f = 1
        
        if not isok[v] and (cnt[v] & 1):
            add(v, 1)
    
    out.append("YES" if f else "NO")

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))