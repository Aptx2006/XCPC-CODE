import sys, math
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, d = II(), II()
    m = n // 2
    if d > m * m * 2:
        out.append('NO')
        return
    
    out.append('YES')
    
    add = lambda r1, c1, r2, c2: out.extend((f'{r1} {c1} {r2} {c2}', f'{r2} {c2} {r1} {c1}'))

    for i in range(1, m + 1):
        for j in range(1, m + 1):
            add(i, j, i + m, j + m)
            
    for i in range(1, m + 1):
        for j in range(m + 1, m * 2 + 1):
            add(i, j, i + m, j - m)

    if n & 1:
        out.extend((
            f'1 {n} {n} {n}',f'{n} {n} {n} 1',f'{n} 1 1 {n}'
        ))
        for i in range(2, n):
            add(i, n, n, n + 1 - i)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
