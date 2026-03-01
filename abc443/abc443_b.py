n, k = map(int, input().split())
sum, cnt = n, 0
while True:
	if sum >= k:
		break
	cnt += 1
	n += 1
	sum += n
print(cnt)