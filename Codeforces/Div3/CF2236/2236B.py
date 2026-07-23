import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, k = II(), II()
    s = SI()
    isok = [0] * k
    for i, c in enumerate(s):
        if c == '1':
            isok[i % k] ^= 1
            
    if any(isok):
        out.append("NO")
    else:
        out.append("YES")

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))