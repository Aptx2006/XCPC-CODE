import sys
from collections import Counter
input = lambda: sys.stdin.readline().strip()
# it = map(int, sys.stdin.read().split())
# II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, x, s = map(int, input().split())
    u = input()
    
    dp = [-1] * (x + 1)
    dp[0] = 0
    k = cnt = 0
    
    for i in range(n):
        if u[i] == 'I':
            if k < x:
                dp[k + 1] = fmax(dp[k + 1], dp[k])
                k += 1
        elif u[i] == 'E':
            if dp[k] != -1 and dp[k] + 1 <= k * (s - 1):
                dp[k] = dp[k] + 1
            elif cnt > 0 and k < x:
                cnt -= 1
                dp[k + 1] = fmax(dp[k + 1], dp[k])
                k += 1
        else:
            if dp[k] != -1 and dp[k] + 1 <= k * (s - 1):
                dp[k] = dp[k] + 1
                cnt += 1
            elif k < x:
                dp[k + 1] = fmax(dp[k + 1], dp[k])
                k += 1
                
    ans = 0
    for i in range(x + 1):
        if dp[i] != -1:
            ans = fmax(ans, i + dp[i])
    out.append(ans)

for _ in range(int(input())):
    main()

print('\n'.join(map(str, out)))

