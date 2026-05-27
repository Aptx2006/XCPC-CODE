import sys
# input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

def main():
    n = II()
    a = [II() for _ in range(n)]
    
    suma, absa = sum(a), 0
    m = -1
    suf = sum(a)
    
    for i in range(n):
        suf -= a[i]
        if a[i] > 0:
            cur = absa - a[i] + suf
            if cur > suma:
                suma = cur
                m = i
        absa += abs(a[i])
        
    if m == -1:
        print(0)
        print()
    else:
        ans = []
        f = False
        for i in range(m - 1, -1, -1):
            cur = -a[i] if f else a[i]
            if cur > 0:
                ans.append(i + 1)
                f = not f
        ans.append(m + 1)
        print(len(ans))
        print(*ans)

for _ in range(II()):
    main()
