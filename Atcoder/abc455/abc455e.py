import sys
input = lambda: sys.stdin.readline().strip()

def cnt1(arr):
	mp = {}
	ans = 0
	for x in arr:
		c = mp.get(x, 0)
		ans += c
		mp[x] = c + 1
	return ans

def cnt2(arr):
	mp = {}
	ans = 0
	for x in arr:
		c = mp.get(x, 0)
		ans += c
		mp[x] = c + 1
	return ans

def main():
	t = sys.stdin.read().split()
	s = t[-1]
	n = len(s)

	d1 = [0] 
	d2 = [0] 
	d3 = [0] 
	d12 = [(0, 0)]  # (A-B, A-C)

	a = b = c = 0
	for ch in s:
		if ch == 'A':
			a += 1
		elif ch == 'B':
			b += 1
		else:
			c += 1
		d1.append(a - b)
		d2.append(b - c)
		d3.append(a - c)
		d12.append((a - b, a - c))

	tot = n * (n + 1) // 2
	print(tot - ( cnt1(d1) + cnt1(d2) + cnt1(d3)) + 2 * cnt2(d12))

main()
