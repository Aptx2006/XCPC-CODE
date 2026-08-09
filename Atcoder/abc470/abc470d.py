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
    q = II()
    a = [0] + list(II() for i in range(n))
    b = [0] * (n + 1)
    
    for i in range(1, n + 1):
        b[a[i]] = i
        
    flag = True  
    
    for _ in range(q):
        op = II()
        if op == 1:
            x = II()
            y = II()
            if flag:
                u = a[x]
                v = a[y]
                a[x] = v
                a[y] = u
                b[v] = x
                b[u] = y
            else:
                u = b[x]
                v = b[y]
                b[x] = v
                b[y] = u
                a[v] = x
                a[u] = y
        else:
            flag = not flag
            
    if flag:
        ans = a[1:]
    else:
        ans = b[1:]
        
    print(' '.join(map(str, ans)))

main()

print('\n'.join(map(str, out)))
