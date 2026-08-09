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

    old = [0] * (n + 1)
    cnt = [0] * (q + 2) 
    bit = [0] * (1 << 20)
    
    offset = [1 << k for k in range(20)]
    mask = [(1 << k) - 1 for k in range(20)]
    
    add = 0
    ans = 0
    
    for _ in range(q):
        op = II()
        if op == 1:
            x = II()
            last = old[x]
            if last <= add:
                nv = add + 1
                old[x] = nv
                cnt[nv] ^= 1
                for k in range(20):
                    bit[offset[k] + (nv & mask[k])] ^= 1
                ans ^= 1 
            else:
                nv = last + 1
                old[x] = nv
                cnt[last] ^= 1
                cnt[nv] ^= 1
                for k in range(20):
                    m = mask[k]
                    o = offset[k]
                    bit[o + (last & m)] ^= 1
                    bit[o + (nv & m)] ^= 1
                ans ^= (last - add) ^ (nv - add)
        else:
            for k in range(20):
                if bit[offset[k] + (add & mask[k])]:
                    ans ^= offset[k]
            add += 1
            if cnt[add]:
                for k in range(20):
                    bit[offset[k] + (add & mask[k])] ^= 1
                    
        out.append(str(ans))

main()

print('\n'.join(map(str, out)))
