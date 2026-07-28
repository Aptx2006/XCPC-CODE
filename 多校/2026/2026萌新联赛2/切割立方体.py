import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    w, X, h = II(), II(), II()
    G = [[[1] * (h + 5) for _ in range(X + 5)] for i in range(w + 5)]
    for _ in range(II()):
        x1, y1, z1, x2, y2, z2 = II(), II(),II(), II(),II(), II()
        for x in range(x1, x2 + 1):
            for y in range(y1, y2 + 1):
                for z in range(z1, z2 + 1):
                    G[x][y][z] = 0 
    ans = 0
    for x in range(1, w + 1):
        for y in range(1, X + 1):
            for z in range(1, h + 1):
                ans += G[x][y][z]
    out.append(ans)

main()

print('\n'.join(map(str, out)))
