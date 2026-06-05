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
    ans = ''
    if 'a' <= s[0] <= 'z':
        ans = s[0].upper() + s[1:]
    else:
        ans = s
    print(ans)

main()

print('\n'.join(map(str, out)))
