import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, x, y = II(), II(), II()
    a = list(II() for i in range(n))
    if fmin(x, y) == 0:
        out.append('NO')
        return
    out.append('YES')
    ans = 0
    v = fmin(x, y)
    for x in a:
        ans += (x + v - 1) // v
    out.append(ans)
        
main()

print('\n'.join(map(str, out)))
