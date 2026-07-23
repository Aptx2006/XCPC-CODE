import sys
from collections import Counter
#input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

def main():
    n = II()
    m = II()
    mx = cnt = 0
    lasta  = -1
    for i in range(n):
        ai = II()
        if ai == lasta:
            cnt += 1
        else:
            cnt = 1
        mx = max(mx, cnt)
        lasta = ai
    if mx >= m:
        print('NO')
    else:
        print('YES')

for _ in range(II()):
    main()