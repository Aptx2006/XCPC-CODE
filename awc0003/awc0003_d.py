import sys
input = lambda: sys.stdin.readline()
def main():
	n, k, m = map(int, input().split())
	a = list(map(int, input().split()))
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