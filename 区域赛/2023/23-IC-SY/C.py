import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    x, y = II(), II()
    if (x, y) == (0, 0):
        out.append(4)
    elif (x, y) == (1, 0):
        out.append(3)
    elif (x, y) == (2, 0):
        out.append(2)
    elif (x, y) == (0, 1):
        out.append(4)
    elif (x, y) == (1, 1):
        out.append(3)
    elif (x, y) == (2, 1):
        out.append(2)
    elif (x, y) == (0, 2):
        out.append(6)
    elif (x, y) == (1, 2):
        out.append(4)
    else:
        out.append(2)


main()

print('\n'.join(map(str, out)))
