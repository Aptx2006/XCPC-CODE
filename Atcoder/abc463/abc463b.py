import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, x = II(), SI()
    G = [SI() for i in range(n)]
    j = ord(x) - ord('A')
    for i in range(n):
        if G[i][j] == 'o':
            out.append('Yes')
            return
    out.append('No')

main()

print('\n'.join(map(str, out)))
