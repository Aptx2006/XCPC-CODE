import sys
from collections import Counter
input = lambda: sys.stdin.readline().strip()

def solve():
    mod = 676767677
    inf = 10**9
    n, m = map(int, input().split())
    a = list(map(int , input().split()))
  
    mp = [0] * (max(a + [0]) + 5)
    for x in a:
        mp[x] += 1
        
    pre = [0] * len(mp)
    for i in range(1, len(mp)):
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
    
for _ in range(int(input())):
    solve()
