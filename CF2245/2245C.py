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
    B = 1 << n.bit_length()

    if k >= B:
        out.append("NO")
        return

    if n & (n - 1) == 0:          
        if k < n:
            out.append("NO")
            return
        #[n, 2n-1]
        if k == n:
            p = list(range(1, n)) + [0]
        else:
            x = k ^ n
            v = [0, x]
            s = set(v)
            p = [i for i in range(n) if i not in s] + v
        out.append("YES")
        out.append(" ".join(map(str, p)))
        return

    x = k ^ n

    if x < n:
        if x == 0:
            p = list(range(1, n)) + [0]
        else:
            v = [0, x]
            s = set(v)
            p = [i for i in range(n) if i not in s] + v
    else:
        H = 1 << (n.bit_length() - 1) 
        y = x ^ H
        if n & 1:                       
            v = [0, y, H]
        else:                           
            z = y ^ 1
            v = sorted([0, 1, z, H])  
        s = set(v)
        p = [i for i in range(n) if i not in s] + v

    out.append("YES")
    out.append(" ".join(map(str, p)))
    
for _ in range(II()):
    main()

print('\n'.join(map(str, out)))