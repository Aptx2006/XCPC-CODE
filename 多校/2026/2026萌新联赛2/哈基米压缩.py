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
    a = list((II(), II()) for i in range(n))
    pre = [0] * (n + 1)
    for i in range(1, n + 1):
        pre[i] = pre[i - 1] + a[i - 1][1]
    for _ in range(II()):
        x = II()
        l = 1
        r = n
        ans = 0
        while l <= r:
            mid = (l + r) >> 1
            if pre[mid] < x:
                l = mid + 1
            elif pre[mid] >= x and pre[mid - 1] < x:
                ans = mid
                break
            else:
                r = mid - 1
        out.append(a[ans - 1][0])    
        
main()

print('\n'.join(map(str, out)))
