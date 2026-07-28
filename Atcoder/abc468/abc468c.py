import itertools
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
    p = tuple(II() for i in range(n))
    q = tuple(II() for i in range(n))
    st = list(itertools.permutations(p))
    ans = sum(p < v < q for v in st)    
    out.append(ans)

main()

print('\n'.join(map(str, out)))
