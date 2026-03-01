n = int(input())
a = list()
for i in range(n):
	s = input()
	a.append(s)
mx = max(len(s) for s in a)
for s in a:
	c = (mx - len(s)) // 2
	print('.' * c, s, '.' * c, sep = '')