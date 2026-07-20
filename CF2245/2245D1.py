import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, m = II(), II()
    G = [[0] * n for _ in range(n)]
    for _ in range(m):
        o, i, j = II(), II() - 1, II() - 1
        G[i][j] = G[j][i] = o

    o1 = [] #非负
    o2 = [] #负数

    for i in range(n):
        if G[i][i] == 1:
            o1.append(i)
        else:
            o2.append(i)

    for i in range(n):
        for j in range(i, n):
            if G[i][i] == G[j][j]:
                if G[i][i] != G[i][j]:
                    out.append("NO")
                    return

    #每个负数 产生的非负
    mp = [0] * n
    for i in o2:
        for j in o1:
            mp[i] += int(G[j][i] == 1)

    ans = [0] * n
    o2.sort(key=lambda i: -mp[i])
    for x, i in enumerate(o2, 1):
        ans[i] = -x
    #print(ans)

    #每个非负数 加上负数后 产生的非负
    mp2 = [0] * n
    for i in o1:
        for j in o2:
            mp2[i] += int(G[i][j] == 1)

    for i in o1:
        k = mp2[i]
        ans[i] = k
        for x, j in enumerate(o2):
            if x < k and G[i][j] != 1 or (x >= k and G[i][j] != 2):
                out.append("NO")
                return

    out.append("YES")
    out.append(" ".join(map(str, ans)))
    
for _ in range(II()):
    main()

print('\n'.join(map(str, out)))