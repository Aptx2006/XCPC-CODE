import sys
input = lambda: sys.stdin.readline()
def main():
	n, k = map(int, input().split())
	a = [0]
	b = [0]
	c = [0]
	for i in range(n):
		x, y = map(int, input().split())
		a.append(x), b.append(y)
		c.append(x - y)
	c.sort(reverse = True)
	ans = sum(a)
	for i in range(k):
		ans -= c[i]
	print(ans)

main()