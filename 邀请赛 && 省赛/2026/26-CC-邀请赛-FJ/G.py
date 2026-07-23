import sys
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, m = II(), II()
    d = (n - 1) * (n - 2) // 2
    ans = pow(2, d, m)
    if ~n & 1:
        ans *= 2
    out.append(ans % m)

for _ in range(II()):   
    main()

print('\n'.join(map(str, out)))
