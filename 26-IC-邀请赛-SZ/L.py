import sys
input = lambda: sys.stdin.readline().strip()
fmax = lambda A, B : A if A > B else B
for _ in range(int(input())):
    n, m = map(int, input().split())
    a = [ [0, 0, 0] ]
    for i in range(n):
        a.append(list(map(int, input().split())))
    dp = list([0] * (m + 5) for _ in range(n + 5))
    a.sort(key = lambda A: A[1])
    for i in range(1, n + 1):
        p, v, w = a[i][0], a[i][1], a[i][2]
        for j in range(m, w - 1, -1):
            dp[i][j] = fmax(dp[i - 1][j], dp[i - 1][j - w] * (1 - p / 100) + p / 100 * v)
        for j in range(min(w, m + 1)):
            dp[i][j] = dp[i - 1][j]
    print(f"{max(dp[n]):.10f}")
