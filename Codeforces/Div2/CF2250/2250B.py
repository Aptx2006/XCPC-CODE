import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, sz: a if a > sz else sz
fmin = lambda a, sz: a if a < sz else sz
out = []

def main():
    n = II()
    k = II()
    if k == n - 1:
        out.append("-1")
    else:
        sz = n - k             
        c0 = n // 2           
        c1 = n - c0            
        b1 = (sz + 1) // 2     
        b0 = sz // 2           
        res = []
        for j in range(sz):
            if j & 1:
                if j == 1:
                    res.append('0' * (c0 - b0 + 1))
                else:
                    res.append('0')
            else:
                if j == 0:
                    res.append('1' * (c1 - b1 + 1))
                else:
                    res.append('1')
        
        out.append("".join(res))

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
