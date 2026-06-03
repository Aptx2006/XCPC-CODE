import sys
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, k = II(), II()
    a = [0] + list(II() for _ in range(n))
    if k == 1:
        if sum(a) & 1:
            out.append('Alice')
        else:
            out.append('Bob')
    else:
        i = 0
        while True:
            b = pow(2, i)
            if b > k:
                out.append('Bob')
                return
            s = sum(x // b for x in a)
            if s & 1:
                out.append('Alice')
                return
            i += 1                                        

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
