import sys

input = sys.stdin.readline

n = int(input())
m = int(input())

need = {}

for _ in range(m):
    s, x = input().split()
    need[s] = n * int(x)

k = int(input())

for _ in range(k):
    s, y = input().split()
    if s in need:
        need[s] -= int(y)

ans = [(s, x) for s, x in need.items() if x > 0]
ans.sort()

if not ans:
    print("OK")
else:
    for s, x in ans:
        print(s, x)