import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
T = II()
for _ in range(T):
	n = II()
	if n == 2:
		print(2)
	elif n == 3:
		print(3)
	elif n % 2 == 1:
		print(1)
	else:
		print(0)
