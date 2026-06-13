from collections import Counter
import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

MOD = 10 ** 9 + 7
N = 500000

spf = [0] * (N + 1)
pri = []
for i in range(2, N + 1):
    if spf[i] == 0:
        spf[i] = i
        pri.append(i)
    for p in pri:
        v = i * p
        if v > N:
            break
        spf[v] = p
        if p == spf[i]:
            break

def main():
    n, x = II(), II()
    a = [II() for i in range(n)]

    mp = Counter()
    for v in a:
        while v > 1:
            p = spf[v]
            c = 0
            while v % p == 0:
                v //= p
                c += 1
            mp[p] = mp[p] + c

    ans = 1
    for v in mp.values():
        ans = ans * (v + 1) % MOD

    out.append(ans)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))