import sys
input = lambda: sys.stdin.read().strip()
text = input().split()
P = 0
T = int(text[P])
P += 1
for _ in range(T):
    n,k,x = int(text[P]),int(text[P+1]),int(text[P+2])
    P += 3
    a = list(map(int, text[P:P+n]))
    P += n
    a.sort()
    def isok(mid):
        if mid == 0:
            return (x+1) >= k
        pos = []
        for ai in a:
            l = max(0, ai - (mid - 1))
            r = min(x, ai + (mid - 1))
            if l <= r:
                pos.append((l, r))
        if len(pos) == 0:
            return (x + 1) >= k
        pos.sort()
        cnt = 0
        cl, cr = pos[0]
        for l,r in pos:
            if l <= cr + 1:
                cr = max(cr, r)
            else:
                cnt += cr - cl + 1
                cl, cr = l, r
        cnt += cr - cl + 1
        ans = (x + 1) - cnt
        return ans >= k
        
    l,r,res = 0,x+1,0
    while l <= r:
        mid = (l+r) // 2
        if isok(mid):
            res,l = mid,mid + 1
        else:
            r = mid - 1
    ans = []
    if res == 0:
        for i in range(k):
            ans.append(i)
    else:
        pos = []
        for ai in a:
            l = max(0, ai - (res - 1))
            r = min(x, ai + (res - 1))
            if l <= r:
                pos.append( (l, r) )
        pos.sort()
        b = []
        if pos:
            cl, cr = pos[0]
            for l, r in pos:
                if l <= cr + 1:
                    cr = max(cr, r)
                else:
                    b.append((cl, cr))
                    cl, cr = l, r
            b.append((cl, cr))
        p = 0
        for l, r in b:
            while p <= l - 1 and len(ans) < k:
                ans.append(p)
                p += 1
            p = max(p, r + 1)
            if len(ans) >= k:
                break
        while len(ans) < k and p <= x:
            ans.append(p)
            p += 1
    for x in ans:
        print(x,end=' ')
    print('')
