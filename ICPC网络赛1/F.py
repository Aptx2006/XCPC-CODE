n, m = map(int, input().split())
a = [0] + list(sum(map(int, input().split())) for i in range(n))
ans = sum(int(a[i + 1] < a[i]) for i in range(n))
print(ans)
