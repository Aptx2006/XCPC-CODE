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
    a = list(II() for i in range(n))
    mp = Counter(a)
        
    mx = k = 0
    for x, v in mp.items():
        if v > mx:
            mx = v
            k = x
            
    s = n - mx 
    ans = sum(a)
    if mx > s + 2:
        ans -= (mx - s - 2) * k
        
    out.append(ans)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
