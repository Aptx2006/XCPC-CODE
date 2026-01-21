import sys
input = lambda: sys.stdin.readline().strip()
T = int(input())
for _ in range(T):
	n = int(input())
	if n == 2:
		print(2)
	elif n == 3:
		print(3)
	elif n % 2 == 1:
		print(1)
	else:
		print(0)