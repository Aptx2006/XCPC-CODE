import sys
input = lambda: sys.stdin.readline().strip()
# it = map(int, sys.stdin.read().split())
# II = lambda: next(it)

def main():
    n = int(input())
    s = input()
    if s.count('(') == s.count(')'):
        print('YES')
    else:
        print('NO')

for _ in range(int(input())):
    main()
