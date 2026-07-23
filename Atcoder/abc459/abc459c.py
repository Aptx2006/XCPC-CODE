import sys
#input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

def main():
    n, q = II(), II()
    a =[0] * (n + 1)
    cnt = [0] * (q + 3)
    bit = [0] * (q + 3)

    def add(i, v):
        while i <= q + 2:
            bit[i] += v
            i += i & -i

    def ask(i):
        s = 0
        while i > 0:
            s += bit[i]
            i -= i & -i
        return s

    cnt[0] = n
    add(1, n)
    mn = 0
    g = 0
    ans = []
    for _ in range(q):
        op, x = II(), II()
        if op == 1:
            old = a[x]
            cnt[old] -= 1
            add(old + 1, -1)
            a[x] = old + 1
            cnt[old + 1] += 1
            add(old + 2, 1)
            if old == mn and cnt[mn] == 0:
                while cnt[mn] == 0:
                    mn += 1
            if mn >= g + 1:
                g += 1
        else:
            t = x + g
            if t <= 0:
                ans.append(str(n))
            elif t > q + 1:
                ans.append('0')
            else:
                ans.append(str(n - ask(t)))

    print('\n'.join(ans))

main()
