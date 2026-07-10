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
    D = II()
    a = list((II(), II()) for i in range(n))

    ev = []
    for s, t in a:
        r = t - D
        if r >= s:
            ev.append((s, 1))
            ev.append((r + 1, -1))

    if not ev:
        out.append('0')
        return

    ev.sort()
    cur = 0
    last = 1
    ans = 0
    i = 0
    m = len(ev)

    while i < m:
        x = ev[i][0]
        if x > last:
            ans += cur * (cur - 1) // 2 * (x - last)
            last = x
        while i < m and ev[i][0] == x:
            cur += ev[i][1]
            i += 1

    out.append(ans)


main()

print('\n'.join(map(str, out)))