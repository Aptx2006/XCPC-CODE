import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
def main():
	n = II()
	for _ in range(1, n + 1):
		print(_, end = ' ')
	print('')

T = II()
for _ in range(T):
	main()
