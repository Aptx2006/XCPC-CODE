import sys
from collections import Counter
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n = II()
    a = list(II() for _ in range(n))
    if any(a[i] >= i + 1 for i in range(n)):
        out.append("NO")
        return
    
    ans = []
    
    def dfs(x, st, to, fz): # 从st 去 to 借助 fz 辅助
        if x == 0:
            return
        if x == 1:
            ans.append(f"{x} {st} {to}")
            return
            
        req = a[x-1]
        k = x - 1 - req
        
        if k == x - 1:
            dfs(k, st, fz, to)
            ans.append(f"{x} {st} {to}")
            dfs(k, fz, to, st)
        else:
            dfs(k, st, fz, to)
            ans.append(f"{x} {st} {to}")
            dfs(k, fz, st, to)
            dfs(x - 1, st, to, fz)
            
    dfs(n, 1, 3, 2)
    out.append("YES")
    out.append(len(ans))
    out.extend(ans)
        

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))