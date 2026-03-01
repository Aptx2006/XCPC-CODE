import sys
import math
from collections import defaultdict, deque, Counter
input = lambda: sys.stdin.readline()
import heapq
def main():
  n,m = map(int, input().split())
  adj = [[] for _ in range(n + 1)]
  for _ in range(m):
      u, v = map(int, input().split())
      adj[u].append(v)
  
  INF = float('inf')
  f = [INF] * (n + 1)
  f[1] = 1  
  heap = []
  heapq.heappush(heap, (1, 1))  

  while heap:
  	cmx, u = heapq.heappop(heap)
  	if cmx > f[u]:
  		continue
  	for v in adj[u]:
  		mx = max(cmx, v)
  		if mx < f[v]:
  			f[v] = mx
  			heapq.heappush(heap, (mx, v))
  g = [0] * (n + 1)
  for i in range(1, n + 1):
  	g[i] = max(g[i - 1], f[i])
  for i in range(1, n + 1):
  	if g[i] == i:
  		print(n - i)
  	else:
  		print(-1)

main()