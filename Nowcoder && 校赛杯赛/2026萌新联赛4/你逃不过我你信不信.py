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
    mod = 10000
    sum = 0
    x = 1
    limit = min(n, 19) 
    for i in range(1, limit + 1):
        x = x * i % mod
        sum = (sum + x) % mod
    out.append(f"{sum:04d}")

main()

print('\n'.join(map(str, out)))
