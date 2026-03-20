import sys
sys.setrecursionlimit(100000)
input = lambda: sys.stdin.readline().strip()
def main():
	n = int(input())
	dp = list([0] * 2 for _ in range(n + 5))
	for i in range(n):
		dp[i + 1][1] = int(input())
	G = list([] for _ in range(n + 5))
	son = [0] * (n + 5)
	for i in range(n - 1):
		u, v = map(int, input().split())
		G[v].append(u)
		son[u] = 1
	def dfs(u):
		for v in G[u]:
			dfs(v)
			dp[u][0] += max(dp[v][0], dp[v][1])
			dp[u][1] += dp[v][0]
	for i in range(n):
		if son[i + 1] == 0:
			dfs(i + 1)
			print(max(dp[i + 1]))
	
main()