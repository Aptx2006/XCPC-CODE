import sys
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

import math

mod = 10**9 + 7
inv2 = pow(2, mod - 2, mod)
inv6 = pow(6, mod - 2, mod)

def getsq(x):
    x %= mod
    return x * (x + 1) * (2 * x + 1) * inv6 % mod

def rev(n, p):
    ans = 0
    while n > 0:
        ans = ans * p + n % p
        n //= p
    return ans % mod

def main():
    n, k = II(), II()
    ans = 0
    
    if n == 1:
        out.append((k - 1) % mod)
        return
    if k > n:
        ans = (k - n) * n % mod

    lim = fmin(k, n)
    B = math.isqrt(n + 1)

    p_lim = fmin(lim, B)
    for p in range(2, p_lim + 1):
        ans = (ans + rev(n, p)) % mod
        
    l = max(B + 1, 2)
    r = lim
    c = l
    while c <= r:
        q = n // c
        pp = fmin(r, n // q) if q > 0 else r
            
        cnt = (pp - c + 1) % mod
        s1 = (c + pp) * (pp - c + 1) * inv2 % mod
        s2 = (getsq(pp) - getsq(c - 1) + mod) % mod
        
        temp1 = n * s1 % mod
        temp2 = q * (s2 - cnt + mod) % mod
        
        ans = (ans + temp1 - temp2 + mod) % mod
        c = pp + 1
        
    out.append(ans)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
