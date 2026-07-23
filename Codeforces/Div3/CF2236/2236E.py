from collections import deque
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
    a = [II() for _ in range(n)]
    ans = 0
    for L in range(n // 2, 0, -1):
        mp = [0] * (n + 1)
        dis = 0
        dq_mn = deque()
        dq_mx = deque()
        isok = [False] * (n - L + 1)
        mn = [0] * (n - L + 1)

        for i, x in enumerate(a):
            if mp[x] == 0:
                dis += 1
            mp[x] += 1

            while dq_mn and a[dq_mn[-1]] >= x:
                dq_mn.pop()
            dq_mn.append(i)

            while dq_mx and a[dq_mx[-1]] <= x:
                dq_mx.pop()
            dq_mx.append(i)

            if i >= L:
                y = a[i - L]
                mp[y] -= 1
                if mp[y] == 0:
                    dis -= 1
                if dq_mn[0] == i - L:
                    dq_mn.popleft()
                if dq_mx[0] == i - L:
                    dq_mx.popleft()

            if i >= L - 1:
                s = i - L + 1
                mx = a[dq_mx[0]]
                mn[s] = a[dq_mn[0]]
                isok[s] = (dis == L and mx - mn[s] + 1 == L)

        st = set()
        for s in range(n - L + 1):
            if s >= L and isok[s - L]:
                st.add(mn[s - L])
            if isok[s]:
                m = mn[s]
                if (m - L) in st or (m + L) in st:
                    ans = L
                    break
        if ans:
            break

    out.append(ans)

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))