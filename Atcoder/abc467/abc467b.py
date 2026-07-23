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
    ans = 0
    for i in range(n):
        x, y = II(), II()
        s = SI()
        if s == 'keep':
            ans += y - x
    out.append(ans)

main()

print('\n'.join(map(str, out)))
