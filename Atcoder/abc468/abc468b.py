import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    m, d = II(), II()
    s = list(SI())
    id = []
    for i in range(m):
        if s[i] == 'G':
            id.append(i)
    for i in id:
        for j in range(max(0, i - d), min(m, i + d + 1)):
            s[j] = 'G'
    out.append(s.count('.'))

main()

print('\n'.join(map(str, out)))
