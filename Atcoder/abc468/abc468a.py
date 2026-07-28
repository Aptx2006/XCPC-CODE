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
    a = list(II() for i in range(n))
    out.append(sum(a[i] < a[i + 1] > a[i + 2] for i in range(n - 2)))

main()

print('\n'.join(map(str, out)))
