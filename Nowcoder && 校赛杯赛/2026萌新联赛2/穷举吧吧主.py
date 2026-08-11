#吃个午饭先
import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n = II()
    a = list(II() for i in range(n))
    a = [0] + a
    G = [[] for i in range(n + 5)]
    ans1 = ans2 = 0
    for _ in range(n - 1):
        u, v = II(), II()
        G[u].append((v, a[v]))
        G[v].append((u, a[u]))
        ans1 = max(ans1, (a[u] + a[v]) / 2)

    for i in range(1, n + 1):
        if len(G[i]) < 2:
            continue
        A = B = 0
        for (u, val) in G[i]:
            if val > A:
                B = A
                A = val
            elif val > B:
                B = val
        ans2 = max(ans2, (a[i] + A + B)  / 3)
    
    out.append("{0:.2f}".format(max(ans1, ans2)))


for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
