import sys
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())


fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, m = map(int, input().split())

for _ in range(int(input())):
    main()

print('\n'.join(map(str, out)))
