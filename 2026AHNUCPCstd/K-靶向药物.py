import sys

MOD = 212370440130137957
base = 131

MX = 2*10**5
f = [1] * (MX+1)
for i in range(1, MX+1):
    f[i] = f[i-1] * base % MOD

class StrHash:
    __slots__ = 'hval'
    def __init__(self, s: str):
        n = len(s)
        hval = [0] * (n+1)
        for i, c in enumerate(s):
            hval[i+1] = (hval[i] * base + ord(c)) % MOD
        self.hval = hval

    def substr(self, i: int, l: int):
        return (self.hval[i+l] - self.hval[i] * f[l]) % MOD

import sys
s, t = sys.stdin.read().split()
m, n = len(s), len(t)
sh1 = StrHash(s)
sh2 = StrHash(t)

def check(l):
    if l > n:
        return True
    vis = set(sh2.substr(i, l) for i in range(n-l+1))
    for i in range(m-l+1):
        if sh1.substr(i, l) not in vis:
            return True
    return False

lo, hi = 1, m
while lo < hi:
    mid = (lo + hi) // 2
    if check(mid):
        hi = mid
    else:
        lo = mid + 1
print(lo)
