import sys
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    G = list([] for _ in range(5))
    p = (0, 0)
    for i in range(5):
        G[i] = list(II() for j in range(5))
        for j in range(5):
            if G[i][j] == 1:
                p = (i, j)
    out.append(abs(p[0] - 2) + abs(p[1] - 2))

main()

print('\n'.join(map(str, out)))
