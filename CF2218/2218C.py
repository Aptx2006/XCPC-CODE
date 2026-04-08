import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)

def main():
    n = II()
    a = 1
    b = n + 1
    for i in range(1, 3 * n + 1):
        if i % 3 != 1:
            print(b, end = ' ')
            b += 1
        else:
            print(a, end = ' ')
            a += 1
    print('')


for _ in range(II()):
    main()
