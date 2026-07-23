import sys
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []
a = [0, 0]
N = 2
while True:
    cur = N * (N - 1) // 2
    if cur > 10**5:
        break
    N += 1
    a.append(cur)

def main():
    k = II()
    ans = []
    x = y = 0
    for i in range(N - 1, -1, -1):
        while k != 0 and a[i] <= k:
            k -= a[i]
            for j in range(i):
                ans.append((j + x, y))
            x += i
            y += 1
    out.append(len(ans))
    ans = list(str(x) + ' ' + str(y) for (x, y) in ans)
    out.extend(ans)
            
    

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
