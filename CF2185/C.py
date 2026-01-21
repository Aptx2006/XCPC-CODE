import sys
input = lambda: sys.stdin.readline().strip()
def main():
	n = int(input())
	a = list(map(int, input().split()))
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
	
T = int(input())
for _ in range(T):
	main()