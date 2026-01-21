import sys
input = lambda: sys.stdin.readline().strip()
def main():
	n, k = map(int, input().split())
	for b in range(33):
		H = 1 << b
		mn, mx = n // H, (n - 1 + H) // H
		if k >= mn and k <= mx:
			print(b)
			return
	
	print(-1)

for _ in range(int(input())):
	main()