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
    a = [II() for i in range(n)]
    mx = 0
    for i in range(n - 1):
        for j in range(i + 1, n):
            if a[j] > a[i]:
                mx += a[j] - a[i]
                a[j] = a[i]
                break
    out.append(sum(a))
 
for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
