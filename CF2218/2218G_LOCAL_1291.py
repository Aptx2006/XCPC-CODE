import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
from collections import Counter

def solve():
    mod = 676767677
    inf = 10**9
<<<<<<< HEAD
    n, m = II(), II()
    a = [II() for _ in range(n)]
    mp = Counter(a)
    pre = [0] * (m + 5)
    for i in range(1, m + 1):
=======
    n, m = map(int, input().split())
    a = list(map(int , input().split()))
  
    mp = [0] * (max(a + [0]) + 5)
    for x in a:
        mp[x] += 1
        
    pre = [0] * len(mp)
    for i in range(1, len(mp)):
>>>>>>> cff8fcedf53d8de09bcacfbe22b4590854aaa6eb
        pre[i] = pre[i - 1] + mp[i - 1] 
        
    ans = 1
    a = [inf] + a + [inf]
    for i in range(1, n + 1):
        val = a[i]
        if not val:
            continue
        tag = min(a[i - 1], a[i + 1])
        if tag >= val:
            print(0)
            return
        if val != tag + 1:
            ans = (ans * mp[val - 1]) % mod
        else:
            ans = (ans * pre[val]) % mod
    print(ans)
    
for _ in range(II()):
    solve()
