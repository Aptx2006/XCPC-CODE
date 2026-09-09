from collections import defaultdict
import sys

input = sys.stdin.readline

<<<<<<< HEAD
n = int(input())
m = int(input())

need = {}
=======
def main():
    n = II()
    b = list(II() for i in range(n))
    a = [1] * n
    mp = defaultdict(list)
    for i, x in enumerate(b):
        mp[x].append(i)
    b = sorted(set(b))
    lastans = 0
    if b[0] != 0:
        out.append(-1)
        return
    for i in range(1, len(b)):
        sz = len(mp[b[i - 1]])
        cur = b[i] - b[i - 1]
        ans = cur // sz
        if cur % sz != 0 or ans <= lastans:
            out.append(-1)
            return
        for j in mp[b[i - 1]]:
            a[j] = ans
        lastans = ans
    for j in mp[b[-1]]:
        a[j] = lastans + 1
    out.append(' '.join(map(str, a)))


for _ in range(II()):
    main()
>>>>>>> d5366e4a59a6146306aea65080b93488b1ce3605

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