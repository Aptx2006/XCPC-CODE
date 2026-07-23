import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, c = II(), II()
    a = list(II() for _ in range(n))
    ans = sum(a) - n * c
    b = list(c - x for x in a if x < c)
    b.sort(reverse=True)
    ans += sum(b[:n // 2])
    out.append(ans)
    
for _ in range(II()):
    main()

print('\n'.join(map(str, out)))