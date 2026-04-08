import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)
def main():
	n = II()
	a = []
	for i in range(n, 0, -1):
		a.append(i)
	print(",".join(map(str,a)))      
main()
