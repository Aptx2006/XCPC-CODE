import sys
from itertools import combinations 
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []


def main():
    n = II()
    a = list(II() for _ in range(n))
    if a[-1] > n - 2:
        out.append(f'{a[-1]} {0}')
        return
    cnt = mex = 0
    st = set()
    mex = 0
    for x in a:
        if x > n - 2 or x in st:
            cnt += 1
            st.add(mex)
        else:
            st.add(x)
        while mex in st:
            mex += 1
    out.append(f'{n - 1} {cnt}')

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
