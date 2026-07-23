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
    
    sz = len(set(a))
    
    cnt = 1
    for i in range(1, n):
        if a[i] != a[i-1]:
            cnt += 1
            
    if cnt == sz:
        out.append("YES")
        return
        
    mp1 = {}
    mp2 = {}
    for i in range(n):
        if a[i] not in mp1:
            mp1[a[i]] = i
        mp2[a[i]] = i
        
    st = set()
    bad1 = -1
    for i in range(n):
        if a[i] in st and a[i] != a[i-1]:
            bad1 = i
            break
        st.add(a[i])

    st = set()
    bad2 = -1
    for i in range(n - 1, -1, -1):
        if a[i] in st and i < n - 1 and a[i] != a[i+1]:
            bad2 = i
            break
        st.add(a[i])

    base = set()
    if bad1 != -1:
        base.add(bad1)
        base.add(bad1 - 1)
    if bad2 != -1:
        base.add(bad2)
        base.add(bad2 + 1)
    #for x in base:
    #    if x < 0 or x >= n:
    #        base.remove(x)
    base = {x for x in base if 0 <= x < n}
    
    st = set(base)
    for x in base:
        for idx in (x, x - 1, x + 1):
            if 0 <= idx < n:
                val = a[idx]
                for p in (mp1[val], mp2[val]):
                    st.update({p, p - 1, p + 1})
    #for x in st:
    #    if x < 0 or x >= n:
    #        st.remove(x)
    st = {x for x in st if 0 <= x < n}

    b = list(st)
    m = len(b)
    f = False
    
    for i in range(m):
        for j in range(i + 1, m):
            u = b[i]
            v = b[j]
            
            tst = {u, v}
            if u + 1 < n: 
                tst.add(u + 1)
            if v + 1 < n: 
                tst.add(v + 1)
            
            dif = 0
            for k in tst:
                if k > 0 and a[k] != a[k-1]:
                    dif += 1
            
            a[u], a[v] = a[v], a[u]
            
            add = 0
            for k in tst:
                if k > 0 and a[k] != a[k-1]:
                    add += 1
                    
            if cnt - dif + add == sz:
                f = True
                
            a[u], a[v] = a[v], a[u]
            if f:
                break
        if f:
            break
            
    out.append('YES' if f else 'NO')

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))