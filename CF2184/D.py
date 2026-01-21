import sys
input = lambda: sys.stdin.readline().strip()
def main():
	n, k = map(int, input().split())
	global C
	ln, ans = n.bit_length(), 0
	if(ln > k):
		ans = 1
	for i in range(1, ln):
		st = max(0, k + 1 - i)
		for j in range(st, i):
			ans += C[i - 1][j]
	
	print(ans)
	
for i in range(35):
	C[i][0] = 1
	for j in range(1, i + 1):
		C[i][j] = C[i - 1][j] + C[i - 1][j - 1]
for _ in range(int(input())):
	main()