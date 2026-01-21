import sys
input = lambda: sys.stdin.readline().strip()
def main():
	n = int(input())
	a = list(map(int, input().split()))
	print(max(a) * n)

T = int(input())
for _ in range(T):
	main()