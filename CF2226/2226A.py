mod = 676767677
import sys
input = lambda: sys.stdin.readline().strip()

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    for i in range(n):
        if a[i] != 1:
            ans += a[i]
        elif i != n - 1:
            continue
        else:
            ans += 1
    print(ans % mod)