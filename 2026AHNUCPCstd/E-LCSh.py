import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())

n = ii()
A = [x-1 for x in mii()]
B = [x-1 for x in mii()]
mp = [0] * n
for i, x in enumerate(A):
    mp[x] = i
B = [mp[x] for x in B]

from bisect import bisect_left
def LIS_length(nums):
    lis = []
    for x in nums:
        idx = bisect_left(lis, x)
        if idx == len(lis):
            lis.append(x)
        else:
            lis[idx] = x
    return len(lis)

le = LIS_length(B)
if le == 1 or le == n:
    exit(print(-1))
off = 0
while True:
    C = list(range(n-1, -1, -1))
    for l in range(off, n, le):
        r = min(n - 1, l + le - 1)
        while l < r:
            C[l], C[r] = C[r], C[l]
            l += 1; r -= 1
    if C != B:
        break
    off += 1

C = [A[x] for x in C]
print(*(x + 1 for x in C))
