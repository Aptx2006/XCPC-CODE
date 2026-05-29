import sys
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

MOD = 10**9 + 7
N = 1005

C = [[0] * N for _ in range(N)]
for i in range(N):
    C[i][0] = 1
    for j in range(1, i + 1):
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD

fac = [1] * N
for i in range(1, N):
    fac[i] = fac[i - 1] * i % MOD

def comb(n, m):
    return C[n][m]

out = []

def main():
    n, k = II(), II()
    f = [0]*(n + 1)

    for i in range(n + 1):
        sum = 0
        for j in range(i + 1):
            sum += comb(n - j, j) * comb(n - i + j, i - j)
        f[i] = sum * fac[n - i] % MOD

    ans = 0
    for i in range(k, n + 1):
        if (i - k) & 1:
            ans -= comb(i, k) * f[i]
        else:
            ans += comb(i, k) * f[i]

    out.append(ans % MOD)

main()

print('\n'.join(map(str, out)))