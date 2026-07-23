import sys
from heapq import heappush, heappop
input = lambda: sys.stdin.readline().strip()


fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n,k,d=map(int,input().split())
    p=list(map(int,input().split()))
    pq1=[]
    pq2=[]
    ans = 0
    for x in p:
        heappush(pq1,-(max(0, x - d)))
        ans += max(0, x - d)
        delta = x - max(0, x - d)
        heappush(pq2,delta)
    cnt = n // k
    for i in range(cnt):
        A = -heappop(pq1)
        b = []
        b_sum = 0
        if len(pq2) >= k - 1:
            for j in range(k - 1):
                b.append(heappop(pq2))
                b_sum+=b[-1]
            if A > b_sum:
                ans += b_sum - A
            else:
                break
    out.append(ans)

for _ in range(1):
    main()

print('\n'.join(map(str, out)))
