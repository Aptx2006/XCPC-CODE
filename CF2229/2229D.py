import sys
# input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

def main():
    n = II()
    a = [II() for _ in range(n)]
    b = [II() for _ in range(n)]

    l = 1
    r = 2*10**5
    ans = 1
    def isok(mid):
        cnt1 = 0
        cnt2 = 0
        f = False
        for i in range(n):
            if a[i] >= mid and b[i] >= mid:
                cnt1 += 1
                f = False
            elif a[i] < mid and b[i] < mid:
                if not f:
                    cnt2 += 1
                    f = True
        return cnt1 > cnt2
    
    while l <= r:
        mid = (l + r) // 2
        if isok(mid):
            ans = mid
            l = mid + 1
        else:
            r = mid - 1
            
    print(ans)

for _ in range(II()):
    main()
