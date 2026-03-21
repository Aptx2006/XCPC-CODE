# Problem: d - Make Target 2
# Contest: AtCoder - AtCoder Beginner Contest 449
# URL: https://atcoder.jp/contests/abc449/tasks/abc449_d
# Memory Limit: 1024 MB
# Time Limit: 2000 ms
# 
# Powered by CP Editor (https://cpeditor.org)

import sys
input = lambda: sys.stdin.readline().strip()
def main():
	l, r, d, u = map(int, input().split())
	def h(k):
	  mnx = max(l, -k)
	  mxx = min(r, k)
	  mny = max(d, -k)
	  mxy = min(u, k)
	  if mnx > mxx or mny > mxy:
	      return 0
	  return (mxx - mnx + 1) * (mxy - mny + 1)
	
	mxk = max(max(abs(l), abs(r)), max(abs(d), abs(u)))
	ans = 0
	k = 0
	while k <= mxk:
	  ans += h(k) - h(k-1)
	  k += 2
	print(ans)
main()