from collections import Counter, defaultdict
from math import gcd
import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def fun(n, d):
    if d < 0:
        n = -n
        d = -d
    g = gcd(abs(n), d)
    return (n // g, d // g)

def calc(a, b, op):
    n1, d1 = a
    n2, d2 = b
    if op == '+':
        return fun(n1 * d2 + n2 * d1, d1 * d2)
    if op == '-':
        return fun(n1 * d2 - n2 * d1, d1 * d2)
    if op == '*':
        return fun(n1 * n2, d1 * d2)
    if n2 == 0:
        return None
    return fun(n1 * d2, n1 * 0 + d1 * n2)

def main():
    s = SI()
    n = II()
    s = set(s)
    ops = [c for c in '+-*/' if c not in s]
    tag = (n, 1)

    dig = [str(i) for i in range(10) if str(i) not in s]

    mp = {}
    for d in dig:
        mp[(int(d), 1)] = d

    for a in dig:
        if a == '0':
            continue
        for b in dig:
            ab = a + b
            key = (int(ab), 1)
            if key not in mp or len(ab) < len(mp[key]):
                mp[key] = ab

    for a in dig:
        if a == '0':
            continue
        for b in dig:
            for c in dig:
                abc = a + b + c
                key = (int(abc), 1)
                if key not in mp or len(abc) < len(mp[key]):
                    mp[key] = abc

    mp_ = sorted([(k, v) for k, v in mp.items()], key=lambda x: (len(x[1]), x[0]))
    vals = [k[0] for k, _ in mp_]
    strs = [v for _, v in mp_]

    if tag in mp:
        exp = mp[tag]
        out.extend(['Yes', str(len(exp)), exp])
        return

    st1 = set()
    st2 = set()
    for c in vals:
        st1.add(n - c)
        st1.add(n + c)
        st1.add(n * c)
        if c != 0:
            t = fun(n, c)
            if t[1] == 1:
                st1.add(t[0])
            else:
                st2.add(t)

    best = {}

    m = len(vals)
    for i in range(m):
        a = vals[i]
        saa = strs[i]
        for j in range(m):
            b = vals[j]
            sbb = strs[j]

            if '+' in ops:
                r = a + b
                if r == n:
                    exp = saa + '+' + sbb
                    out.extend(['Yes', str(len(exp)), exp])
                    return
                if r in st1:
                    res = (r, 1)
                    exp = saa + '+' + sbb
                    old = best.get(res)
                    if old is None or len(exp) < len(old):
                        best[res] = exp

            if '-' in ops:
                r = a - b
                if r == n:
                    exp = saa + '-' + sbb
                    out.extend(['Yes', str(len(exp)), exp])
                    return
                if r in st1:
                    res = (r, 1)
                    exp = saa + '-' + sbb
                    old = best.get(res)
                    if old is None or len(exp) < len(old):
                        best[res] = exp

            if '*' in ops:
                r = a * b
                if r == n:
                    exp = saa + '*' + sbb
                    out.extend(['Yes', str(len(exp)), exp])
                    return
                if r in st1:
                    res = (r, 1)
                    exp = saa + '*' + sbb
                    old = best.get(res)
                    if old is None or len(exp) < len(old):
                        best[res] = exp

            if '/' in ops and b != 0:
                res = fun(a, b)
                if res == tag:
                    exp = saa + '/' + sbb
                    out.extend(['Yes', str(len(exp)), exp])
                    return
                if (res[1] == 1 and res[0] in st1) or res in st2:
                    exp = saa + '/' + sbb
                    old = best.get(res)
                    if old is None or len(exp) < len(old):
                        best[res] = exp

    for (cc, scc) in mp_:
        c = cc[0]

        exp_ = best.get((n - c, 1))
        if exp_ is not None:
            exp = exp_ + '+' + scc
            out.extend(['Yes', str(len(exp)), exp])
            return

        exp_ = best.get((n + c, 1))
        if exp_ is not None:
            exp = exp_ + '-' + scc
            out.extend(['Yes', str(len(exp)), exp])
            return

        if c == 0:
            if n == 0:
                exp_ = best.get((0, 1))
                if exp_ is not None:
                    exp = exp_ + '*' + scc
                    out.extend(['Yes', str(len(exp)), exp])
                    return
        else:
            exp_ = best.get(fun(n, c))
            if exp_ is not None:
                exp = exp_ + '*' + scc
                out.extend(['Yes', str(len(exp)), exp])
                return

        if c != 0:
            exp_ = best.get((n * c, 1))
            if exp_ is not None:
                exp = exp_ + '/' + scc
                out.extend(['Yes', str(len(exp)), exp])
                return

    out.append('No')

for _ in range(II()):
    main()

print('\n'.join(out))