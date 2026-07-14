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
    a = [(II(), II()) for i in range(n)]
    a.sort(key = lambda x: -x[1])
    m = II()
    qry = [(II(), i) for i in range(m)]
    qry.sort(key = lambda x: -x[0])
    ans = [0] * m
    i = j = 0
    mx = 0
    # print(a)
    # print(qry)
    while j < m:
        while i < n and a[i][1] > qry[j][0]:
            mx = fmax(a[i][0] ,mx)
            i += 1
        ans[qry[j][1]] = mx
        j += 1
    out.extend(ans)


main()

print('\n'.join(map(str, out)))
