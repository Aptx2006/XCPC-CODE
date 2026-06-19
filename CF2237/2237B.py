import sys
import heapq
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n = II()
    a = [II() for i in range(n)]
    b = [II() for i in range(n)]
    

    pos = sorted(range(n), key=a.__getitem__)
    pq = []
    p = 0
    rank = [0] * n 

    for j, val in enumerate(b, 1):
        while p < n and a[pos[p]] <= val:
            heapq.heappush(pq, pos[p])
            p += 1
        if not pq:
            out.append('-1')
            return
        idx = heapq.heappop(pq)
        rank[idx] = j

    bit = [0] * (n + 2)

    def add(i):
        while i <= n:
            bit[i] += 1
            i += i & -i

    def qry(i):
        s = 0
        while i > 0:
            s += bit[i]
            i -= i & -i
        return s

    ans = 0
    cnt = 0
    for r in rank:
        ans += cnt - qry(r)
        add(r)
        cnt += 1

    out.append(ans)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))