import sys
input = lambda: sys.stdin.readline().strip()
# it = map(int, sys.stdin.read().split())
# II = lambda: next(it)

def main():
	n = int(input())
	a = list(map(int, input().split()))
	g0 = []
	g2 = []
	g3 = []
	g6 = []
	for x in a:
		if x % 6 == 0:
			g6.append(x)
		elif x % 2 == 0:
			g2.append(x)
		elif x % 3 == 0:
			g3.append(x)
		else:
			g0.append(x)
	res = g6 + g2 + g0 + g3
	print(*res)
    

for _ in range(int(input())):
	main()
