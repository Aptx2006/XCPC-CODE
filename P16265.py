import sys
input = lambda: sys.stdin.readline().strip()

n, q = map(int, input().split())
fa = [0] * (n + 5)
a = [0] * (n + 5)
add = [0] * (n + 5)

for i in range(n + 5):
    fa[i] = i

def find(x):
    global fa
    fx = fa[x]
    while fx != fa[fx]:
        fy = fa[fx]
        fx = fa[fy]
    fa[x] = fx
    return fx

def union(x, y):
    global fa, add
    fx = find(x)
    fy = find(y)
    addx = add[fx]
    if fx != fy:
        fa[fx] = fy
        add[fy] += addx
        add[fx] = 0

for _ in range(q):
    op = list(map(int, input().split()))
    if op[0] == 1:
        union(op[1], op[2])
        #print(find(op[1]), find(op[2]))
    elif op[0] == 2:
        a[ op[1] ] += op[2]
    elif op[0] == 3:
        add[ find(op[1]) ] += op[2]
    else:
        print(a[ op[1] ] + add[ find(op[1]) ])


