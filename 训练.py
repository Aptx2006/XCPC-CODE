import sys
<<<<<<< HEAD


def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    if not data:
        return

    n = data[0]
    a = data[1:1 + n]

    min_value = max(a) - min(a)

    ways = 1 if min_value == 0 else 2

    print(ways, min_value)


if __name__ == '__main__':
    main()
=======
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
>>>>>>> 979334818d779a782710f1da9b1a801c88aab226
