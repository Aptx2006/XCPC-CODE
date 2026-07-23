import sys
input = lambda: sys.stdin.readline().strip()
# it = map(int, sys.stdin.read().split())
# II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []


def main():
    l, d = map(int, input().split())
    t = list(map(int, input().split()))
    s = input()

    if 3 * d >= l:
        print(0)
        return

    inf = 10**18
    dp = [[inf] * 4 for _ in range(l + 1)]
    dp[0][0] = 0

    for i in range(1, l + 1):
        cost = t[int(s[i - 1])]
        for j in range(4):
            dp[i][j] = dp[i - 1][j] + cost
            if j > 0 and i >= d:
                if dp[i - d][j - 1] < dp[i][j]:
                    dp[i][j] = dp[i - d][j - 1]

    for j in range(1, 4):
        for x in range(max(0, l - d), l):
            if dp[x][j - 1] < dp[l][j]:
                dp[l][j] = dp[x][j - 1]

    out.append(min(dp[l]))

main()

print('\n'.join(map(str, out)))