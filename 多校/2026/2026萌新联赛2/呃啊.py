import sys
input = lambda: sys.stdin.readline().strip()
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

def main():
    n, m, s, k, t = II(), II(), II(), II(), II()
    a = list(range(n))
    id1 = id2 = s - 1
    cnt = 0
    while len(a) > 1:
        if a[id1] != id2:
            a.pop(id1)
            if len(a) == 1:
                break
            id1 %= len(a)
        else:
            id1 = (id1 + 1) % len(a)

        id1 = (id1 + m) % len(a)
        cnt += 1
        if cnt != t:
            continue
        cnt = 0
        id2 = (id2 - k - 1) % n
        if id2 not in a:
            i = sum(x < id2 for x in a)
            a.insert(i, id2)
            if i <= id1:
                id1 += 1
    out.append(a.pop() + 1)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
