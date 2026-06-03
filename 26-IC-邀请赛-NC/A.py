import sys
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    m, n = II(), II()
    if m % n == 0:
        out.append(1)
    else:
        out.append(0)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
