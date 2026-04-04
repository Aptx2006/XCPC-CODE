import sys
from collections import Counter
input = lambda: sys.stdin.readline().strip()

def solve():
    mod = 676767677
    inf = 10**9
    n, m = map(int, input().split())
    a = list(map(int , input().split()))
    mp = Counter(a)
    pre = [0] * (m + 5)
    for i in range(1, m + 1):
        pre[i] = pre[i - 1] + mp[i - 1] 
    ans = 1
    a = [inf] + a + [inf]
    for i in range(1, n + 1):
        if not a[i]:
            continue
        tag = min(a[i - 1], a[i + 1])
        if tag >= a[i]:
            print(0)
            return
        if a[i] != tag + 1:
            ans = (ans * mp[a[i] - 1]) % mod
        else:
            ans = (ans * pre[a[i]]) % mod
    print(ans)
    
for _ in range(int(input())):
    solve()
