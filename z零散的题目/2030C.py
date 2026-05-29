import sys
input = lambda: sys.stdin.readline().strip()
# it = map(int, sys.stdin.read().split())
# II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n = int(input())
    s = input()
    s = '1' + s + '1'
    if s.count('11') > 0:
        out.append('YES')
    else:
        out.append('NO')

for _ in range(int(input())):
    main()

print('\n'.join(map(str, out)))
