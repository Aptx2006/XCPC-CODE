import sys


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