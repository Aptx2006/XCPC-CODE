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
    if n == 2:
        out.append("1 2 1 2 2 1 1 2")
        return
        
    b1 = list(range(1, n + 1))
    
    b2 = b1[:]
    b3 = b1[1:] + b1[:1]
    b4 = b1[3 % n:] + b1[:3 % n]
    
    ans = b1 + b2 + b3 + b4
    out.append(" ".join(map(str, ans)))

for _ in range(II()):
    main()

print('\n'.join(out))