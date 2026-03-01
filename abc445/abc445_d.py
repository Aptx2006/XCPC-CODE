import sys
from collections import defaultdict, deque
input = lambda: sys.stdin.readline()
def main():
	H, W, n = map(int, input().split())
	a = []
	hmp = defaultdict(deque)
	wmp = defaultdict(deque)
	for i in range(n):
		x, y = map(int, input().split())
		a.append((x, y))
		hmp[x].append((x, i))
		wmp[y].append((y, i))
	res = [(0, 0)] * n
	Q = deque()
	Q.append((1, 1, H, W))
	while Q:
		x, y, h, w = Q.popleft()
		if h == 0 or w == 0:
			continue
		f = False
		for i in range(len(hmp[h])):
			wi, idx = hmp[h].popleft()
			if wi == w:
				res[idx] = (x, y)
				if w > wi:
					Q.append((x, y + wi, h, w - wi))
				if h > 1 and wi > 0:
					Q.append((x + h, y, h - 1, wi))
				f = True
				break
			else:
				hmp[h].append((wi, idx))
		if f:
			continue
		for i in range(len(wmp[w])):
			hi, idx = wmp[w].popleft()
			if hi == h:
				res[idx] = (x, y)
				if h > hi:
					Q.append((x + hi, y, h - hi, w))
				f = True
				break
			else:
				wmp[w].append((hi, idx))
		if f:
			continue
			
		wi, idx = hmp[h].popleft()
		res[idx] = (x, y)
		if w > wi:
			Q.append((x, y + wi, h, w - wi))
		if h > 1 and wi > 0:
			Q.append((x + h, y, h - 1, wi))

	for x, y in res:
		print(x, y)
		
	
main()