import sys
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, k, p = II(), II(), II()
    mn = n * -p
    mx = -mn
    if k > mx or k < mn:
        out.append(-1)
    else:
        ans = (abs(k) + p - 1 ) // p
        out.append(ans)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
