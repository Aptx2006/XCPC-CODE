import sys
it = iter(sys.stdin.read().split())
SI = lambda: next(it)
II = lambda: int(SI())

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

MOD = 998244353

def main():
    n = II()
    h = [II() for i in range(n)]

    left = [-1] * n
    st = []
    for i, x in enumerate(h):
        while st and h[st[-1]] <= x: 
            st.pop()
        if st:
            left[i] = st[-1]
        st.append(i)
    
    last = 10**9
    ans = [0] * n
    for i, x in enumerate(h):
        ans[i] = (i - left[i]) * x + ans[left[i]]

    for x in ans:
        out.append(x + 1)

for _ in range(1):
    main()

print(' '.join(map(str, out)))
