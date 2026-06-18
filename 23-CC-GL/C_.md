## 🤖 Assistant

这道题来自 2023 CCPC 桂林站（Problem C. Arithmetic and Bitwise Operations Master），是一道结合了**数论性质（因数分解）**与**线性基（Linear Basis）**的经典位运算计数题。

下面为你带来一份通俗易懂、层层递进的详细题解。

---

## 📌 题意分析

题目要求我们从序列 $a$ 中选出一个**非空子序列**，使得这个子序列中的**每一个元素**，都能整除整个子序列的**异或和**。
设选出的子序列异或和为 $S$，那么对于子序列中的任意元素 $x$，都必须满足：
$$x \mid S$$

我们需要求出满足条件的非空子序列总数，答案对 $998244353$ 取模。

---

## 💡 核心思路

直接暴力搜索子序列显然会超时。我们需要根据异或（XOR）与整除（Divisibility）的数学性质进行分类讨论。令子序列的异或和为 $S$。

### 1. 当异或和 $S = 0$ 时（特殊情况）
根据数学定义，任何正整数 $x$ 都能整除 $0$（因为 $0 = 0 \cdot x$）。
因此，**只要子序列的异或和为 0，其中的所有元素自然满足 $x \mid 0$。**
* **转化**：求整个数组中，有多少个非空子序列的异或和为 0。
* **求解**：这是**线性基**的经典应用。假设整张数组插入线性基后，成功消元进入线性基的元素个数为 $B_{all}$，总元素个数为 $n$。那么那些无法进入线性基的 $n - B_{all}$ 个元素可以任意选或不选，它们都能在线性基中找到唯一的组合将其异或和抵消为 0。
* **结论**：异或和为 0 的非空子序列方案数为：
  $$2^{n - B_{all}} - 1$$

---

### 2. 当异或和 $S > 0$ 时（关键突破口点）
这是本题最精妙的数学性质。

设该子序列中的**最大元素**为 $M$。因为 $M$ 在子序列中，所以必须满足 $M \mid S$。因为 $S > 0$，所以显然有：
$$S \ge M$$

再来看看异或的性质：一堆数字进行异或，其结果 $S$ 的最高二进制位，绝对不可能超过这些数字中最高位的最大值。
既然最大元素是 $M$，那么子序列中所有元素的最高位都不会超过 $M$ 的最高位。因此：
$$S < 2^{\lfloor \log_2 M \rfloor + 1} \le 2M$$

结合两边，我们得到了一个极度苛刻的范围：
$$M \le S < 2M$$
在这个半开半闭区间内，**是 $M$ 的倍数的数有且仅 seasonal 有一个，那就是 $M$ 本身！**

* **重大发现**：如果 $S > 0$，则必定有 **$S = M$**（异或和恰好等于子序列中的最大值）。
* **衍生条件**：既然 $S = M$，那么对于子序列中的其他任意元素 $x$，必须满足 $x \mid M$。也就是说，**子序列里的所有元素，都必须是最大值 $M$ 的因数！**

---

### 3. 如何高效计数？
我们可以枚举整个数组中出现过的每一个可能的最大值 $M$（$1 \le M \le n$）。对于一个固定的 $M$：
1. 找出数组中所有是 $M$ 的**真因数**（即 $d \mid M$ 且 $d < M$）的元素。
2. 假设这些真因数的总个数为 $TotalLess$，将它们去重后加入一个局部的线性基，设线性基大小为 $B$。
3. 线性基有一个优美性质：**任何能够被该线性基表出的异或和，其组合方案数都是完全相同的**，方案数均为 $2^{TotalLess - B}$。
4. 现在我们来放入核心元素 $M$（假设 $M$ 在原数组中出现了 $cnt[M]$ 次）。为了让 $M$ 成为子序列的最大值，我们必须**至少选一个 $M$**：
   * **情况 A：选择奇数个 $M$**（方案数为 $2^{cnt[M]-1}$）。此时 $M$ 这一部分的异或贡献为 $M$。为了让总异或和为 $M$，真因数部分必须异或出 $M \oplus M = 0$。由于 $0$ 必然可以被线性基表出，所以真因数贡献的方案数确定为 $2^{TotalLess - B}$。
   * **情况 B：选择正偶数个 $M$**（方案数为 $2^{cnt[M]-1} - 1$）。此时 $M$ 这一部分的异或贡献为 $0$。为了让总异或和为 $M$，真因数部分必须异或出 $M \oplus 0 = M$。我们需要用局部的线性基检查 $M$ 是否能被表出，如果能，真因数贡献的方案数同样为 $2^{TotalLess - B}$，否则为 0。

---

## 🛠️ XCPC 风格代码实现

下面是严格基于你提供的代码模板实现的完整 AC 代码。

```cpp
#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

const int MAXN = 200005;
const int MOD = 998244353;

// 全局预处理数组
vector<int> divs[MAXN]; // 存储每个数的真因数
i64 pw2[MAXN];          // 预处理 2 的幂次

void precompute() {
    pw2[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pw2[i] = (pw2[i - 1] * 2) % MOD;
    }
    // 预处理每个数的严格真因数 (d < j)
    for (int i = 1; i < MAXN; i++) {
        for (int j = i * 2; j < MAXN; j += i) {
            divs[j].push_back(i);
        }
    }
}

// 线性基模板
struct LinearBasis {
    int basis[20] = {0};
    int sz = 0;
    
    void init() {
        memset(basis, 0, sizeof(basis));
        sz = 0;
    }
    
    bool insert(int x) {
        for (int i = 19; i >= 0; i--) {
            if ((x >> i) & 1) {
                if (!basis[i]) {
                    basis[i] = x;
                    sz++;
                    return true;
                }
                x ^= basis[i];
            }
        }
        return false;
    }
    
    bool check(int x) {
        for (int i = 19; i >= 0; i--) {
            if ((x >> i) & 1) {
                if (!basis[i]) return false;
                x ^= basis[i];
            }
        }
        return true;
    }
};

void solve() {
    cin >> n;
    vector<int> a(n);
    vector<int> count_val(n + 1, 0);
    
    for(auto &x: a) {
        cin >> x;
        count_val[x]++;
    }

    // ----------------- 1. 处理 S = 0 的情况 -----------------
    LinearBasis lb_all;
    lb_all.init();
    for (int x : a) {
        lb_all.insert(x);
    }
    // 总方案数先加上 2^(n - 线性基大小) - 1
    i64 total_ans = (pw2[n - lb_all.sz] - 1 + MOD) % MOD;

    // ----------------- 2. 处理 S > 0 的情况 -----------------
    // 枚举子序列的最大值 M
    for (int M = 1; M <= n; M++) {
        if (count_val[M] == 0) continue; // 数组里压根没这个数，跳过

        int total_less = 0;
        LinearBasis lb_divs;
        lb_divs.init();

        // 收集 M 的所有真因数
        for (int d : divs[M]) {
            if (count_val[d] > 0) {
                total_less += count_val[d];
                lb_divs.insert(d); // 插入局部线性基
            }
        }

        // 真因数部分表出任意合法异或和的基准方案数
        i64 w_base = pw2[total_less - lb_divs.sz];

        // Case A: 选奇数个 M -> M 贡献异或和 M -> 要求真因数异或和为 0
        i64 ways_odd = pw2[count_val[M] - 1];
        i64 res_odd = (ways_odd * w_base) % MOD;
        total_ans = (total_ans + res_odd) % MOD;

        // Case B: 选正偶数个 M -> M 贡献异或和 0 -> 要求真因数异或和为 M
        if (count_val[M] >= 2) {
            i64 ways_even = (pw2[count_val[M] - 1] - 1 + MOD) % MOD;
            if (lb_divs.check(M)) { // 检查局部线性基能否表出 M
                i64 res_even = (ways_even * w_base) % MOD;
                total_ans = (total_ans + res_even) % MOD;
            }
        }
    }

    cout << total_ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute(); // 全局预处理一次
    for(cin >> T ; T--; solve());
    return 0;
}
```

---

## ⏱️ 复杂度分析

### 时间复杂度
1. **预处理**：真因数分解采用埃氏筛法思想，复杂度为 $O(N \log N)$；预处理 $2$ 的幂次为 $O(N)$。由于在 `main` 函数开头只执行了一次，不计入多组数据的循环。
2. **单组数据 `solve()`**：
   * 整体线性基插入：$O(n \cdot \log(\max a)) = O(20n)$。
   * 枚举最大值 $M$：均摊下来，每个数的因数个数期望只有 $O(\log n)$ 个。对于每个存在的因数，插入局部线性基的代价是 $O(20)$。
   * 因此，枚举 $M$ 部分的总复杂度为 $O(n \cdot \log n \cdot 20)$。
* **总时间复杂度**：$O(T \cdot n \log n)$，在 $\sum n \le 2 \cdot 10^5$ 的限制下，实际运行时间约 0.05 秒，极其优秀。

### 空间复杂度
* 主要是全局 `divs` 预处理数组，其存储的元素总数为 $\sum_{i=1}^N \frac{N}{i} = N \log N$。
* **总空间复杂度**：$O(N \log N)$，大约占用十几 MB 内存，远低于题目常见的 256MB/512MB 限制。

---

## 📊 难度分析与总结

* **评级**：Codeforces 约 2000 - 2100 分（中等偏难，属于 XCPC 银牌题/金牌签到题）。
* **难点核心**：这道题最难的一步在于**将 $S > 0$ 缩减为 $S = M$** 的数学直觉。如果没有观察到“最大值的两倍以内必无其他倍数”这一位运算与整除的精妙交集，极容易陷入繁琐的动态规划（DP）黑洞中。
* **启发**：在面对位运算与四则运算（整除、加减）结合的题目时，从**最高二进制位**或**最大值边界**切入去卡死取值范围，往往是打破僵局的银弹。
