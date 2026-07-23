import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
def main():
	n = II()
	a = [II() for _ in range(n)]
	a.sort()
	ans = cnt = 0
	for i in range(1, n):
		if a[i] == a[i - 1]:
			continue
		elif a[i] == a[i - 1] + 1:
			cnt += 1
		else:
			ans = max(ans, cnt + 1)
			cnt = 0
	print(max(ans, cnt + 1))
	
T = II()
for _ in range(T):
	main()
