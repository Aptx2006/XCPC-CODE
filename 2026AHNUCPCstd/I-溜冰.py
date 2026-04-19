import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())

from collections import deque, defaultdict
from bisect import *
dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

def solve():
    n, sx, sy, tx, ty = mii()
    x2y = defaultdict(list)
    y2x = defaultdict(list)
    blocks = set()
    for _ in range(n):
        x, y = mii()
        x2y[x].append(y)
        y2x[y].append(x)
        blocks.add((x, y))
    if sx == tx and sy == ty:
        return 0
    if (sx, sy) in blocks or (tx, ty) in blocks:
        return -1
    if all((tx+dx, ty+dy) not in blocks for dx, dy in dirs):
        return -1
    for xs in y2x.values():
        xs.sort()
    for ys in x2y.values():
        ys.sort()

    dis = {(sx, sy): 0}
    q = deque([(sx, sy)])
    while q:
        st = q.popleft()
        x, y = st
        if x == tx and y == ty:
            return dis[st]
        nd = dis[st] + 1
        for d, (dx, dy) in enumerate(dirs):
            x2, y2 = x+dx, y+dy
            if (x2, y2) in blocks:
                continue
            if d == 0:
                arr = y2x[y]
                idx = bisect_left(arr, x)
                if idx < len(arr):
                    bx = arr[idx]
                    if (st := (bx-1, y)) not in dis:
                        dis[st] = nd
                        q.append(st)
            elif d == 1:
                arr = x2y[x]
                idx = bisect_left(arr, y)
                if idx < len(arr):
                    by = arr[idx]
                    if (st := (x, by-1)) not in dis:
                        dis[st] = nd
                        q.append(st)
            elif d == 2:
                arr = y2x[y]
                idx = bisect_right(arr, x) - 1
                if idx >= 0:
                    bx = arr[idx]
                    if (st := (bx+1, y)) not in dis:
                        dis[st] = nd
                        q.append(st)
            elif d == 3:
                arr = x2y[x]
                idx = bisect_right(arr, y) - 1
                if idx >= 0:
                    by = arr[idx]
                    if (st := (x, by+1)) not in dis:
                        dis[st] = nd
                        q.append(st)
    
    return -1

for _ in range(ii()):
    print(solve())
