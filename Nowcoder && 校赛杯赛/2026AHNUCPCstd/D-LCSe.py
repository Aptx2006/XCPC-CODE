import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
a = list(map(int, input().split()))

print(*a[::-1])
