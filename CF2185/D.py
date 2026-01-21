import sys
input = lambda: sys.stdin.readline().strip()
def main():
	n, m, h = map(int, input().split())
	a = list(map(int, input().split()))
	a = [0] + a
	aa = list(x for x in a)
	L = list()
	for i in range(m):
		b, c = map(int, input().split())
		a[b] += c
		L.append(b)
		if a[b] > h:
			for _ in L:
				a[_] = aa[_]
			L = list()
	print(*a[1:])
	
T = int(input())
for _ in range(T):
	main()