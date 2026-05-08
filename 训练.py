import sys
# input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

def main():
    n, s = II(), II()
    mn = mx = s
    for i in range(n):
        c = II()
        if c > mx:
            mx = (mx + c + 1) // 2
        else:
            mn = (mn + c + 1) // 2
    print(mx)

for _ in range(II()):
    main()
