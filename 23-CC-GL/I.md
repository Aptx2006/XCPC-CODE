## 🤖 Assistant

这是一道非常经典的**区间贡献转化**与**动态极值维护**的综合难题。通过分析，我们可以将看似复杂的 $\text{MEX}$ 变量转化为静态的区间查询。

下面我将为你带来这道题的高质量、超详细整合题解。

---

## 🏆 题目基本信息与核心切入点

* **题目难度**：⭐⭐⭐⭐（属于 Codeforces Div.2 E/F 级别，中高难度）
* **算法标签**：`数据结构`、`扫描线`、`莫队算法`、`树状数组`、`MEX`、`离线转化`

### 核心公式翻译
对于任意选择的队伍区间 $[l, r]$，其评分定义为：
$$\text{Score} = \text{区间内不同算法的数量} - \text{区间内无人掌握的最简单算法编号}$$

在算法竞赛中，“无人掌握的最简单正整数”有一个标准的术语叫 **MEX (Minimum Excluded)**。因此，队伍的得分公式可以化简为：
$$\text{Score} = \text{Distinct}(l, r) - \text{MEX}(l, r)$$

由于我们要让 $\text{Score}$ 最大，而 $\text{Distinct}$ 和 $\text{MEX}$ 都会随着区间的变化而发生复杂的联动，直接去枚举所有区间求极值会达到 $O(n^2)$ 的复杂度。**解决本题的终极核心思想就是：打破联结，化动为静。**

---

## 🛠️ 第一部分：莫队算法（分块离线思想）

### 1. 莫队算法思路分析

既然 $\text{MEX}$ 是个变量，我们不如**反过来枚举这个 $\text{MEX}$ 的值 $k$**。
假设某个区间 $[l, r]$ 的 $\text{MEX}$ 恰好等于 $k$，必须满足两个严苛的充要条件：
1. 算法 $1 \sim k-1$ **必须全部**在区间 $[l, r]$ 中出现过。
2. 算法 $k$ **绝对不能**在区间 $[l, r]$ 中出现。

既然算法 $k$ 绝不能出现，那么我们在原数组中找出所有值为 $k$ 的位置，这些位置就会把原数组切成若干个**不包含 $k$ 的“安全段”**。我们所求的区间 $[l, r]$ 必然只能完整地缩在某一个安全段内部。

#### 💡 关键贪心转化
在一个确定的 $k$-安全段内部，算法 $k$ 已经彻底消失了，此时区间的 $\text{MEX}$ 顶多就是 $k$。
为了让 $\text{Score} = \text{Distinct}(l, r) - k$ 最大，我们在当前的常数 $k$ 下，应该**尽可能让区间变大**，从而能吸纳更多其他的独特算法（增大 $\text{Distinct}$）。

因此，**被 $k$ 分割出来的每一个“极大安全段”本身，就是当前 $\text{MEX}=k$ 时的最优候选区间！**

通过这个结论，我们将“盲目枚举所有区间”变成了“精准测试以下特定区间”：
* **对于在数组中出现过的元素 $k$**：将其出现位置作为隔断，切出的所有极大区间 $[\text{pos}_i + 1, \text{pos}_{i+1} - 1]$ 作为询问加入队列（总区间数不超过 $2n$ 个）。
* **对于在数组中没出现过的元素**：为了让 $-k$ 尽可能大，我们只需要取最小的那个没出现过的元素（即整个数组的全局 $\text{MEX}$），将其对应的询问区间设为整个数组 $[1, n]$。

这样我们就得到了 $O(n)$ 个确定区间的“数颜色”（求不同元素个数）问题。直接套用**莫队算法**板子离线解决。

### 2. 莫队算法代码实现

```cpp
#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

const int MAXM = 500005;
int freq[MAXM]; // 全局频次数组

struct Query {
    int l, r, k, id;
    int block;
    // 奇偶块排序优化
    bool operator<(const Query& other) const {
        if (block != other.block) return block < other.block;
        return (block & 1) ? (r < other.r) : (r > other.r);
    }
};

struct Element {
    int val, id;
    bool operator<(const Element& other) const {
        if (val != other.val) return val < other.val;
        return id < other.id;
    }
};

void solve() {
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<Element> elems(n);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        elems[i - 1] = {a[i], i};
    }
    
    // 排序以便在 O(n) 内找出各元素的出现位置，防止多测受 m 的大小干扰
    sort(all(elems));
    
    // 计算整个数组的全局 MEX
    int g_mex = 1;
    int last_v = 0;
    for(auto &e : elems) {
        if (e.val == last_v) continue;
        last_v = e.val;
        if (e.val == g_mex) g_mex++;
        else if (e.val > g_mex) break;
    }
    
    vector<Query> queries;
    
    // 生成极大不包含 k 的安全区间询问
    int i = 0;
    while(i < n) {
        int j = i;
        while(j < n && elems[j].val == elems[i].val) j++;
        
        int val = elems[i].val;
        int prev_pos = 0;
        for(int idx = i; idx < j; idx++) {
            int cur_pos = elems[idx].id;
            if (prev_pos + 1 <= cur_pos - 1) {
                queries.push_back({prev_pos + 1, cur_pos - 1, val, (int)queries.size(), 0});
            }
            prev_pos = cur_pos;
        }
        if (prev_pos + 1 <= n) {
            queries.push_back({prev_pos + 1, n, val, (int)queries.size(), 0});
        }
        i = j;
    }
    // 别忘了全局 MEX 对应的全数组询问
    queries.push_back({1, n, g_mex, (int)queries.size(), 0});
    
    int q_num = queries.size();
    int block_size = max(1, (int)(n / sqrt(q_num + 1)));
    for(auto &q : queries) {
        q.block = q.l / block_size;
    }
    
    sort(all(queries));
    
    // 莫队双指针拓展
    int cur_l = 1, cur_r = 0;
    int current_distinct = 0;
    
    auto add_fn = [&](int idx) {
        if (freq[a[idx]] == 0) current_distinct++;
        freq[a[idx]]++;
    };
    
    auto del_fn = [&](int idx) {
        freq[a[idx]]--;
        if (freq[a[idx]] == 0) current_distinct--;
    };
    
    int max_score = -1e9;
    for(auto &q : queries) {
        while (cur_l > q.l) add_fn(--cur_l);
        while (cur_r < q.r) add_fn(++cur_r);
        while (cur_l < q.l) del_fn(cur_l++);
        while (cur_r > q.r) del_fn(cur_r--);
        
        max_score = max(max_score, current_distinct - q.k);
    }
    
    // 指针回滚清空全局数组，防止多测 TLE
    while (cur_l <= cur_r) del_fn(cur_l++);
    
    cout << max_score << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T ; T--; solve());
    return 0;
}
```

---

## 🚀 第二部分：树状数组+扫描线（在线树状结构思想）

### 1. 树状数组思路分析

除了莫队离线以外，我们同样可以从**另一个维度进行枚举**。这也是算法竞赛中处理区间颜色最主流的手段：**扫描线**。

如果我们枚举 $\text{MEX}$ 的值 $x$（同样考虑由 $x$ 分割出来的极长区间询问），这就等价于：我们现在手头有一堆固定的区间询问，我们需要在 $\Theta(n \log n)$ 级别的时间内求出所有区间的颜色总数。

#### 💡 扫描线基本原理
我们将所有询问按照**右端点 $r$ 从小到大排序**。我们让扫描线从左到右扫过整个数组：
* 当扫描线到达 $r$ 时，我们把当前位置的元素 $a[r]$ 激活。
* 为了避免同一种颜色在区间内被重复统计，**一个元素只有在它最后一次出现的位置才应该对答案产生贡献。**
* 因此，我们维护一个 `last` 数组，记录每种颜色上一次出现的位置。当遇到 $a[r]$ 时：
    1. 如果它之前出现过（即 `last[a[r]] != 0`），我们在树状数组的 `last[a[r]]` 位置 **$-1$**。
    2. 在当前新位置 $r$ 处 **$+1$**。
    3. 更新 `last[a[r]] = r`。

这样，当我们想知道某个左端点为 $l$ 的询问 $[l, r]$ 中有多少不同元素时，直接利用树状数组求 `query(r) - query(l - 1)` 即可，其本质就是统计当前有多少种颜色的“最后生存位置”落在 $[l, r]$ 内部。


因为这道题对 $m$ 的总和没有保证，如果直接给 $m$ 开大数组去记录位置会造成巨大的内存开销。我们可以利用 `vector` 动态存储每个元素的所有出现坐标，以此在极低的空间内完成询问生成与扫描线统计。

### 2. 树状数组代码实现

```cpp
#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
#define all(x) (x).begin(), (x).end()

// 树状数组模板
struct Fenwick {
    int n;
    vector<int> tree;
    Fenwick(int num) : n(num), tree(num + 1, 0) {}
    
    void add(int i, int delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    
    // 关键优化：MEX 最大不可能超过 n + 1
    int K_max = min(m + 1, n + 1);
    
    // 记录每个值在数组中出现的所有位置
    vector<vector<int>> pos(K_max + 1);
    for (int i = 1; i <= K_max; i++) {
        pos[i].push_back(0); // 左哨兵
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] <= K_max) {
            pos[a[i]].push_back(i);
        }
    }
    
    for (int i = 1; i <= K_max; i++) {
        pos[i].push_back(n + 1); // 右哨兵
    }
    
    // 离线存储询问：queries[R] 存储所有右端点为 R 的询问 {L, k}
    vector<vector<pair<int, int>>> queries(n + 1);
    for (int k = 1; k <= K_max; k++) {
        for (size_t i = 0; i < pos[k].size() - 1; i++) {
            int L = pos[k][i] + 1;
            int R = pos[k][i + 1] - 1;
            if (L <= R) {
                queries[R].push_back({L, k});
            }
        }
    }
    
    // 离散化 a 数组，用于树状数组去重（防止 a[i] 很大导致 last 数组爆内存）
    vector<int> vals = a;
    sort(vals.begin() + 1, vals.end());
    vals.erase(unique(vals.begin() + 1, vals.end()), vals.end());
    
    Fenwick bit(n);
    vector<int> last(vals.size() + 1, 0);
    int max_score = -2e9; // 初始化为极小值
    
    // 扫描线过程
    for (int r = 1; r <= n; r++) {
        int dc_id = lower_bound(vals.begin() + 1, vals.end(), a[r]) - vals.begin();
        
        if (last[dc_id] != 0) {
            bit.add(last[dc_id], -1); // 抹除旧位置贡献
        }
        bit.add(r, 1); // 激活当前位置贡献
        last[dc_id] = r;
        
        // 结算所有以当前 r 结尾的极长区间询问
        for (auto& q : queries[r]) {
            int L = q.first;
            int k = q.second;
            int distinct_cnt = bit.query(r) - bit.query(L - 1);
            max_score = max(max_score, distinct_cnt - k);
        }
    }
    
    cout << max_score << "\n";
}

int main() {
    // 极致 I/O 优化
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
```

---

## ⚖️ 两种解法大比拼

| 指标 | 莫队算法解法 | 树状数组+扫描线解法 |
| :--- | :--- | :--- |
| **时间复杂度** | $\Theta(n \sqrt{n})$ | $\Theta(n \log n)$（运行速度更快） |
| **空间复杂度** | $\Theta(n)$ | $\Theta(n + m)$ |
| **思维核心** | 利用分块双指针暴力挪动维护频次 | 利用单点修改、前缀和动态提取区间贡献 |
| **多测清空** | 依靠双指针回滚实现 $O(\text{区间长度})$ 极其优雅的清空 | 依靠动态 `vector` 的生命周期，自动销毁 |
