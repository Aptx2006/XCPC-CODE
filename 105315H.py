import sys
from heapq import heappush, heappop
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
out = []

def main():
    n, k = II(), II()
    a = list((II(), II()) for _ in range(n))
    id = list(range(n))
    id.sort(key = lambda x: a[x][1])
    pq = []
    ans = -10**18
    c = 0
    for i in id:
        if len(pq) == k - 1:
            ans = fmax(ans, c + a[i][0] - a[i][1])
        c += a[i][0]
        heappush(pq, a[i][0])
        if len(pq) == k:
            top = heappop(pq)
            c -= top

    out.append(ans)

for _ in range(II()):
    main()
    
print('\n'.join(map(str, out)))
