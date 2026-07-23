from collections import Counter
import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []


def main():
    n = II()
    a = [II() for _ in range(n)]
    b = [II() for _ in range(n)]
    mx_a, mn_a = max(a), min(a)
    mx_b, mn_b = max(b), min(b)

    if mx_b > mx_a or mn_b < mn_a:
            out.append(-1)
            return
            
    ans = sum(abs(a[i] - b[i]) for i in range(n))
        
    up = [i for i in range(n) if a[i] < b[i]]  
    down = [i for i in range(n) if a[i] > b[i]]  
    
    if not up or not down:
        out.append(ans)
        return
        
    up_mx = max(b[i] for i in up)
    down_mn = min(b[i] for i in down)
    
    if up_mx <= down_mn:
        out.append(ans)
        return
        
    f1 = any(min(a[i], b[i]) >= up_mx for i in range(n))
    f2 = any(max(a[i], b[i]) <= down_mn for i in range(n))
    if f1 and f2:
        out.append(ans)
        return
        
    ct1 = sum(1 for x in a if x >= up_mx)
    ct2 = sum(1 for x in a if x <= down_mn)
    if ct1 > 1 or ct2 > 1:
        out.append(ans)
        return
        
    if n == 2:
        out.append(-1)
        return
            
    add = 10**18
    for i in range(n):
        if a[i] >= up_mx or a[i] <= down_mn:
            continue
        cur1 = 2 * max(0, up_mx - max(a[i], b[i]))
        cur2 = 2 * max(0, min(a[i], b[i]) - down_mn)
        add = fmin(add, fmin(cur1, cur2))
            
    out.append(ans + add)


for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
