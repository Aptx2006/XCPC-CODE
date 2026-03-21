# Problem: B - Deconstruct Chocolate
# Contest: AtCoder - AtCoder Beginner Contest 449
# URL: https://atcoder.jp/contests/abc449/tasks/abc449_b
# Memory Limit: 1024 MB
# Time Limit: 2000 ms
# 
# Powered by CP Editor (https://cpeditor.org)

import sys
input = lambda: sys.stdin.readline().strip()
def main():
	h, w, q = map(int, input().split())
	for _ in range(q):
		op, x = map(int, input().split()) 
		if op == 1:
			h -= x
			print(w * x)
		else:
			w -= x
			print(x * h)     
main()