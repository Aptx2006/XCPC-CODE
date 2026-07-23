import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
def main():
	n, k = II(), II()
	a = [II() for _ in range(n)]
	for i in range(n):
		a[i] %= k
	a.sort()
	ans = 10**9
	for i in range(n):
		ans = min(ans, a[-1] - a[i])
		a.append(a[i] + k)
	print(ans)
main()
