import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
def main():
	n, k, m = II(), II(), II()
	t = m // k
	time = min(n, k) if t & 1 else n
	m = m % k
	print(max(0, time - m))

for _ in range(II()):
	main()
