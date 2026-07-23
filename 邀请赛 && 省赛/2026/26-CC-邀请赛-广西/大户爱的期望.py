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
    n = II()
    ans = -1
    s = 0
    for i in range(n, 1, -1):
        s += 1 / i
        ans = fmax(ans, i * s - (i - 1))
    ans /= n
    print('%.6f'%ans)


for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
