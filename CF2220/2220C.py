import sys
from collections import Counter
#input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

def main():
    p = II()
    q = II()
    limit = (p + 2 * q) * 2 + 1
    i = 3
    while i * i <= limit:
        if limit % i == 0:
            n = (i - 1) // 2
            m = (limit // i - 1) // 2
            if q <= min( n * (m + 1) , m * (n + 1) ):
                print(n, m)
                return
        i += 2
    print(-1)

for _ in range(II()):
    main()