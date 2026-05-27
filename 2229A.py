import sys
# input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

def main():
    n = II()
    a = [II() for _ in range(n)]
    print((max(a) - min(a) + 1) // 2)

for _ in range(II()):
    main()
