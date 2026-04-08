import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
def main():
	n, k = II(), II()
	a = [0]
	b = [0]
	c = [0]
	for i in range(n):
		x, y = II(), II()
		a.append(x), b.append(y)
		c.append(x - y)
	c.sort(reverse = True)
	ans = sum(a)
	for i in range(k):
		ans -= c[i]
	print(ans)

main()
