
"""
HDU 1532 / Drainage Ditches — 最大流问题

题意（简短）:
- 给定一个有向图，M 个交叉点（节点），编号 1..M；编号 1 为池塘（源点），编号 M 为河流（汇点）。
- 有 N 条沟渠（有向边），每条边 Si -> Ei，容量 Ci（表示该沟渠每分钟能排出的最大流量）。
- 目标：求从源点 1 到汇点 M 的最大流量（单位：加仑/分钟）。

算法：Dinic 最大流
- 思路概述：重复两步直到无法增流：
  1) 用 BFS 从源构建分层图（level 数组），只保留能从层 i 到层 i+1 的边；
  2) 在分层图上用 DFS 找阻塞流（尽量多推流），并利用当前弧优化避免重复遍历。
- 实现要点：
  * 邻接表存储边，边使用三元组 [to, cap, rev]，rev 为反向边在目标节点邻接表中的索引；
  * add_edge 同时添加正向边与反向边（反向边初始容量为 0），便于残量更新；
  * BFS 构建 level[]，DFS 使用 it[]（当前弧）加速；
  * INF 取足够大（Python int 不溢出）。
- 复杂度：
  * 对本题规模（M ≤ 200, N ≤ 200）足够；理论复杂度常见分析为 O(V^2 * E)（较弱上界），
	在某些图论文献中对单位网络或特殊图可得更好界（如 O(E * sqrt(V)) 等），但对工程实现不必深究。

常见变体与进阶：
- 最小费用最大流（MCMF）：每条边带费用，求满足需求的最小费用；常用算法有 SPFA/优先队列 + 潜势法（Johnson）。
- Push-Relabel（推-放）和 ISAP：在某些稠密图或特殊情形下比 Dinic 更快。
- 最大流应用：二分配、最小割、连通性、圈覆盖、项目选择、闭环最小割等问题。

使用建议：
- 先熟悉 Ford-Fulkerson/Edmonds-Karp，再掌握 Dinic（分层 + 阻塞流）；
- 在练习中注意实现细节：反向边、当前弧优化、对大输入使用快速输入（如整数流）。
"""

import sys

it = map(int, sys.stdin.buffer.read().split())
II = lambda: next(it)


class Dinic:
	def __init__(self, n):
		self.n = n
		self.G = [[] for _ in range(n)]

	def add_edge(self, u, v, c):
		self.G[u].append([v, c, len(self.G[v])])
		self.G[v].append([u, 0, len(self.G[u]) - 1])

	def bfs(self, s, t):
		from collections import deque
		self.level = [-1] * self.n
		q = deque()
		self.level[s] = 0
		q.append(s)
		while q:
			u = q.popleft()
			for v, cap, _ in self.G[u]:
				if cap > 0 and self.level[v] < 0:
					self.level[v] = self.level[u] + 1
					q.append(v)
		return self.level[t] >= 0

	def dfs(self, u, t, f):
		if u == t:
			return f
		i = self.it[u]
		while i < len(self.G[u]):
			v, cap, rev = self.G[u][i]
			if cap > 0 and self.level[v] == self.level[u] + 1:
				ret = self.dfs(v, t, min(f, cap))
				if ret > 0:
					self.G[u][i][1] -= ret
					self.G[v][rev][1] += ret
					return ret
			i += 1
			self.it[u] = i
		return 0

	def maxflow(self, s, t):
		flow = 0
		INF = 10 ** 18
		while self.bfs(s, t):
			self.it = [0] * self.n
			while True:
				pushed = self.dfs(s, t, INF)
				if pushed == 0:
					break
				flow += pushed
		return flow


def main():
	res = []
	while True:
		try:
			n = II()
			m = II()
		except StopIteration:
			break
		dinic = Dinic(m)
		for _ in range(n):
			s = II()
			e = II()
			c = II()
			dinic.add_edge(s - 1, e - 1, c)
		res.append(str(dinic.maxflow(0, m - 1)))
	print("\n".join(res))


for _ in range(1):
	main()
