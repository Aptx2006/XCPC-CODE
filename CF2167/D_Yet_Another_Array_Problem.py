import sys,math
input = lambda:sys.stdin.readline().strip()
T = int(input())
for _ in range(T):
    n = int(input())
    arr = list(map(int,input().split()))
    ans = -1
    for x in range(2,100):
        for y in arr:
            if(math.gcd(x,y)==1):
                ans = x
                break
        if(ans!=-1):
            break
    print(ans)
