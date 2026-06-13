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
    ans = 0
    while n <= m:
        n *= 3
        m *= 2
        ans += 1
    out.append(ans)

main()

print('\n'.join(map(str, out)))
