import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
def main():
	n, k = II(), II()
	for b in range(33):
		H = 1 << b
		mn, mx = n // H, (n - 1 + H) // H
		if k >= mn and k <= mx:
			print(b)
			return
	
	print(-1)

for _ in range(II()):
	main()
