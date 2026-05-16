s = input()
n = len(s)
ans = 0
for i in range(n):
    if s[i] == 'C':
        ans += min(i + 1, n - i)
print(ans)
