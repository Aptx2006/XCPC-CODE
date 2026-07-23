import sys, math
input = lambda: sys.stdin.readline().strip()
# it = map(int, sys.stdin.read().split())
# II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    s = input()
    mp = {}
    for i in range(len(s)):
        mp[s[i]] = i
    if mp['p'] < mp['z'] or mp['c'] < mp['e'] or mp['c'] < mp['p']:
        out.append('NO')
    else:
        out.append('YES')

for _ in range(int(input())):
    main()

print('\n'.join(map(str, out)))
