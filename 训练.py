import sys
import itertools
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    a = [1, 2, 3]
    for p in itertools.combinations(a, 2):
        print(p)
 
main()

print('\n'.join(map(str, out)))
