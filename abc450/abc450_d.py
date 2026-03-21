import sys
input = lambda: sys.stdin.readline().strip()
def main():
	n, k = map(int, input().split())
	a = list(map(int, input().split()))
	for i in range(n):
		a[i] %= k
	a.sort()
	ans = 10**9
	for i in range(n):
		ans = min(ans, a[-1] - a[i])
		a.append(a[i] + k)
	print(ans)
main()