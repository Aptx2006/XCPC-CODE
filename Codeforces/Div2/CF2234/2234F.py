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
    h = [II() for _ in range(n)]
    h2 = h + h
    
    mx = h.index(max(h))
    hr = h2[mx + 1 : mx + 1 + n]
    
    F = [0] * n
    st = [n - 1]
    for i in range(n - 2, -1, -1):
        while st and hr[st[-1]] < hr[i]: 
            st.pop()
        F[i] = hr[i] * (st[-1] - i) + F[st[-1]]
        st.append(i)
        
    G = [0] * n
    st = []
    for i in range(n):
        while st and hr[st[-1]] < hr[i]: 
            st.pop()
        if st:
            G[i] = hr[i] * (i - st[-1]) + (G[st[-1]] if st[-1] != -1 else 0)
        else:
            G[i] = hr[i] * (i + 1)
        st.append(i)
        
    res = [0] * n
    for l in range(n):
        #tmp = h2[l : l + n]
        #pre = list(accumulate(tmp, max))
        #suf = list(accumulate(tmp[::-1], max))[::-1]
        #ans = sum(p if p < s else s for p, s in zip(pre, suf[1:]))
        res[(mx + 1 + l) % n] = F[l] + (G[l - 1] if l > 0 else 0)
        
    out.append(" ".join(map(str, res)))

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))