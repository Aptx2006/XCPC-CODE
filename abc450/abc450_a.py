import sys
input = lambda: sys.stdin.readline().strip()
def main():
	n = int(input())
	a = []
	for i in range(n, 0, -1):
		a.append(i)
	print(",".join(map(str,a)))      
main()