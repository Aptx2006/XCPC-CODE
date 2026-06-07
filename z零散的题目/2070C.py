import sys
input = lambda: sys.stdin.readline().strip()

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, k = map(int, input().split())
    s = input()
    a = list(map(int, input().split()))
    
    l, r = 0, 10**9
    ans = -1
    
    def isok(d):
        last = 'R'
        cnt = 0
        for i in range(n):
            if a[i] > d:
                if s[i] == 'B' and last != 'B':
                    cnt += 1
                last = s[i]
        return cnt <= k
    
    while l <= r:
        mid = (l + r) // 2
        if isok(mid):
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    out.append(ans)

for _ in range(int(input())):
    main()

print('\n'.join(map(str, out)))
