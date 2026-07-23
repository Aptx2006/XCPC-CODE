import sys
from random import randint

input = lambda: sys.stdin.readline().strip()
sys.setrecursionlimit(1 << 20)


def main():
	n, q = map(int, input().split())

	l = [0] * (n + 1)
	r = [0] * (n + 1)
	fa = [0] * (n + 1)
	sz = [0] * (n + 1)
	pr = [0] * (n + 1)

	for i in range(1, n + 1):
		sz[i] = 1
		pr[i] = randint(1, 1 << 30)

	def pull(x):
		sz[x] = 1 + (sz[l[x]] if l[x] else 0) + (sz[r[x]] if r[x] else 0)
		if l[x]:
			fa[l[x]] = x
		if r[x]:
			fa[r[x]] = x

	def merge(a, b):
		if not a or not b:
			x = a or b
			if x:
				fa[x] = 0
			return x
		if pr[a] < pr[b]:
			r[a] = merge(r[a], b)
			pull(a)
			fa[a] = 0
			return a
		l[b] = merge(a, l[b])
		pull(b)
		fa[b] = 0
		return b

	def split(x, k):
		if not x:
			return 0, 0
		ls = sz[l[x]] if l[x] else 0
		if k <= ls:
			a, b = split(l[x], k)
			l[x] = b
			pull(x)
			if a:
				fa[a] = 0
			fa[x] = 0
			return a, x
		a, b = split(r[x], k - ls - 1)
		r[x] = a
		pull(x)
		if b:
			fa[b] = 0
		fa[x] = 0
		return x, b

	def root(x):
		while fa[x]:
			x = fa[x]
		return x

	def pos(x):
		res = (sz[l[x]] if l[x] else 0) + 1
		while fa[x]:
			p = fa[x]
			if r[p] == x:
				res += (sz[l[p]] if l[p] else 0) + 1
			x = p
		return res

	pile_root = [0] * (n + 1)
	root_pile = {}
	for i in range(1, n + 1):
		pile_root[i] = i
		root_pile[i] = i

	for _ in range(q):
		c, p = map(int, input().split())

		sr = root(c)
		dr = root(p)
		sp = root_pile[sr]
		dp = root_pile[dr]

		k = pos(c)
		a, b = split(sr, k - 1)
		nd = merge(dr, b)

		root_pile.pop(sr, None)
		root_pile.pop(dr, None)

		pile_root[sp] = a
		if a:
			root_pile[a] = sp

		pile_root[dp] = nd
		root_pile[nd] = dp

	ans = [0] * n
	for i in range(1, n + 1):
		rt = pile_root[i]
		ans[i - 1] = sz[rt] if rt else 0
	print(*ans)


main()
