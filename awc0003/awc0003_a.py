import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
def main():
	n, k = II(), II()
	ans = 0
	for i in range(n):
		a, b = II(), II()
		if a * b >= k:
			ans += 1
			
	print(ans)

main()
