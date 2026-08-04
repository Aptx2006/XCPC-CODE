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
    b = list(II() for _ in range(n))

    mp = Counter(b)               
    mp_ = sorted(mp)               
    k = len(mp_)

    if k == 0 or mp_[0] != 0:
        out.append("-1")
        return

    num = [mp[c] for c in mp_]

    if k == 1:
        out.append(" ".join(["1"] * n))
        return

    v = [0] * k
    last = 0
    for m in range(k - 1):
        dif = mp_[m + 1] - mp_[m]
        if dif % num[m] != 0:  
            out.append("-1")
            return
        val = dif // num[m]
        if val <= last:          
            out.append("-1")
            return
        v[m] = val
        last = val

    v[k - 1] = v[k - 2] + 1        

    mp = {mp_[m]: v[m] for m in range(k)}
    a = [mp[x] for x in b]
    out.append(" ".join(map(str, a)))
    
for i in range(II()):
    main()

print('\n'.join(map(str, out)))
