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
    s = SI()
    n = len(s)
    ans = 0

    for c in range(n):
        diff = 0
        ans += 1 
        l, r = c - 1, c + 1
        while l >= 0 and r < n:
            if s[l] != s[r]:
                diff += 1
                if diff > 1:
                    break
            ans += 1
            l -= 1
            r += 1

    for c in range(n - 1):
        diff = 0
        l, r = c, c + 1
        while l >= 0 and r < n:
            if s[l] != s[r]:
                diff += 1
                if diff > 1:
                    break
            ans += 1
            l -= 1
            r += 1

    out.append(ans)

main()

print('\n'.join(map(str, out)))