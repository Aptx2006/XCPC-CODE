import sys
from itertools import combinations 
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []
mp = {}
st1 = []

for r in range(1, 7):
    for comb in combinations(range(9), r):
        st = set(comb)
        if 6 in st:
            st.add(9)
        st1.append((list(comb), st))

for i in range(len(st1)):
    for j in range(i, len(st1)):
        cA, setA = st1[i]
        cB, setB = st1[j]
        
        mex = 1
        while True:
            t = mex // 10
            o = mex % 10
            if (t in setA and o in setB) or (t in setB and o in setA):
                mex += 1
            else:
                break
        
        if mex not in mp:
            mp[mex] = (cA, cB)

def main():
    s = II()
    if s in mp:
        out.append('Yes')
        cA, cB = mp[s]
        ansA = cA + [cA[0]] * (6 - len(cA))
        ansB = cB + [cB[0]] * (6 - len(cB))
        out.append(' '.join(map(str, ansA + ansB)))
    else:
        out.append('No')

for _ in range(II()):
    main()

print('\n'.join(map(str, out)))
