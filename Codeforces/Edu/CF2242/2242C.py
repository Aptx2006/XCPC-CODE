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
    k = II()
    a = [II() for i in range(n)]

    cnt = []
    cur = 1
    for i in range(1, n):
        if a[i] != a[i - 1]:
            cnt.append(cur)
            cur = 1
        else:
            cur += 1
    cnt.append(cur)

    cnt.sort()
    m = len(cnt)

    suf = [0] * (m + 1)
    for i in range(m - 1, -1, -1):
        suf[i] = suf[i + 1] + cnt[i]

    ans = 0
    for t in range(1, m + 1):         
        S = suf[m - t]               
        de = S - k
        if de % t != 0:
            continue
        D = de // t                

        if t < m:
            low = cnt[m - t - 1]      
            high = cnt[m - t] - 1       
        else:
            low = 0
            high = cnt[0] - 1

        if fmax(low, fmax(0, D)) <= high:
            ans += 1

    out.append(ans)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))