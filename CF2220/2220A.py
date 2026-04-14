import sys
from collections import Counter
#input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

def main():
    n = II()
    a = list(II() for _ in range(n))
    mp = Counter(a)
    if max(mp.values()) > 1:
        print(-1)
    else:
        print(*sorted(a, reverse = True))

for _ in range(II()):
    main()