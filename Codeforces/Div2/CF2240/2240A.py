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
    k = II()
    ans = 0
    p = 1
    while n > 0:
        if n >= k * p:
            n -= k * p
            ans += k
        else:
            ans += n // p
            break
        p <<= 1
    out.append(ans)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
