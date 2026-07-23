import sys
from heapq import heappush, heappop
from functools import lru_cache,cache
sys.setrecursionlimit(1000000)
input = lambda: sys.stdin.readline().strip()


fmax = lambda a, b: a if a > b else b
fmin = lambda a, b: a if a < b else b
out = []
A=0
B=0
C=0
@cache
def dfs(a,b,c):
    global A,B,C
    if b < c or min(a,b,c) < 0:
        return 0
    if b+c==0:
        return 1
    if a+c==0:
        return 1
    ans = dfs(a-1,b,c) + dfs(a,b-1,c) + dfs(a,b,c-1)
    return ans
    
def main():
    global A,B,C
    x,y,k=map(int,input().split())
    C=k
    B=k+y
    A=x-k
    out.append(dfs(A,B,C))

for _ in range(1):
    main()

print('\n'.join(map(str, out)))
