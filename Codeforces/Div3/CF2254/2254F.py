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
    a = list(II() for _ in range(n))
    b = list(II() for _ in range(n))
    sa = sb = 0
    for v in a: 
        sa ^= v
    for v in b: 
        sb ^= v
    sx = sa ^ sb
    c1 = Counter([sx ^ x for x in b] + [sx])
    c2 = Counter(a + [0])
    out.append("YES" if c1 == c2 else "NO")
    
for i in range(II()):
    main()

print('\n'.join(map(str, out)))