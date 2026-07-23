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
    if n * 9 == m * 16:
        out.append('Yes')
    else:
        out.append('No')

main()

print('\n'.join(map(str, out)))
