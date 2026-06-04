import sys, math
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    x1, y1 = II(), II()
    r1 = II()
    x2, y2 = II(), II()
    r2 = II()
    dist = (x1 - x2) * (x1 - x2)  + (y1 - y2) * (y1 - y2) 
    if (r1 + r2) * (r1 + r2) >= dist:
        out.append('Yes')
    else:
        out.append('No')


for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
