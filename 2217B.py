import sys

input = lambda: sys.stdin.readline().strip()

def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    p = list(map(int, input().split()))
    m = p[0] - 1
    cl = sum(a[i] != a[i + 1] for i in range(m))
    cr = sum(a[i] != a[i + 1] for i in range(m, n - 1))
    
    ans = max(cl, cr)
    if ans & 1:
        ans += 1
    print(ans)

for _ in range(int(input())):
    main()
