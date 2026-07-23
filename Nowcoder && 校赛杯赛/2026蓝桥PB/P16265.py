import sys
input = lambda: sys.stdin.readline().strip()

n, q = map(int, input().split())
fa = list(range(n + 5))
a = [0] * (n + 5)
val = [0] * (n + 5)
add = [0] * (n + 5)

def find(x):
    fx = x
    path = []
    while fa[fx] != fx:
        path.append(fx)
        fx = fa[fx]
    for x in reversed(path):
        p = fa[x]
        add[x] += add[p]
        fa[x] = fx
    return fx

def union(x, y):
    fx = find(x)
    fy = find(y)
    if fx != fy:
        fa[fx] = fy
        add[fx] = val[fx] - val[fy]

for _ in range(q):
    op = list(map(int, input().split()))
    if op[0] == 1:
        union(op[1], op[2])
    elif op[0] == 2:
        a[op[1]] += op[2]
    elif op[0] == 3:
        val[find(op[1])] += op[2]
    else:
        root = find(op[1])
        print(a[op[1]] + val[root] + add[op[1]])
