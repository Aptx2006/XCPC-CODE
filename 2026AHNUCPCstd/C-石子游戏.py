import sys
input = lambda: sys.stdin.readline().strip()

for _ in range(int(input())):
    n, m, k = map(int, input().split())
    z = (n - 1) % ((k + 1) // 2 * (m + 1) + 1)
    print('Alice' if z % (m + 1) or not z else 'Bob')
