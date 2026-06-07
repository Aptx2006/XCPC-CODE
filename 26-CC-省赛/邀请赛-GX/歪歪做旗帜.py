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
    s = SI()
    mp = Counter(s)
    out.append(min(mp['G'], mp['X'], mp['C'] // 2, mp['P']))

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
