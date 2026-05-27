import sys
from collections import Counter
input = lambda: sys.stdin.readline().strip()
#it = map(int, sys.stdin.read().split())
#II = lambda: next(it)

ans = []
def main():
    s = input()
    n = len(s)
    mp = Counter(s)

    mx = max(y for x, y in mp.items())
    if mx > (n + 1) // 2:
        ans.append('No')
        return

    a = sorted(((v, k) for k, v in mp.items()), key=lambda x: (-x[0], x[1]))

    res = [''] * n
    pos = 0
    for c, ch in a:
        for _ in range(c):
            if pos >= n:
                pos = 1
            res[pos] = ch
            pos += 2
    ans.append('Yes')
    ans.append(''.join(res))

for _ in range(int(input())):
    main()
print('\n'.join(ans))
