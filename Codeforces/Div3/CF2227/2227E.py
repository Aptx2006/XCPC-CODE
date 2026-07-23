import sys
input = lambda: sys.stdin.readline().strip()
# it = map(int, sys.stdin.read().split())
# II = lambda: next(it)p()

def main():
	n = int(input())
	arr = list(map(int, input().split()))
	a = [0] + arr
	p = [0] * (n + 2)
	r = [0] * (n + 2)
	s = sum(arr)
	for i in range(1, n + 1):
		p[a[i]] = max(p[a[i]], i)
	k = 0
	for i in range(1, n + 1):
		r[i] = max(r[i - 1], p[i - 1])
		k += (n - r[i])
	m = s - k
	x = m
	for i in range(1, n + 1):
		d = max(0, i - r[a[i]] - 1)
		if m + d > x:
			x = m + d
	print(x)

for _ in range(int(input())):
	main()
