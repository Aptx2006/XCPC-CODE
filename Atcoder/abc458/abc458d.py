import heapq
import sys
input = lambda: sys.stdin.readline().strip()

left = []
right = []

heapq.heappush(left, -int(input()))

for i in range(int(input())):
    A, B = map(int, input().split())
    
    if A <= -left[0]:
        heapq.heappush(left, -A)
    else:
        heapq.heappush(right, A)
    
    if B <= -left[0]:
        heapq.heappush(left, -B)
    else:
        heapq.heappush(right, B)
    
    while len(left) > i+2:
        val = -heapq.heappop(left)
        heapq.heappush(right, val)
    while len(left) < i+2:
        val = heapq.heappop(right)
        heapq.heappush(left, -val)
    
    print(-left[0])
