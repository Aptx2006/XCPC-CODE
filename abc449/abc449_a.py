# Problem: A - π
# Contest: AtCoder - AtCoder Beginner Contest 449
# URL: https://atcoder.jp/contests/abc449/tasks/abc449_a
# Memory Limit: 1024 MB
# Time Limit: 2000 ms
# 
# Powered by CP Editor (https://cpeditor.org)

import sys, math
input = lambda: sys.stdin.readline().strip()
def main():
	d = int(input())
	r = d / 2
	print(math.pi * r * r)      
main()