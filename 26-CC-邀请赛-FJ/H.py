import sys
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, m = II(), II()
    A = (n + 2) // 3
    A = A - (n - m + 2) // 3

    B = fmin((n + 9) // 10, m // 6)

    out.append(f'{A} {B}')  

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
