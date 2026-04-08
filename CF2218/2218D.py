from math import gcd
import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)

def main():
    n = II()
    a = [1] * (n + 1)
    p, k = 1, n + 1
    while p <= n:
        a[p] = k
        k -= 1
        p += 2
    p = (n - 1 if n & 1 else n)
    while p >= 2:
        a[p] = k
        k -= 1
        p -= 2
    ans = list()
    for i in range(n):
        ans.append(a[i] * a[i + 1])
    print(*ans)

for _ in range(II()):
    main()
