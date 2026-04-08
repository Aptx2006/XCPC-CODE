import sys
it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)

n, k = II(), II()
sum, cnt = n, 0
while True:
	if sum >= k:
		break
	cnt += 1
	n += 1
	sum += n
print(cnt)
