import sys
input = lambda: sys.stdin.readline().strip()
# it = map(int, sys.stdin.read().split())
# II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n = int(input())
    mp = {'R': 1, 'Y': 2, 'G': 3, 'B': 4}
    pos = {1: set(), 2: set(), 3: set(), 4: set()}
    f = 1
    for _ in range(4 * n):
        r, c = map(str, input().split())
        if f == 1:
            for i in range(mp[c] + 1, 5):
                for rank in pos[i]:
                    if rank != r:
                        f = 0
                        break
                if f == 0:
                    break
        pos[mp[c]].add(r)
    out.append('YES' if f else 'NO')

for _ in range(int(input())):
    main()

print('\n'.join(map(str, out)))
