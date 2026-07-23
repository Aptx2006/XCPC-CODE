# CF19E Fairy 题解

## 题目大意

给定一个无向图，有 `n` 个点和 `m` 条边。

现在要删除恰好一条边，问有哪些边满足：

> 删除这条边之后，剩下的图是二分图。

输出所有满足条件的边的编号，边编号按照输入顺序从 `1` 开始。

---

## 算法 Tag

- 二分图判定
- 带权并查集
- 异或并查集
- 可回滚并查集
- 根号分块

---

## 解题思路

这道题的核心是判断：

> 删掉某条边后，整张图是否可以二染色。

二分图的等价条件是：每条边连接的两个点颜色不同。

如果我们用 `0 / 1` 表示两种颜色，那么对于每条边 `(u, v)`，都应该满足：

```cpp
color[u] ^ color[v] = 1
```

因此可以用带权并查集维护这种异或关系。

---

## 1. 暴力想法

最直接的方法是枚举每条边 `del`：

1. 删除这条边；
2. 用剩下的 `m - 1` 条边判断图是否二分图。

复杂度大约是：

```text
O(m^2)
```

因为 `m <= 10000`，`1e8` 左右的操作可能会比较危险。

所以代码中用了一个根号分块优化。

---

## 2. 带权并查集维护二分图

在你的代码中，并查集结构是：

```cpp
vector<int> fa, sz, xr;
```

含义分别是：

- `fa[x]`：并查集父亲；
- `sz[x]`：集合大小，用于按大小合并；
- `xr[x]`：`x` 到 `fa[x]` 的颜色异或值。

`find(x)` 返回：

```cpp
{root, x 到 root 的异或值}
```

代码如下：

```cpp
pair<int, int> find(int x) {
    int p = 0;
    while(fa[x] != x) {
        p ^= xr[x];
        x = fa[x];
    }
    return {x, p};
}
```

注意这里没有路径压缩，因为这个并查集需要支持回滚。

---

## 3. 加入一条边

加入边 `(u, v)` 时，需要满足：

```cpp
color[u] ^ color[v] = 1
```

代码中对应函数是：

```cpp
void add(int u, int v)
```

先找到 `u` 和 `v` 所在集合的根：

```cpp
auto [x, px] = find(u);
auto [y, py] = find(v);
```

其中：

- `x` 是 `u` 所在集合的根；
- `px` 是 `u` 到根 `x` 的颜色异或值；
- `y` 是 `v` 所在集合的根；
- `py` 是 `v` 到根 `y` 的颜色异或值。

---

### 情况一：`u` 和 `v` 已经在同一集合

如果 `x == y`，说明之前已经确定了 `u` 和 `v` 的相对颜色。

此时只需要检查：

```cpp
if((px ^ py) != 1) ++bad;
```

如果 `px ^ py != 1`，说明这条边要求它们颜色不同，但当前关系却不是不同，出现矛盾。

这里的 `bad` 表示当前图中有多少个二分图冲突。

只要：

```cpp
bad == 0
```

当前图就是二分图。

---

### 情况二：`u` 和 `v` 不在同一集合

如果 `x != y`，说明这条边可以把两个集合合并。

代码中使用按大小合并：

```cpp
if(sz[x] < sz[y]) {
    swap(x, y);
    swap(px, py);
}
```

然后把根 `y` 接到根 `x` 下面：

```cpp
fa[y] = x;
xr[y] = px ^ py ^ 1;
sz[x] += sz[y];
```

为什么是：

```cpp
xr[y] = px ^ py ^ 1;
```

因为需要保证：

```cpp
color[u] ^ color[v] = 1
```

而：

```cpp
color[u] ^ color[x] = px
color[v] ^ color[y] = py
```

合并后需要确定 `color[y] ^ color[x]`，推导后就是：

```cpp
color[y] ^ color[x] = px ^ py ^ 1
```

因此：

```cpp
xr[y] = px ^ py ^ 1;
```

---

## 4. 为什么需要可回滚？

在分块时，对于同一个块内的每一条候选删除边，我们都要临时加入一些边，然后恢复到原来的状态。

所以需要支持：

```cpp
保存状态
尝试加入边
回滚状态
```

你的代码中用 `his` 记录每次真正合并时的信息：

```cpp
struct upd {
    int x, y, sx, py;
};
```

含义是：

- `x`：被挂上去的根；
- `y`：新的父亲根；
- `sx`：合并前 `y` 的集合大小；
- `py`：合并前 `x` 的 `xr` 值。

保存状态：

```cpp
qry save() const {
    return {(int)his.size(), bad};
}
```

回滚状态：

```cpp
void back(qry s) {
    while((int)his.size() > s.h) {
        auto c = his.back();
        his.pop_back();
        fa[c.x] = c.x;
        xr[c.x] = c.py;
        sz[c.y] = c.sx;
    }
    bad = s.bad;
}
```

这里除了恢复并查集结构，还要恢复 `bad`。

这是因为加入一条边时，如果两个点已经在同一集合中，可能只会让 `bad++`，但不会产生一次合并，也就不会进入 `his`。

---

## 5. 根号分块优化

代码中：

```cpp
int B = max(1,(int)sqrt(m) + 1);
```

将所有边按照编号分块，每块大小大约是 `sqrt(m)`。

对于一个块 `[L, R)`，做如下操作：

### 第一步：先加入块外所有边

```cpp
DSU uf(n);

for(int i = 0; i < m; i++) {
    if(i < L or i >= R) uf.add(e[i].first, e[i].second);
}
```

这部分边对于当前块内所有要删除的边来说都是公共的。

也就是说，如果我们枚举删除的是块内某条边，那么块外所有边一定都会保留。

---

### 第二步：如果块外边已经不二分，直接跳过

```cpp
if(uf.bad) continue;
```

如果只看块外边就已经有冲突，那么删除块内任意一条边都无法消除这个冲突。

所以当前块内所有边都不可能是答案。

---

### 第三步：枚举块内要删除的边

```cpp
for(int del = L; del < R; del++) {
    auto s = uf.save();

    for(int i = L; i < R; i++) {
        if(i == del) continue;
        uf.add(e[i].first, e[i].second);
        if(uf.bad) break;
    }

    if(!uf.bad) res.push_back(del + 1);
    uf.back(s);
}
```

对于当前要删除的边 `del`：

- 块外边之前已经全部加入；
- 块内边除了 `del` 以外全部加入；
- 因此当前并查集表示的正好是删掉 `del` 后的图。

如果最后：

```cpp
uf.bad == 0
```

说明删掉这条边后，图是二分图，于是加入答案：

```cpp
res.push_back(del + 1);
```

注意边在代码中是 `0` 下标存储，所以输出时需要 `+1`。

---

## 时空复杂度分析

设块大小为 `B`。

每个块都要重新加入所有块外边，复杂度约为：

```text
O(m)
```

一共有大约：

```text
m / B
```

个块，所以这部分复杂度是：

```text
O(m^2 / B)
```

对于每个块，枚举块内每条删除边，每次最多再加入 `B` 条块内边，所以每块复杂度约为：

```text
O(B^2)
```

所有块这部分复杂度是：

```text
O(mB)
```

因此总复杂度为：

```text
O((m^2 / B + mB) log n)
```

取：

```text
B = sqrt(m)
```

得到：

```text
O(m sqrt(m) log n)
```

由于 `m <= 10000`，这个复杂度可以通过。

空间复杂度：

```text
O(n + m)
```

主要来自：

- 存边数组；
- 并查集数组；
- 回滚历史数组；
- 答案数组。

---

## 具体实现

```cpp
#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x)(x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " <<(x) << endl;

int T, n, m, k, ans, cnt;

struct DSU {
    struct upd {
        int x, y, sx, py;
    };

    struct qry {
        int h, bad;
    };

    vector<int> fa, sz, xr;
    vector<upd> his;
    int bad = 0;

    DSU(int n) {
        fa.resize(n + 1);
        sz.assign(n + 1, 1);
        xr.assign(n + 1, 0);
        his.clear();
        bad = 0;
        for(int i = 1; i <= n; i++) fa[i] = i;
    }

    pair<int, int> find(int x) {
        int p = 0;
        while(fa[x] != x) {
            p ^= xr[x];
            x = fa[x];
        }
        return {x, p};
    }

    void add(int u, int v) {
        auto [x, px] = find(u);
        auto [y, py] = find(v);

        if(x == y) {
            if((px ^ py) != 1) ++bad;
            return;
        }

        if(sz[x] < sz[y]) {
            swap(x, y);
            swap(px, py);
        }

        his.push_back({y, x, sz[x], xr[y]});
        fa[y] = x;
        xr[y] = px ^ py ^ 1;
        sz[x] += sz[y];
    }

    qry save() const {
        return {(int)his.size(), bad};
    }

    void back(qry s) {
        while((int)his.size() > s.h) {
            auto c = his.back();
            his.pop_back();
            fa[c.x] = c.x;
            xr[c.x] = c.py;
            sz[c.y] = c.sx;
        }
        bad = s.bad;
    }

    bool ok() const {
        return bad == 0;
    }
};

void solve() {
    cin >> n >> m;

    vector<pair<int, int>> e(m);
    for(auto &x : e) cin >> x.first >> x.second;

    vector<int> res;
    int B = max(1,(int)sqrt(m) + 1);

    for(int L = 0; L < m; L += B) {
        int R = min(m, L + B);
        DSU uf(n);

        for(int i = 0; i < m; i++) {
            if(i < L or i >= R) uf.add(e[i].first, e[i].second);
        }

        if(uf.bad) continue;

        for(int del = L; del < R; del++) {
            auto s = uf.save();

            for(int i = L; i < R; i++) {
                if(i == del) continue;
                uf.add(e[i].first, e[i].second);
                if(uf.bad) break;
            }

            if(!uf.bad) res.push_back(del + 1);
            uf.back(s);
        }
    }

    cout << res.size() << '\n';
    for(auto &id : res) cout << id << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(T = 1; T--; solve());
    return 0;
}
```

---

## 小结

这份代码没有使用 CF19E 的经典 DFS 奇环覆盖做法，而是利用了 `m <= 10000` 的数据范围，采用：

```text
根号分块 + 可回滚带权并查集
```

对于每条边，它本质上都在判断：

```text
删除这条边后，剩余边的异或约束是否无矛盾
```

如果无矛盾，则删掉这条边后图可以二染色，也就是答案边。
