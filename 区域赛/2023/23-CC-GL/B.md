## 🤖 Assistant

# B. The Game 题解

## 题目大意

给定两个多重集 $A$（大小 $n$）和 $B$（大小 $m$，$m \le n$）。每次操作：选择一个 $x \in A$，将 $x$ 改为 $x+1$，然后删除 $A$ 中的最小元素（若有多个则只删一个）。问能否通过若干次操作使 $A=B$，若能则输出操作序列（每次选的 $x$），否则输出 $-1$。

## 思路

### 关键性质

1. **相对顺序不变**：排序后，每次操作选择最靠右的 $x$ 可使所有数字的相对顺序保持不变。因此最终 $A$ 中最大的 $m$ 个元素依次匹配 $B$ 中的元素。

2. **可行性条件**（排序后）：
   - 对每个 $i \in [1,m]$，有 $A_{n-m+i} \le B_i$（只能增加，不能减少）
   - $\sum B - \sum \text{maxM}(A) \le n-m$（总增量不能超过操作次数）

3. **两阶段策略**：
   - **阶段一（冗余操作）**：当"所需增量"＜"剩余操作次数"时，操作最小元素（属于将被删除的部分），消耗多余的操作次数。用**对顶 set** 维护"保留集"（最大的 $m$ 个）和"删除集"（其余），每次选删除集的最小值。
   - **阶段二（必要操作）**：当所需增量 $=$ 剩余操作次数时，从大到小依次将保留集中的元素提升至目标值 $B_i$。

4. 若模拟过程中出现 $kk_i > B_i$ 或最终保留集不等于 $B$，则无解。

### 算法流程

1. 排序 $A$ 和 $B$，检查两个可行性条件，不满足则输出 `-1`。
2. 建立对顶 set：`keep`（最大的 $m$ 个）和 `del`（其余），维护 `sumKeep`。
3. 设 $remaining = n-m$。
4. **阶段一**：当 `sumB - sumKeep < remaining` 时，选 `del` 最小值 $x$ 记录，执行 $x \to x+1$（插入到对应集合），删除全局最小值，`rebalance` 保持 `|keep| = m`。
5. 检查阶段一后是否 $kk_i > B_i$，若是则无解。
6. **阶段二**：提取 `keep` 为有序数组 $kk$，从大到小将每个 $kk_i$ 提升至 $B_i$，同步删除 `del` 的最小值。
7. 最终检查 $kk = B$，输出操作序列。

### 复杂度

- **时间复杂度**：$\mathcal{O}(n \log n + m \log m)$。所有测试用例的 $n,m$ 总和 $\le 3\times 10^5$，对顶 set 的每次操作 $\mathcal{O}(\log n)$。
- **空间复杂度**：$\mathcal{O}(n + m)$。

---

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    sort(all(a));
    sort(all(b));

    // 可行性检查 1：对应位置不能超过目标
    for (int i = 0; i < m; i++) {
        if (a[n - m + i] > b[i]) {
            cout << "-1\n";
            return;
        }
    }

    i64 sumB = accumulate(all(b), 0LL);
    i64 sumKeep = accumulate(a.begin() + (n - m), a.end(), 0LL);

    // 可行性检查 2：总增量不超过操作次数
    if (sumB - sumKeep > n - m) {
        cout << "-1\n";
        return;
    }

    // 对顶 set：keep = 最大的 m 个，del = 其余
    multiset<int> keep, del;
    for (int i = 0; i < n - m; i++) del.insert(a[i]);
    for (int i = n - m; i < n; i++) keep.insert(a[i]);

    i64 curSumKeep = sumKeep;
    vector<int> ops;
    int remaining = n - m;

    // 保持 |keep| == m
    auto rebalance = [&]() {
        while (keep.size() < m && !del.empty()) {
            auto it = prev(del.end());
            int v = *it;
            del.erase(it);
            keep.insert(v);
            curSumKeep += v;
        }
        while (keep.size() > m) {
            auto it = keep.begin();
            int v = *it;
            keep.erase(it);
            curSumKeep -= v;
            del.insert(v);
        }
    };

    // 阶段一：冗余操作（消耗多余步数）
    while (remaining > 0 && sumB - curSumKeep < remaining) {
        int x = *del.begin();
        ops.push_back(x);
        del.erase(del.begin());

        int nx = x + 1;
        if (!keep.empty() && nx > *keep.begin()) {
            keep.insert(nx);
            curSumKeep += nx;
        } else {
            del.insert(nx);
        }

        // 删除全局最小值
        if (!del.empty()) {
            del.erase(del.begin());
        } else {
            auto it = keep.begin();
            curSumKeep -= *it;
            keep.erase(it);
        }

        rebalance();
        remaining--;
    }

    // 检查阶段一后是否违规
    {
        vector<int> kk(all(keep));
        for (int i = 0; i < m; i++) {
            if (kk[i] > b[i]) {
                cout << "-1\n";
                return;
            }
        }
    }

    // 阶段二：必要操作（精确提升保留集元素）
    if (remaining > 0) {
        vector<int> kk(all(keep));
        for (int i = m - 1; i >= 0 && remaining > 0; i--) {
            while (kk[i] < b[i] && remaining > 0) {
                ops.push_back(kk[i]);
                kk[i]++;
                if (!del.empty()) {
                    del.erase(del.begin());
                }
                remaining--;
            }
        }
        if (kk != b) {
            cout << "-1\n";
            return;
        }
    } else {
        vector<int> kk(all(keep));
        if (kk != b) {
            cout << "-1\n";
            return;
        }
    }

    // 输出
    cout << ops.size() << "\n";
    for (size_t i = 0; i < ops.size(); i++) {
        cout << ops[i] << " \n"[i + 1 == ops.size()];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (cin >> T; T--; solve());
    return 0;
}
```

---

## 标签

`贪心` `数据结构` `对顶堆/对顶set` `模拟` `排序`

## 难度

$\star\star\star$（中等偏难，ICPC 区域赛 C/D 题水平）
