import sys
input = lambda: sys.stdin.readline().strip()
def main():
	n = int(input())
	a = []
	for _ in range(n - 1):
		b = list(map(int, input().split()))
		a.append(b)
	f = 0
	for i in range(n - 2):
		for j in range(i + 1, n - 1):
			for k in range(j + 1, n):
				if a[i][k - i - 1] > a[i][j - i - 1] + a[j][k - j - 1]:
					f = 1
					break
	print("Yes\n" if f else "No\n") 
main()