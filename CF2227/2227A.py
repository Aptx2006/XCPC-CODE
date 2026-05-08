import sys
input = lambda: sys.stdin.readline().strip()
# it = map(int, sys.stdin.read().split())
# II = lambda: next(it)

def main():
    n, m = map(int, input().split())
    if (n & 1) + (m & 1) <= 1:
        print('YES')
    else:
        print('NO')

for _ in range(int(input())):
    main()
