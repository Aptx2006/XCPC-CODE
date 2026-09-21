import math
import sys
#input = lambda: sys.stdin.readline().strip()

eps = 1e-8

def fun(a, b, c):
    res1 = res2 = 0.0 

    if a == 0:
        res1 = res2 = -c / b
        return res1, res2
    
    if b * b - 4 * a * c < 0:
        res1 = res2 = 0.0
        return res1, res2
    
    res1 = ( -b + math.sqrt(b * b - 4 * a * c) ) / (2 * a)
    res2 = ( -b - math.sqrt(b * b - 4 * a * c) ) / (2 * a)

    return res1, res2

for _ in range(int(input())):
    ans = 0
    w, x1, x2, yc, u, v = map(float, input().split())
    #print(w, x1, x2, yc, u, v)
    t1 = yc / v
    l = t1 * u + x1
    r = t1 * u + x2
    if l < 0 and r > 0:
        res1, res2 = fun(u * u - v * v, 2 * x1 * u, x1 * x1 + yc * yc)
        ans1 = 0.0
        if res1 > 0 and res2 > 0:
            ans1 = min(res1, res2)
        elif res1 > 0:
            ans1 = res1
        elif res2 > 0:
            ans1 = res2

        res1, res2 = fun(u * u - v * v, 2 * x2 * u, x2 * x2 + yc * yc)
        ans2 = 0.0
        if res1 > 0 and res2 > 0:
            ans2 = min(res1, res2)
        elif res1 > 0:
            ans2 = res1
        elif res2 > 0:
            ans2 = res2
        
        ans = (w - yc) / v
        if ans1 > 0 and ans2 > 0:
            ans += min(ans1, ans2)
        elif ans1 > 0:
            ans += ans1
        elif ans2 > 0:
            ans += ans2
    else:
        ans = w / v

    print("{:.9f}".format(ans))
