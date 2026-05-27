import sys
# input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

def main():
    n = II()
    a = [II() for _ in range(n)]
    b = [II() for _ in range(n)] 

    res = sum(max(x, y) for x, y in zip(a, b)) + max(min(x, y) for x, y in zip(a, b))
    print(res) 

for _ in range(II()):
    main()
