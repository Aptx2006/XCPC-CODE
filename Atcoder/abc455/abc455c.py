import sys
input = lambda: sys.stdin.readline().strip()

def main():
	n, k = map(int, input().split())
	a = list(map(int, input().split()))

	mp = {}
	for x in a:
		mp[x] = mp.get(x, 0) + x

	ans = sorted(mp.values(), reverse=True)
	print(sum(a) - sum(ans[:k]))

main()



