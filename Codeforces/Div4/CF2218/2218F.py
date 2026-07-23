import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)

def solve():
    x, y = II(), II()
    sum = x + y
    if sum & 1:
        if y <= x:
            print('NO')
        else:
            print('YES')
            k = 2
            for i in range(x):
                print(1, k)
                print(k, k + 1)
                k += 2
            while k <= sum:
                print(1, k)
                k += 1
    else:
        if y < x or not x:
            print('NO')
        else:
            print('YES')
            k = 2
            for i in range(x - 1):
                print(1, k)
                print(k, k + 1)
                k += 2
            while k <= sum:
                print(1, k)
                k += 1


for _ in range(II()):
    solve()
