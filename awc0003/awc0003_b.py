import sys
input = lambda: sys.stdin.readline()
def main():
	n = int(input())
	s = input()
	R1 = s[2]
	ans = 0
	for i in range(n - 1):
		s = input()
		if R1 == s[0]:
			ans += 1
		R1 = s[2]
			
	print(ans)

main()