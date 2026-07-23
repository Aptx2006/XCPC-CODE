from functools import cache
import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    x, y, xx = II(), II(), II()
    cx = [x]
    while cx[-1] > 0:
        cx.append(cx[-1] // xx)
    cy = [y]
    while cy[-1] > 0:
        cy.append(cy[-1] // xx)
    st = set(cx + cy)
    ans = abs(x - y)        
    for val in st:
        if val >= x:
            ans1 = val - x
        else:
            for i, v in enumerate(cx):
                if v <= val:
                    ans1 = i + (val - v)
                    break
        if val >= y:
            ans2 = val - y
        else:
            for i, v in enumerate(cy):
                if v <= val:
                    ans2 = i + (val - v)
                    break
        ans = fmin(ans, ans1 + ans2)

    out.append(ans)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))