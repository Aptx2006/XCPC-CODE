import sys
input = lambda: sys.stdin.readline().strip()

import math

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    p = a[0]
    for x in a[1:]:
        if p != x and min(p, x) % math.fabs(p - x) == 0:
            ans += 1
        p = x
    print(ans)