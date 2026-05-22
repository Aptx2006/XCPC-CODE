import sys
input = lambda: sys.stdin.readline().strip()

for _ in range(int(input())):
    n = int(input())
    s = input()
    print(n + sum(i * (s[i] != s[i - 1]) for i in range(1, n)))
