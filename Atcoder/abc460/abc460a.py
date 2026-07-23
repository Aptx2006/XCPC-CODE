import sys
input = lambda: sys.stdin.readline().strip()
# it = map(int, sys.stdin.read().split())
# II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, m = map(int, input().split())
    ans = 0
    while m:
        m = n % m
        ans += 1
    out.append(ans)

main()

print('\n'.join(map(str, out)))
