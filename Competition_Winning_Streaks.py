import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []
INF = -10**30

def main():
    k, x1, y1, x2, y2 = II(), II(), II(), II(), II()
    A = x2 - x1
    B = y2 - y1

    # 对于y 安全的x [L, R]
    def xrange(y):
        if y <= k - 2:
            return (INF, k - 1)
        if y == k - 1:
            return (INF, k)
        if y == k:
            return (k - 1, k + 1)
        if y == k + 1:
            return (k, k + 2)
        return (y - 1, y + 1)

    def yrange(x):
        if x <= k - 2:
            return (INF, k - 1)
        if x == k - 1:
            return (INF, k)
        if x == k:
            return (k - 1, k + 1)
        if x == k + 1:
            return (k, k + 2)
        return (x - 1, x + 1)

    # 点 (x,y) 作为中间状态是否安全
    def safe(x, y):
        return max(x, y) < k or abs(x - y) <= 1
    def visok(ya, yb, x):
        if ya >= yb:
            return True
        L, R = yrange(x)
        return ya + 1 >= L and yb <= R

    def hisok(xa, xb, y):
        if xa >= xb:
            return True
        L, R = xrange(y)
        return xa + 1 >= L and xb <= R

    # 移动终点是否安全
    def visokf(ya, yb, x):
        if ya >= yb:
            return True
        if ya + 1 >= yb:
            return True
        L, R = yrange(x)
        return ya + 1 >= L and yb - 1 <= R


    def hisokf(xa, xb, y):
        if xa >= xb:
            return True
        if xa + 1 >= xb:
            return True
        L, R = xrange(y)
        return xa + 1 >= L and xb - 1 <= R

    if A == 0:
        mn = 0
    elif B == 0:
        mn = A
    else:
        ideal = (A + B) // (B + 1)

        st = 0
        stmx = 0
        cx, cy = x1, y1
        while cx < x2 or cy < y2:
            flaga = (cx + 1 == x2 and cy == y2)
            flagb = (cy + 1 == y2 and cx == x2)
            aok = cx < x2 and (hisokf if flaga else hisok)(cx, cx + 1, cy)
            bok = cy < y2 and (visokf if flagb else visok)(cy, cy + 1, cx)
            if aok and not bok:
                st += 1
                stmx = fmax(stmx, st)
                cx += 1
            elif bok and not aok:
                st = 0
                cy += 1
            else:
                break
        sx, sy = cx, cy

        ed = 0
        edmx = 0
        cx, cy = x2, y2
        first = True
        while cx > x1 or cy > y1:
            if first:
                aok = cx > x1 and safe(cx - 1, cy) and hisokf(cx - 1, cx, cy)
                bok = cy > y1 and safe(cx, cy - 1) and visokf(cy - 1, cy, cx)
                first = False
            else:
                aok = cx > x1 and safe(cx - 1, cy) and hisok(cx - 1, cx, cy)
                bok = cy > y1 and safe(cx, cy - 1) and visok(cy - 1, cy, cx)
            if aok and not bok:
                ed += 1
                edmx = fmax(edmx, ed)
                cx -= 1
            elif bok and not aok:
                ed = 0
                cy -= 1
            else:
                break
        ex, ey = cx, cy

        midA = ex - sx
        midB = ey - sy
        if midA <= 0:
            mid_ideal = 0
        elif midB <= 0:
            mid_ideal = midA
        else:
            mid_ideal = (midA + midB) // (midB + 1)

        mn = fmax(ideal, fmax(fmax(stmx, edmx), mid_ideal))

    cand = {y1, y2}
    for t in [k - 2, k - 1, k, k + 1, k + 2,
              x1 - 1, x1, x1 + 1, x1 + 2,
              x2 - 2, x2 - 1, x2, x2 + 1]:
        cand.add(t)
    cand = sorted([y for y in cand if y1 <= y <= y2])

    if A == 0:
        mx = 0
    else:
        mx = 0
        full = False
        for y in cand:
            L, R = xrange(y)
            if not (x1 >= L and x1 <= R):
                continue
            if y == y2:
                if hisokf(x1, x2, y):
                    full = True
                    break
            else:
                if hisok(x1, x2, y):
                    full = True
                    break
        if full:
            mx = A
        else:
            for y in cand:
                L, R = xrange(y)
                st = fmax(x1, L)
                ed = x2 if y == y2 else fmin(x2, R)
                if st >= ed:
                    continue
                if ed == x2 and y == y2:
                    if not hisokf(st, ed, y):
                        continue
                else:
                    if not hisok(st, ed, y):
                        continue

                if ed == x2 and y == y2:
                    ok = True
                elif ed == x2:
                    ok = visokf(y, y2, x2)
                elif y == y2:
                    ok = hisokf(ed, x2, y2)
                else:
                    ok = True
                if ok:
                    mx = fmax(mx, ed - st)

            if mx == 0:
                mx = 1

    out.append(f"{mn} {mx}")

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
