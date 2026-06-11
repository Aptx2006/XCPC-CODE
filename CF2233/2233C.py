import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, k, s = II(), II(), SI()
    
    l = [0] * (n + 1)
    for i in range(n):
        l[i+1] = l[i] + (1 if s[i] == '(' else 0)
    r = [0] * (n + 1)
    for i in range(n - 1, -1, -1):
        r[i] = r[i+1] + (1 if s[i] == ')' else 0)
    mx = n + 1
    p = -1
    for i in range(n + 1):
        if l[i] + r[i] < mx:
            mx = l[i] + r[i]
            p = i
    
    need = fmin(mx, k)
    need1 = fmin(l[p], need)
    need2 = need - need1
    ans = ['0'] * n
    
    for j in range(p):
        if s[j] == '(' and need1 > 0:
            ans[j] = '1'
            need1 -= 1
            
    for j in range(p, n):
        if s[j] == ')' and need2 > 0:
            ans[j] = '1'
            need2 -= 1
            
    out.append("".join(ans))

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))