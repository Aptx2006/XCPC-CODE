import sys
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, m = II(), II()
    a = list((II(), II()) for _ in range(m))
    l, r = 0, 10**9
    ans = 0

    def isok(x):
        nn = n
        for (r, c) in a:
            nn -= r * ( (c + x) // (x + 1) )
        #print(x, nn)
        return nn <= 0

    while l <= r:
        mid = (l + r) >> 1
        if isok(mid):
            l = mid + 1
            ans = mid
        else:
            r = mid - 1
    out.append(ans)

main()

print('\n'.join(map(str, out)))
