# Problem: D - Concat Power of 2
# Contest: AtCoder - AtCoder Beginner Contest 451
# URL: https://atcoder.jp/contests/abc451/tasks/abc451_d
# StartTime 2026-03-28 20:52:03
# Memory Limit: 1024 MB
# Time Limit: 2000 ms
# Coder:Aptx4869
# 
# Powered by CP Editor (https://cpeditor.org)

import sys, heapq, bisect
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
def main():
    S = []
    k = 0
    while 1:
        val = 1 << k 
        s = str(val)
        if len(s) > 9:
            break
        S.append(s)
        k += 1
    
    a = []
    st = set()
    
    for s in S:
        x = int(s)
        if x not in st:
            heapq.heappush(a, x)
            st.add(x)
    
    n = II()
    ans = 0
    for _ in range(n):
        cur = heapq.heappop(a)
        ans = cur
        if _ == n - 1:
            break
        cs = str(cur)
        clen = len(cs)
        for t in S:
            tlen = len(t)
            if clen + tlen > 9:
                continue
            ns = cs + t
            nx = int(ns)
            if nx not in st:
                st.add(nx)
                heapq.heappush(a, nx)
    print(ans)
    
main()
