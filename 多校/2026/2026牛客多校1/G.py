import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

ans = []
for i in range(1, 11):
    for j in range(1, 11):
        ans.append(' '.join(map(str, (i * 0.011, j * 0.011, ))))

def main():
    n = II()
    out.append(2 * n)
    for i in range(n):
        out.append(ans[i] + ' 0')
        out.append(ans[i] + ' 1')

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
