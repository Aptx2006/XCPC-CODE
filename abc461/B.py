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
    ans = list([] for _ in range(n + 1))
    for i in range(n):
        for j in range(II()):
            ans[II()].append(i + 1)
    for i in range(1, n + 1):
        t = [len(ans[i])] + sorted(ans[i])
        out.append(' '.join(map(str, t)))
    

main()

print('\n'.join(map(str, out)))
