import sys, math
input = lambda: sys.stdin.readline().strip()
# it = map(int, sys.stdin.read().split())
# II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    s1 = input().upper()
    s2 = input().upper()
    if s1 > s2:
        out.append(1)
    elif s1 < s2:
        out.append(-1)
    else:
        out.append(0)

main()

print('\n'.join(map(str, out)))
