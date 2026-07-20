from collections import Counter
import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, p, k = II(), II(), II()
    a = list(II() for i in range(n))
    mp = Counter()
    ans = 0
    for x in a:
        cur = ( pow(x, 4) - (x * k) ) % p
        ans += mp[cur]
        mp[cur] += 1
    out.append(ans)

main()

print('\n'.join(map(str, out)))
