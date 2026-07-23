import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, k = II(), II()
    a = [(II(), II()) for i in range(n)]
    a.sort(key = lambda x: x[1])
    L, R = 1, 10**9
    ans = -1

    def isok(x):
        cnt = 0
        last = -1
        for (l, r) in a:
            if last == -1 or l - last >= x:
                cnt += 1
                last = r
        return cnt >= k
    
    while L <= R:
        mid = (L + R) // 2
        if isok(mid):
            ans = mid
            L = mid + 1
        else:
            R = mid - 1
    out.append(ans)


main()

print('\n'.join(map(str, out)))
