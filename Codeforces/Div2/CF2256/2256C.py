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
    k = II()
    s = SI()
    A = B = 0
    m = 2 * n
  
    for i in range(m):
        if s[i] == '1':
            id = (i + 1) % m
            if s[id] == '0':
                end = id
            else:
                end = i
    
            if end & 1:
                A += 1
            else:
                B += 1
              
    out.append(f"{A} {B}")


for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
