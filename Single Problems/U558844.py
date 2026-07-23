import sys
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    mod = 998244353
    n = II()
    p = [II() for _ in range(n)]
    if p[-1] != 1:
        out.append(0)
        return
    ans = 1
    cnt = n - p[0]
    last = p[0]
    for x in p[1:]:
        if x > last:
            ans = 0
        elif x == last:
            ans = ans * cnt
            cnt -= 1
        else:
            cnt += last - x - 1
        ans %= mod
        last = x
    out.append(ans)
    
for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
