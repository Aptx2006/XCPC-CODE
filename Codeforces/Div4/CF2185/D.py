import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
def main():
	n, m, h = II(), II(), II()
	a = [II() for _ in range(n)]
	a = [0] + a
	aa = list(x for x in a)
	L = list()
	for i in range(m):
		b, c = II(), II()
		a[b] += c
		L.append(b)
		if a[b] > h:
			for _ in L:
				a[_] = aa[_]
			L = list()
	print(*a[1:])
	
T = II()
for _ in range(T):
	main()
