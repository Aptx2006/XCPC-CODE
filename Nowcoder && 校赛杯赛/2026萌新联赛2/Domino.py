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
    a = list(II() for i in range(n))
    r = a[0]
    i = 1
    ###############################
    while i < r and i < n: 
        r = fmax(r, a[i] + i)
        i += 1
    out.append(fmin(r, n))
        
main()

print('\n'.join(map(str, out)))
