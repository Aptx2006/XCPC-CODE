import sys
# input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

def main():
    n = II()
    a = [II() for _ in range(n)]
    
    ans = []
    f = False
    for i in range(n - 1, -1, -1):
        cur = -a[i] if f else a[i]
        if cur > 0:
            ans.append(i + 1)
            f = not f
            
    print(len(ans))
    print(*ans)

for _ in range(II()):
    main()
