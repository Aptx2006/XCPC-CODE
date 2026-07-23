import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
def main():
	n, k, m = II(), II(), II()
	a = [II() for _ in range(n)]
	ans = 0
	cur = 0 
	l = 0        
	for r in range(n):
		cur += a[r]
		while l <= r - k + 1 and cur >= m:
			cur -= a[l]
			l += 1
		if r >= k - 1:
			ans += l
	print(ans)

main()
