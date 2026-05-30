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
    for i in range(n):
        m = fmin(x, i + 1)
        if u[i] == 'I':
            for k in range(m, 0, -1):
                if dp[k - 1] != -1:
                    dp[k] = fmax(dp[k], dp[k - 1])
        elif u[i] == 'E':
            for k in range(m, -1, -1):
                if dp[k] != -1 and dp[k] + 1 <= k * (s - 1):
                    dp[k] = dp[k] + 1
        else:
            for k in range(m, -1, -1):
                ans = dp[k]
                if k > 0 and dp[k - 1] != -1:
                    ans = fmax(ans, dp[k - 1])
                if dp[k] != -1 and dp[k] + 1 <= k * (s - 1):
                    ans = fmax(ans, dp[k] + 1)
                dp[k] = ans
                
    ans = 0
    for k in range(x + 1):
        if dp[k] != -1:
            ans = fmax(ans, k + dp[k])
    out.append(ans)

for _ in range(int(input())):
    main()

print('\n'.join(map(str, out)))

