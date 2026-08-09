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
    a = list(II() for i in range(n))
    mp = Counter(a)
    mx = 0
    for x, v in mp.items():
        mx = max(mx, v)
    out.append(n - mx)

main()

print('\n'.join(map(str, out)))
