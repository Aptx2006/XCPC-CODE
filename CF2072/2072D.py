import sys
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n = II()
    a = list(II() for _ in range(n))
    dp1 = list([0] * (n) for i in range(n))
    dp2 = list([0] * (n) for i in range(n))
    mx = 0
    ans = (1, 1)
    for i in range(n):
        for j in range(i + 1, n):
            dp1[i][j] = dp1[i][j - 1] + (a[j] < a[i])
            dp2[i][j] = dp2[i][j - 1] + (a[j] > a[i])
        # print(a[i], dp1[i], dp2[i], sep = '\n', end = '\n\n')
        for j in range(i + 1, n):
            cur = dp1[i][j] - dp2[i][j]
            if mx < cur:
                mx = cur
                ans = (i + 1, j + 1)
    out.append(' '.join(map(str, ans)))

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
