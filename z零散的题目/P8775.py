import sys
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, x = II(), II()
    a = [II() for i in range(n - 1)]
    pre = [0] * (n + 1)
    for i in range(n - 1):
        pre[i + 1] = a[i] + pre[i]
    l, r = 1, n

    def isok(y):
        for i in range(y, n):
            if pre[i] - pre[i - y] < 2 * x:
                return False
        return True

    while l <= r:
        mid = l + r >> 1
        if isok(mid):
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    
    out.append(ans)

main()

print('\n'.join(map(str, out)))
