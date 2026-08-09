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
    for i in range(1, n + 1):
        if i % 3 == 0:
            out.append('Fizz')
        else:
            out.append(i)

main()

print('\n'.join(map(str, out)))
