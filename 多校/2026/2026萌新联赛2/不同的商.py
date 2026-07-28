import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, m = II(), II()
    l = 1
    ans = 0
    while l <= m:
        if l > n:   
            break
        val = n // l
        r = min(n // val, m)
        ans += val* (r - l + 1)
        l = r + 1
    out.append(ans)
    
main()

print('\n'.join(map(str, out)))
