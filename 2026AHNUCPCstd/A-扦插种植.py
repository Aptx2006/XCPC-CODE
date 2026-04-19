import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())
# 模板来源 https://leetcode.cn/circle/discuss/mOr1u6/
class UnionFind:
    def __init__(self, n: int):
        # 一开始有 n 个集合 {0}, {1}, ..., {n-1}
        # 集合 i 的代表元是自己，大小为 1
        self._fa = list(range(n))  # 代表元
        self._size = [1] * n  # 集合大小
        self.cc = n  # 连通块个数

    # 返回 x 所在集合的代表元
    # 同时做路径压缩，也就是把 x 所在集合中的所有元素的 fa 都改成代表元
    def find(self, x: int) -> int:
        root = x
        while self._fa[root] != root:
            root = self._fa[root]
        while self._fa[x] != root:
            nxt = self._fa[x]
            self._fa[x] = root
            x = nxt
        return root

    # 判断 x 和 y 是否在同一个集合
    def is_same(self, x: int, y: int) -> bool:
        # 如果 x 的代表元和 y 的代表元相同，那么 x 和 y 就在同一个集合
        # 这就是代表元的作用：用来快速判断两个元素是否在同一个集合
        return self.find(x) == self.find(y)

    # 把 from 所在集合合并到 to 所在集合中
    # 返回是否合并成功
    def merge(self, from_: int, to: int) -> bool:
        x, y = self.find(from_), self.find(to)
        if x == y:  # from 和 to 在同一个集合，不做合并
            return False
        self._fa[x] = y  # 合并集合。修改后就可以认为 from 和 to 在同一个集合了
        self._size[y] += self._size[x]  # 更新集合大小（注意集合大小保存在代表元上）
        # 无需更新 _size[x]，因为我们不用 _size[x] 而是用 _size[find(x)] 获取集合大小，但 find(x) == y，我们不会再访问 _size[x]
        self.cc -= 1  # 成功合并，连通块个数减一
        return True

    # 返回 x 所在集合的大小
    def get_size(self, x: int) -> int:
        return self._size[self.find(x)]  # 集合大小保存在代表元上
def solve():
    q = ii()
    d = 1
    fa = {}
    node = {}
    vis = {}
    query = []
    eg = []
    for i in range(1, q + 1):
        op,x = mii()
        query.append((op, x))
        if op == 1:
            d += 1
            fa[d] = x
            node[i] = d
            eg.append((d, x))
        elif op == 2:
            if x > 1 and x not in vis:
                vis[x] = i
    dsu = UnionFind(d + 1)
    for u, v in eg:
        if u not in vis:
            dsu.merge(u, v)
    res = []
    for i in range(q, 0, -1):
        op, x = query[i-1]
        if op == 3:
            res.append(dsu.get_size(x))
        elif op == 2:
            if x > 1 and vis.get(x) == i:
                dsu.merge(x,fa[x])
        else:
            y = node[i]
            dsu._size[dsu.find(y)] -= 1
    for i in res[::-1]:
        print(i)
t = 1
t = ii()
for i in range(t):
    solve()
