import sys
input = lambda: sys.stdin.readline().strip()
fmin = lambda x, y: x if x < y else y
fmax = lambda x, y: x if x > y else y

def main():
    n = int(input())
    a = list(map(int, input().split()))
    mn1 = mn0 = 10**9
    mx1 = mx0 = -1
    for x in a:
        if x & 1:
            mx1 = fmax(mx1, x)
            mn1 = fmin(mn1, x)
        else:
            mx0 = fmax(mx0, x)
            mn0 = fmin(mn0, x)
    ck1 = ck0 = -1
    for x in a:
        if x & 1:
            if ck1 > x and (mx0 == -1 or (ck1 > mx0 >= mn0 > x)):
                print('NO')
                return
            ck1 = fmax(x, ck1)
        else:
            if ck0 > x and (mx1 == -1 or (ck0 > mx1 >= mn1 > x)):
                print('NO')
                return
            ck0 = fmax(x, ck0)
    print('YES')

for _ in range(int(input())):
    main()