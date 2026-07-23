import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
def main():
	n = II()
	a = [II() for _ in range(n)]
	print(max(a) * n)

T = II()
for _ in range(T):
	main()
