import sys,math
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
T = II()
for _ in range(T):
    n = II()
    arr = [II() for _ in range(n)]
    ans = -1
    for x in range(2,100):
        for y in arr:
            if(math.gcd(x,y)==1):
                ans = x
                break
        if(ans!=-1):
            break
    print(ans)
