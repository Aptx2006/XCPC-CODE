import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())

n = ii()
A = lii()
for i in range(n-2):
    x, y, z = A[i], A[i+1], A[i+2]
    if x.bit_length() == y.bit_length() == z.bit_length():
        exit(print(1))

pres = [0] * (n+1)
for i, x in enumerate(A):
    pres[i+1] = pres[i] ^ x

def get(l, r): return pres[r+1] ^ pres[l]

ans = n
for l1 in range(n):
    for r1 in range(l1, n):
        x = get(l1, r1)
        for l2 in range(r1+1, n):
            for r2 in range(l2, n):
                y = get(l2, r2)
                if x > y:
                    ans = min(ans, r1-l1+r2-l2)
print(ans if ans < n else -1)
