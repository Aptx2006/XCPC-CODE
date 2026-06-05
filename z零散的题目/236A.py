import sys
from collections import Counter
input = lambda: sys.stdin.readline().strip()
# it = map(int, sys.stdin.read().split())
# II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    s = input()
    mp = Counter(s)
    if ~len(mp) & 1:
        out.append('CHAT WITH HER!')
    else:
        out.append('IGNORE HIM!')

main()

print('\n'.join(map(str, out)))
