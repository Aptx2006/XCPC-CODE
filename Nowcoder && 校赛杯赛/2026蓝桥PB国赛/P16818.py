import sys
input = lambda: sys.stdin.readline().strip()


fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n,m,l,r = map(int,input().split())
    ans=-1
    L,R=1,n*m
    def isok(x):
        nonlocal n,m,l,r
        if m * x < n:
            return False
        mn = 0
        cnt=n
        for i in range(1,m+1):
            if cnt >= x:
                mn += x * i
                cnt-=x
            else:
                mn += cnt * i
                break
        cnt=n
        mx=0
        for i in range(m,0,-1):
            if cnt >= x:
                mx += x * i
                cnt -= x
            else:
                mx += cnt * i
                break
        if mx < l or mn > r:
            return False
        return True
    
    while L<=R:
        mid = (L+R)>>1
        if isok(mid):
            ans = mid
            R=mid-1
        else:
            L=mid+1
    out.append(ans)

for _ in range(1):
    main()

print('\n'.join(map(str, out)))
