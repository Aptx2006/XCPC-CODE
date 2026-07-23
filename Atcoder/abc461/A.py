import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    s = SI()
    ans = ''
    for c in s:
        if '0' <= c <= '9':
            ans += c
    out.append(ans)

main()

print('\n'.join(map(str, out)))
