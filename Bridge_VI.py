import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n = II()
    m = II()
    a = list(II() for i in range(2 * n))
    a = [0] + a
    mn = a[1]
    mx = a[1] + m
    cnt = 0
    if a[2] > mx:
        cnt += 1
    for i in range(2, n + 1):
        ax = a[2 * i - 1]
        ay = a[2 * i]
        if ax > mx and ay > mx:
            cnt += 2
        elif ax > mx or ay > mx:
            cnt += 1
        elif ax + ay + m > 2 * mx:
            cnt += 1
    badcnt = 0
    if a[2] + m > mn:
        badcnt += 1
  
    for i in range(2, n + 1):
        ax = a[2 * i - 1]
        ay = a[2 * i]
        if ax + m > mn and ay + m > mn and ax + ay + m > 2 * mn:
            badcnt += 2
        elif ax + m > mn or ay + m > mn:
            badcnt += 1
    ans = str(cnt) + " " + str(badcnt)
    out.append(ans)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
