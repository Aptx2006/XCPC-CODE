import sys
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, m = II(), II()
    mod = 10007
    a = [0] + [II() for _ in range(n)]
    c = [0] + [II() for _ in range(n)]
    mp1 = list([0] * 2 for _ in range(m + 5))
    mp2 = list([0] * 2 for _ in range(m + 5))
    for i in range(1, n + 1):
        mp1[c[i]][i & 1] += 1
        mp2[c[i]][i & 1] = mp2[c[i]][i & 1] + a[i]
    ans = 0
    for i in range(1, n + 1):
        ans += i * (mp2[c[i]][i & 1] - a[i]) + i * a[i] * (mp1[c[i]][i & 1] - 1)
    out.append(ans % mod)

main()

print('\n'.join(map(str, out)))
