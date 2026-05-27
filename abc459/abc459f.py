import sys
#input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)
sys.setrecursionlimit(1 << 20)

ans = []
def main():
    n = II()
    a = [II() for _ in range(n)]

    b = [a[i] - i for i in range(n)]
    stk = []
    for i in range(n):
        s = b[i]
        l = 1
        while stk:
            ss, ll = stk[-1]
            last = ss // ll 
            if ss % ll != 0:
                last += 1
            cur = s // l
            if last > cur:
                stk.pop()
                s += ss
                l += ll
            else:
                break
        stk.append((s, l))
        
    c = []
    for s, l in stk:
        val = s // l
        rem = s % l
        c.extend([val] * (l - rem))
        c.extend([val + 1] * rem)
        
    res = 0
    for i in range(n):
        res += (n - i) * (b[i] - c[i])
        
    ans.append(str(res))

for _ in range(II()):
    main()
print('\n'.join(ans))
