import sys
input = lambda: sys.stdin.readline().strip()
# it = map(int, sys.stdin.read().split())
# II = lambda: next(it)p()

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    a = [0] + arr
    k = [0] * (n + 3)
    for i in range(1, n + 1):
        k[a[i]] += 1
    for i in range(n, 0, -1):
        k[i] += k[i + 1]
    b = 0
    for i in range(1, n + 1):
        b += k[i] * n - k[i] * (k[i] - 1) // 2
        b -= i * a[i]
    m = 0
    for i in range(1, n + 1):
        d = i - n + k[a[i]] - 1
        if d > m:
            m = d
    print(b + m)

for _ in range(int(input())):
    main()
