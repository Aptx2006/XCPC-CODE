import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, m = II(), II()
    a = [II() for _ in range(n)]
    b = [II() for _ in range(n - 1)]

    c = [(b[i] - a[i] - a[i + 1]) % m for i in range(n - 1)]

    d = [0] * n
    for i in range(n - 1):
        d[i + 1] = (c[i] - d[i]) % m

    val = sum(d) 
    ans = val

    o1 = (n + 1) // 2   
    o2 = n // 2      
    dis = o1 - o2

    v = []

    for i in range(n):
        if i % 2 == 0:
            if d[i] != 0:
                v.append((m - d[i], -m))
        else:
            if d[i] != m - 1:
                v.append((d[i] + 1, m))

    v.sort()

    last = 0
    p = 0

    while p < len(v):
        pos = v[p][0]
        cur = 0

        while p < len(v) and v[p][0] == pos:
            cur += v[p][1]
            p += 1

        gap = pos - last - 1
        if gap > 0:
            val += dis * gap
            ans = fmin(ans, val)

        val += dis + cur
        ans = fmin(ans, val)
        last = pos

    if last < m - 1:
        val += dis * (m - 1 - last)
        ans = fmin(ans, val)

    out.append(ans)


main()

print('\n'.join(map(str, out)))