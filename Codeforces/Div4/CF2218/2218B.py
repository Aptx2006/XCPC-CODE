import sys
data = sys.stdin.buffer

for _ in range(int(data.readline())):
    a = list(map(int, data.readline().split()))
    ans = -sum(a) + 2 * max(a)
    print(ans)
