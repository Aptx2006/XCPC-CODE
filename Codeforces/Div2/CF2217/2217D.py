import sys

input = lambda: sys.stdin.readline().strip()

def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    p = list(map(int, input().split()))
    
    p = [x - 1 for x in p]
    c = [0] * (k + 1)

    c[0] = sum(a[i] != a[i + 1] for i in range(p[0]))
    for i in range(1, k):
        c[i] = sum(a[j] != a[j + 1] for j in range(p[i - 1], p[i]))
    c[k] = sum(a[i] != a[i + 1] for i in range(p[-1], n - 1))
            
    cl = c[0] + (c[0] & 1)
    cr = c[k] + (c[k] & 1)

    k = sum(c) + (c[0] & 1) + (c[k] & 1)
    #if c[0] & 1 and c[k] & 1:
    #    k += 1
    ans = max(max(c), cl, cr, k // 2)
    print(ans)

for _ in range(int(input())):
    main()
