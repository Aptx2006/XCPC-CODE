import sys
from collections import deque
input = lambda: sys.stdin.readline().strip()
def main():
	n, m = map(int, input().split())
	G = []
	for _ in range(n):
	  G.append(list(input()))
	dx = [-1, 1, 0, 0]
	dy = [0, 0, -1, 1]
	
	q = deque()
	for i in range(n):
	  for j in range(m):
	      if (i == 0 or i == n-1 or j == 0 or j == m-1) and G[i][j] == '.':
	      	q.append((i, j))
	      	G[i][j] = '#' 
	
	while q:
	  x, y = q.popleft()
	  for k in range(4):
	  	nx = x + dx[k]
	  	ny = y + dy[k]
	  	if 0 <= nx < n and 0 <= ny < m and G[nx][ny] == '.':
	  		G[nx][ny] = '#'
	  		q.append((nx, ny))
	
	ans = 0
	for i in range(n):
	  for j in range(m):
	      if G[i][j] == '.':
	      	ans += 1
	      	q = deque()
	      	q.append((i, j))
	      	G[i][j] = '#'
	      	while q:
	      		x, y = q.popleft()
	      		for k in range(4):
	      			nx = x + dx[k]
	      			ny = y + dy[k]
	      			if 0 <= nx < n and 0 <= ny < m and G[nx][ny] == '.':
	      				G[nx][ny] = '#'
	      				q.append((nx, ny))
	
	print(ans)
    
main()