import sys
input = lambda: sys.stdin.readline().strip()
def main():
	n = int(input())
	for _ in range(1, n + 1):
		print(_, end = ' ')
	print('')

T = int(input())
for _ in range(T):
	main()