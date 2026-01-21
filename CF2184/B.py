import sys
input = lambda: sys.stdin.readline().strip()
def main():
	n, k, m = map(int, input().split())
	t = m // k
	time = min(n, k) if t & 1 else n
	m = m % k
	print(max(0, time - m))

for _ in range(int(input())):
	main()