from functools import lru_cache
import sys
sys.setrecursionlimit(10000)
input = lambda: sys.stdin.readline().strip()
it = map(int, sys.stdin.read().split())
II = lambda: next(it)

fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []

mod = 0
st = set()
def dfs(a, b):
    if a == 0:
        return 1
    if b == 0:
        return 2
    if (a, b) in st:
        return 'error'
    st.add((a, b))
    num = (a + b) % mod
    return dfs(num, (num % mod + b) % mod) 

def main():
    global st
    st.clear()
    out.append(dfs(II(), II()))

T, mod = II(), II()
for _ in range(T):
    main()

print('\n'.join(map(str, out)))