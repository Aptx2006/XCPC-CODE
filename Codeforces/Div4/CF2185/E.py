import sys
import bisect
input = lambda: sys.stdin.readline().strip()

def main():
  INF = 10**9
  n, m, k = map(int, input().split())
  a = list(map(int, input().split()))
  b = list(map(int, input().split()))
  b.sort()
  
  op = input()
  pt = [0]*(k + 2)
  nt = [0]*(k + 2)
  cur = 0 
  mx = 0
  mn = 0
  
  for i in range(1, k+1):
    cur += 1 if op[i-1] == 'R' else -1
    if cur > mx:
      mx = cur
      pt[mx] = i
    if cur < mn:
      mn = cur
      nt[-mn] = i
  
  die = [0]*(k + 2)
  for x in a:
    best = INF
    it = bisect.bisect_left(b, x)
    if it < m:
      d = b[it] - x
      if d > 0 and d <= mx:
        best = min(best, pt[d])
    if it > 0:
      jt = it - 1
      d = x - b[jt]
      if d > 0 and d <= -mn:
        best = min(best, nt[d])
    if best != INF:
      die[best] += 1
  
  dead = 0
  res = []
  for i in range(1, k+1):
    dead += die[i]
    res.append(str(n - dead))
  print(' '.join(res))

T = int(input())
for _ in range(T):
  main()