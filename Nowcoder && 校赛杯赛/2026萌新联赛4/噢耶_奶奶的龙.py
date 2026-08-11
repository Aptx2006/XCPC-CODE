import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    mod = 998244353
    ans = 3 * pow(7, mod - 2, mod)
    out.append(0)

main()

print('\n'.join(map(str, out)))
