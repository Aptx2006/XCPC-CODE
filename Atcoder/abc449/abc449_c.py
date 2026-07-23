# Problem: C - Comfortable Distance
# Contest: AtCoder - AtCoder Beginner Contest 449
# URL: https://atcoder.jp/contests/abc449/tasks/abc449_c
# Memory Limit: 1024 MB
# Time Limit: 2000 ms
# 
# Powered by CP Editor (https://cpeditor.org)

import sys
import bisect 
input = lambda: sys.stdin.readline().strip()
def main():
	n, l ,r = map(int, input().split())
	s = input()
	ans = 0
	mp = list([] for _ in range(26))
	for i in range(n):
		j = ord(s[i]) - ord('a')
		mn = bisect.bisect_left(mp[j], i - r)
		mx = bisect.bisect_right(mp[j], i - l)
		ans += (mx - mn)
		mp[j].append(i)
	print(ans)
	
main()