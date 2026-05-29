import sys
input = lambda: sys.stdin.readline().strip()
# it = map(int, sys.stdin.read().split())
# II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n = int(input())
    s = input()
    ct1 = s.count('-')
    ct2 = n - ct1
    ans = ct2 * (ct1 // 2) * (ct1 - ct1 // 2)
    out.append(ans)

for _ in range(int(input())):
    main()

print('\n'.join(map(str, out)))
