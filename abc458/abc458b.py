n, m = map(int, input().split())
k = 4
for i in range(n):
    for j in range(m):
        d = (i == 0) + (i == n - 1) + (j == 0) + (j == m - 1)
        print(k - d, end = ' ')
    print('')
