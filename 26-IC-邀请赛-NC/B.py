import sys
input = lambda: sys.stdin.readline().strip()
# it = map(int, sys.stdin.read().split())
# II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n = int(input())
    mp = {'R': 1, 'Y': 2, 'G': 3, 'B': 4}
    a = []
    for i in range(4 * n):
        x, c = map(str, input().split())
        a.append( (mp[c], int(x)) )
    b = sorted(a, key = lambda x: (x[0], -x[1]))

    for i in range(4 * n):
        for j in range(4 * n - 1):
            if a[j][0] == a[j + 1][0] or a[j][1] == a[j + 1][1]:
                if a[j][0] > a[j + 1][0] or a[j][1] < a[j + 1][1]:
                    a[j], a[j + 1] = a[j + 1], a[j]
    #print(b)
    #print(a)
    if a == b:
        out.append('YES')
    else:
        out.append('NO')

for _ in range(int(input())):
    main()

print('\n'.join(map(str, out)))
