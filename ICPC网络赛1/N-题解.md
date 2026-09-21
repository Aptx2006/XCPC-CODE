# N 题解

## 题意

有一个长度为 $n$ 的序列，每个位置可能放有红、黄、蓝三种棋子中的若干种。

我们需要把整个序列划分成若干个连续段。如果某一段中红色棋子的数量同时不少于黄色和蓝色棋子的数量，那么这一段就是红色段。

求所有红色段的长度之和最大是多少。

## 思路

### 1. 朴素动态规划

令 $f_i$ 表示前 $i$ 个位置中，能够被红色段覆盖的最大长度。

考虑最后一个位置：

- 不让位置 $i$ 属于红色段，此时答案为 $f_{i-1}$；
- 枚举一个 $j<i$，如果区间 $(j,i]$ 是红色段，就可以从 $f_j$ 转移过来，答案为 $f_j+i-j$。

于是有

$$
f_i=\max\left(f_{i-1},\max_{0\le j<i,\ (j,i]\text{ 合法}}(f_j+i-j)\right).
$$

直接枚举 $j$ 的时间复杂度为 $O(n^2)$，无法通过本题。

### 2. 用二维前缀差判断区间是否合法

注意到一段区间需要同时满足

$$
R\ge Y,\qquad R\ge B.
$$

定义两种前缀差：

$$
x_i=\sum_{k=1}^{i}(r_k-y_k),\qquad
y_i=\sum_{k=1}^{i}(r_k-b_k).
$$

那么区间 $(j,i]$ 是红色段，当且仅当

$$
x_j\le x_i,\qquad y_j\le y_i.
$$

由此可知，原来的区间判断转化成了一个二维偏序查询。

为了让转移更自然，令

$$
g_i=i-f_i,
$$

表示前 $i$ 个位置中最少有多少个位置没有被红色段覆盖。

对于一段合法区间 $(j,i]$，有

$$
i-(f_j+i-j)=j-f_j=g_j.
$$

所以转移变为

$$
g_i=\min\left(g_{i-1}+1,\min_{0\le j<i,\ x_j\le x_i,\ y_j\le y_i}g_j\right).
$$

现在只需要维护所有已经出现的点 $(x_j,y_j)$，每次查询矩形

$$
(-\infty,x_i]\times(-\infty,y_i]
$$

中的最小 $g_j$。

### 3. 树状数组套树状数组

外层树状数组维护 $x$，每个外层节点再放一个维护 $y$ 的树状数组。

由于所有前缀点可以提前得到，我们先把一个点在外层更新时会经过的所有节点找出来，把它的 $y$ 坐标放入对应节点中，排序去重后建立内层树状数组。

内层 BIT 直接复用 WIDA 的一维 BIT 模板，只进行两处必要调整：

- 原来的权值求和改成取最小值；
- 原来的前缀和查询改成前缀最小值查询。

一次修改和一次查询都会经过两层 BIT，所以时间复杂度为 $O(\log^2 n)$。

还有一个简单优化：如果本次二维查询得到的 `best` 已经成为 $g_i$，那么一定存在一个更早的点 $(x_j,y_j)$ 满足

$$
x_j\le x_i,\qquad y_j\le y_i,qquad g_j=g_i.
$$

以后凡是能从点 $i$ 转移到的位置，也一定能从点 $j$ 转移过去，因此点 $i$ 永远不会更优，不必插入数据结构。只有 `g[i - 1] + 1` 严格更小时，才需要插入当前点。

最终答案为

$$
n-g_n.
$$

## 正确性证明

首先，由前缀差的定义可知，区间 $(j,i]$ 中红色棋子不少于黄色棋子，当且仅当 $x_i-x_j\ge 0$；红色棋子不少于蓝色棋子，当且仅当 $y_i-y_j\ge 0$。因此，$(j,i]$ 是红色段当且仅当 $x_j\le x_i$ 且 $y_j\le y_i$。

考虑 $g_i$ 的转移。如果位置 $i$ 不被红色段覆盖，需要在前 $i-1$ 个位置的最优方案后额外舍弃一个位置，代价为 $g_{i-1}+1$。如果最后一段是合法区间 $(j,i]$，那么这一整段都被覆盖，未覆盖位置的数量仍为 $g_j$。所有方案必然属于这两种情况之一，因此转移式能够得到真正的最小未覆盖位置数。

二维 BIT 在处理位置 $i$ 时只保存更早位置的状态，并返回所有满足 $x_j\le x_i$、$y_j\le y_i$ 的状态中的最小 $g_j$，恰好计算了转移式的第二部分。

对于没有插入的点 $i$，已经存在一个更早、坐标均不大于它且代价不大的点 $j$。任意未来状态如果能够由 $i$ 转移，也一定能够由 $j$ 以不更大的代价转移，所以删除这个冗余状态不会影响后续答案。

综上，算法计算出的 $g_n$ 是最少未覆盖位置数，故输出的 $n-g_n$ 就是红色段长度之和的最大值。

## 复杂度

- 时间复杂度：$O(n\log^2 n)$；
- 空间复杂度：$O(n\log n)$。

## 其他可行算法

### CDQ 分治

也可以按照下标进行 CDQ 分治。先求出左半部分的 DP，再把左半部分的点按 $x$ 排序，用一维 BIT 扫描 $y$，更新右半部分。它同样是在处理三维关系“下标更小、$x$ 更小、$y$ 更小”，时间复杂度一般也是 $O(n\log^2 n)$。

这种写法能够减少长期保存的二维结构，但分治、排序和清空 BIT 的实现更复杂。

### 线段树套平衡树

还可以用外层线段树维护 $x$，每个节点用平衡树或内层线段树维护 $y$ 的前缀最小值，复杂度同样为 $O(n\log^2 n)$。不过代码和常数通常都比离线建好的 BIT 套 BIT 更大。

## 代码

```cpp
#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

struct BIT {
    const int inf = 1e9;
    vector<int> w;
    int n;

    BIT(int n = 0) : n(n), w(n + 1, inf) {}
    void init(int n_) {
        n = n_;
        w.assign(n + 1, inf);
    }
    void add(int x, int v) {
        for (; x <= n; x += x & -x) {
            w[x] = min(w[x], v);
        }
    }
    int ask(int x) {
        int ans = inf;
        for (; x; x -= x & -x) {
            ans = min(ans, w[x]);
        }
        return ans;
    }
};

struct BIT2D {
    const int inf = 1e9;
    int n;
    vector<vector<int>> ys;
    vector<BIT> w;

    BIT2D(int n, const vector<int> &x, const vector<int> &y) : n(n), ys(n + 1), w(n + 1) {
        for (int j = 0; j < (int)x.size(); j++) {
            for (int i = x[j]; i <= n; i += i & -i) {
                ys[i].push_back(y[j]);
            }
        }
        for (int i = 1; i <= n; i++) {
            sort(all(ys[i]));
            ys[i].erase(unique(all(ys[i])), ys[i].end());
            w[i].init(ys[i].size());
        }
    }

    void add(int x, int y, int v) {
        for (int i = x; i <= n; i += i & -i) {
            int p = lower_bound(all(ys[i]), y) - ys[i].begin() + 1;
            w[i].add(p, v);
        }
    }

    int ask(int x, int y) {
        int res = inf;
        for (int i = x; i; i -= i & -i) {
            int p = upper_bound(all(ys[i]), y) - ys[i].begin();
            res = min(res, w[i].ask(p));
        }
        return res;
    }
};

void work() {
    cin >> n;
    vector<int> x(n + 1), y(n + 1);
    int mn = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        x[i] = x[i - 1] + r - a;
        y[i] = y[i - 1] + r - b;
        mn = min(mn, x[i]);
        mx = max(mx, x[i]);
    }
    for (auto &v: x) v -= mn - 1;

    BIT2D bit(mx - mn + 1, x, y);
    bit.add(x[0], y[0], 0);
    int cost = 0;
    for (int i = 1; i <= n; i++) {
        int best = bit.ask(x[i], y[i]);
        int nxt = min(cost + 1, best);
        if (nxt < best) bit.add(x[i], y[i], nxt);
        cost = nxt;
    }
    cout << n - cost << '\n';
}

void solve() {
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
#if 0
    for(cin >> T; T--; solve());
#endif
    return 0;
}
```

## Tag

`动态规划` `前缀和` `二维偏序` `树状数组套树状数组` `离散化`
