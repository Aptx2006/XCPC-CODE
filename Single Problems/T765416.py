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
    d = list(II() for i in range(n - 1))
    t = list(II() for i in range(n))

    a = [0] * n
    for i in range(1, n):
        a[i] = a[i - 1] + d[i - 1]
        
    ans = 0
    L = 0
    while L < n:
        if not t[L]:
            R = L + 1
            while R < n and t[R] == 1:
                R += 1
            if R > L + 1 and R < n:
                for i in range(L + 1, R):
                    dif = a[i] - a[L]
                    good = (i - L) * (a[R] - a[L])
                    if dif * (R - L) != good:
                        ans += 1
            L = R
        else:
            L += 1
            
    out.append(ans)

main()

print('\n'.join(map(str, out)))
