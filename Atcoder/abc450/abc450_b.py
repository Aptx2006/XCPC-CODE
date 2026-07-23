import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
def main():
	n = II()
	a = []
	for _ in range(n - 1):
		b = [II() for _ in range(n)]
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
