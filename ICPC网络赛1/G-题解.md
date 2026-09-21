# G. Toll Gates on a Tight Schedule

## 1. 题面简述

给定一张有 $n$ 个点、$m$ 条有向边的图，每经过一条边需要一分钟，每个点 $i$ 有一个收费 $c_i$。

现在需要从点 $1$ 到达点 $n$，只考虑经过边数最少的路线。求这些最短路线中，经过点的费用之和不超过 $C$ 的路线数量。起点和终点的费用也需要计算，答案对 $2^{64}$ 取模。

## 2. 分析

### 2.1 建出最短路 DAG

注意到每条边的长度都是 $1$，因此可以分别从点 $1$ 和点 $n$ 在反图上进行 BFS，得到：

- $d_1[u]$：从点 $1$ 到点 $u$ 的最短距离；
- $d_n[u]$：从点 $u$ 到点 $n$ 的最短距离。

设从 $1$ 到 $n$ 的最短距离为 $D$。一条边 $u\to v$ 能出现在某条最短路中，当且仅当

$$
d_1[u]+1+d_n[v]=D.
$$

只保留这些边。沿着保留下来的每条边，$d_1$ 都恰好增加 $1$，所以新图是一个按照 $d_1$ 分层的 DAG。每条最短路线都会依次在每一层选择一个点。

### 2.2 折半枚举

费用 $C$ 很大，不能把费用作为背包维度；最短路径的数量也可能非常多，不能完整枚举。

观察到 $n\le 90$，适合使用折半搜索。这里不在某个点处拼接，而是在相邻两层之间选择一条“分界线”：

- 从点 $1$ 出发，枚举到达分界线左侧各点的所有前半段路径费用；
- 从点 $n$ 沿反图出发，枚举到达分界线右侧各点的所有后半段路径费用。

为什么要把分界线放在两层之间，而不是直接选一层作为中点？如果相邻两层之间的边很多，路径数量可能在跨过这一层时突然膨胀。在边上拼接可以停在膨胀发生之前，避免一侧产生大量不必要的半路径。

为了让两边的枚举量尽量均衡，可以先在最短路 DAG 上计算到达每个点的路径数量，以及每个点到终点的路径数量。枚举所有相邻层，根据生成半路径、排序以及跨边配对的次数估算总工作量，选择估算工作量最小的分界线。相比只按路径条数选择中间层，这样可以避开跨层边很多、配对开销很大的位置。

所有点费均非负。如果一条半路径的费用已经大于 $C$，继续延伸也不可能合法，可以立刻剪枝。

### 2.3 合并答案

假设分界线位于第 $k$ 层和第 $k+1$ 层之间。对于一条跨越分界线的边 $x\to y$，设：

- `left[x]` 保存 $1\to x$ 的前半段费用；
- `right[y]` 保存 $y\to n$ 的后半段费用。

两段路径没有重复计算任何点，因此完整费用直接为

$$
L+R.
$$

合法条件为

$$
L+R\le C,
$$

也就是

$$
R\le C-L.
$$

将分界线两边的费用数组排序。对于每条跨层边，有两种合并方法：

- 两个数组大小相差较大时，枚举较小的数组，在较大的数组中使用 `upper_bound`；
- 两个数组大小接近时，直接使用双指针线性统计。

程序会根据两个数组的大小选择估算操作次数更少的一种。每条最短路线只会经过一条分界线上的边，所以不会重复统计。

题目要求答案对 $2^{64}$ 取模。C++ 的 `unsigned long long` 即 `u64` 运算会自然对 $2^{64}$ 取模，因此直接用 `u64` 累加答案即可，不需要额外取模。

设所有中间点中较少一侧的路径总数为 $P_{\min}$，较多一侧的路径总数为 $P_{\max}$，则时间复杂度可以写为

$$
O(n+m+P_{\min}\log P_{\min}+P_{\max}\log P_{\min}),
$$

空间复杂度为 $O(n+m+P_L+P_R)$。其中排序与二分是分别对每个中间点进行的，上式省略了各个中间点下标，写成了方便理解的整体上界。

## 3. 代码

<details>
<summary>点击查看代码</summary>

```cpp
#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    i64 C;
    cin >> n >> m >> C;
    vector<i64> c(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    vector<vector<int>> g(n + 1), rg(n + 1);
    vector<pair<int, int>> e(m);
    for (auto &[u, v]: e) {
        cin >> u >> v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    auto bfs = [&](int s, const vector<vector<int>> &G) {
        vector<int> dis(n + 1, -1);
        queue<int> q;
        dis[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto y: G[x]) {
                if (dis[y] == -1) {
                    dis[y] = dis[x] + 1;
                    q.push(y);
                }
            }
        }
        return dis;
    };

    auto d1 = bfs(1, g);
    auto dn = bfs(n, rg);
    if (d1[n] == -1) {
        cout << 0 << '\n';
        return;
    }

    int D = d1[n];
    if (D == 0) {
        cout << u64(c[1] <= C) << '\n';
        return;
    }
    vector<vector<int>> dag(n + 1), rdag(n + 1), layer(D + 1);
    for (auto [u, v]: e) {
        if (d1[u] != -1 && dn[v] != -1 && d1[u] + 1 + dn[v] == D) {
            dag[u].push_back(v);
            rdag[v].push_back(u);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (d1[i] != -1 && dn[i] != -1 && d1[i] + dn[i] == D) {
            layer[d1[i]].push_back(i);
        }
    }

    const u64 inf = numeric_limits<u64>::max();
    auto add = [&](u64 x, u64 y) {
        return inf - x < y ? inf : x + y;
    };
    vector<u64> pre(n + 1), suf(n + 1);
    pre[1] = suf[n] = 1;
    for (int i = 0; i < D; i++) {
        for (auto x: layer[i]) {
            for (auto y: dag[x]) pre[y] = add(pre[y], pre[x]);
        }
    }
    for (int i = D; i > 0; i--) {
        for (auto x: layer[i]) {
            for (auto y: rdag[x]) suf[y] = add(suf[y], suf[x]);
        }
    }

    int mid = 0;
    i128 best = -1;
    auto lg = [&](u64 x) {
        return 64 - __builtin_clzll(x);
    };
    for (int i = 0; i < D; i++) {
        u64 x = 0, y = 0;
        for (auto v: layer[i]) {
            x = add(x, pre[v]);
        }
        for (auto v: layer[i + 1]) y = add(y, suf[v]);
        i128 work = i128(x) + y;
        for (auto v: layer[i]) work += i128(pre[v]) * lg(pre[v]);
        for (auto v: layer[i + 1]) work += i128(suf[v]) * lg(suf[v]);
        for (auto u: layer[i]) {
            for (auto v: dag[u]) {
                u64 a = pre[u], b = suf[v];
                u64 small = min(a, b), large = max(a, b);
                work += min(i128(small) * lg(large), i128(a) + b);
            }
        }
        if (best == -1 || work < best) {
            best = work;
            mid = i;
        }
    }

    vector<vector<i64>> left(n + 1), right(n + 1);
    auto dfs1 = [&](auto &&self, int x, i64 sum) -> void {
        if (sum > C) return;
        if (d1[x] == mid) {
            left[x].push_back(sum);
            return;
        }
        for (auto y: dag[x]) self(self, y, sum + c[y]);
    };
    auto dfs2 = [&](auto &&self, int x, i64 sum) -> void {
        if (sum > C) return;
        if (d1[x] == mid + 1) {
            right[x].push_back(sum);
            return;
        }
        for (auto y: rdag[x]) self(self, y, sum + c[y]);
    };
    dfs1(dfs1, 1, c[1]);
    dfs2(dfs2, n, c[n]);

    u64 res = 0;
    for (auto x: layer[mid]) sort(all(left[x]));
    for (auto x: layer[mid + 1]) sort(all(right[x]));
    for (auto x: layer[mid]) {
        for (auto y: dag[x]) {
            auto &a = left[x], &b = right[y];
            if (a.empty() || b.empty()) continue;
            auto *small = &a, *large = &b;
            if (small->size() > large->size()) swap(small, large);
            int log = 64 - __builtin_clzll(large->size());
            if (small->size() * log <= small->size() + large->size()) {
                for (auto sum: *small) {
                    res += upper_bound(all(*large), C - sum) - large->begin();
                }
            } else {
                size_t p = large->size();
                for (auto sum: *small) {
                    while (p && large->at(p - 1) > C - sum) p--;
                    res += p;
                }
            }
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
```

</details>

## Tag

`最短路` `BFS` `DAG` `Meet-in-the-Middle` `折半搜索` `二分`
