import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n = II()
    a = [II() for i in range(n)]

    p1 = [0] * (n + 1)
    p2 = [0] * (n + 1)

    for i in range(n):
        if a[i] == 1:
            p1[i + 1] = p1[i] + 1
        else:
            p1[i + 1] = p1[i] - 1

        if a[i] == 3:
            p2[i + 1] = p2[i] - 1
        else:
            p2[i + 1] = p2[i] + 1

    mn = 10 ** 18
    ans = 0

    for y in range(2, n):
        x = y - 1
        if p1[x] >= 0:
            mn = fmin(mn, p2[x])
        if mn <= p2[y]:
            ans = 1
            break

    out.append("YES" if ans else "NO")

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))