import sys
input = lambda: sys.stdin.readline()
def main():
	n, k = map(int, input().split())
	ans = 0
	for i in range(n):
		a, b = map(int, input().split())
		if a * b >= k:
			ans += 1
			
	print(ans)

main()