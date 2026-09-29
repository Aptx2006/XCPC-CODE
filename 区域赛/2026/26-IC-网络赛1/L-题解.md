# L 题解

## 题意

依次给出 $n$ 个字符串。

对于前 $i$ 个字符串，定义 $f_{i,j}$ 为：从中恰好选择 $j$ 个字符串，它们的最长公共前缀长度最大是多少。

对于每个 $i$，求

$$
\sum_{j=1}^{i}(f_{i,j}\oplus j).
$$

其中 $\oplus$ 表示按位异或。

## 思路

### 1. 把选择字符串转化成统计前缀

注意到，如果某个长度为 $len$ 的前缀在前 $i$ 个字符串中出现了至少 $j$ 次，那么我们可以任意选择其中 $j$ 个字符串，它们的最长公共前缀长度至少为 $len$。

反过来，如果 $j$ 个字符串的最长公共前缀长度为 $len$，那么这个长度为 $len$ 的前缀一定出现了至少 $j$ 次。

由此可知：

$$
f_{i,j}=\max\{\lvert p\rvert\mid p\text{ 在前 }i\text{ 个字符串中至少出现 }j\text{ 次}\}.
$$

问题变成了维护每种前缀的出现次数。

### 2. 一个前缀只会更新一个位置

依次插入字符串。假设某个长度为 $len$ 的前缀原来出现了 $c-1$ 次，插入当前字符串后变成了 $c$ 次。

在这次插入以前，它已经能够参与 $f_{i,1},f_{i,2},\ldots,f_{i,c-1}$ 的计算，因此这些位置不需要重复更新。

出现次数变成 $c$ 后，它只获得了一个新的贡献：

$$
f_{i,c}\gets\max(f_{i,c},len).
$$

所以每插入一个字符对应的前缀，只需要进行一次单点取最大值，总操作次数就是所有字符串的长度之和。

### 3. 使用双字符串哈希统计前缀

必须快速判断两个字符串前缀是否相同，因此使用 WIDA 模板中的双字符串哈希：

$$
H_{k}=H_{k-1}\times base+s_k\pmod {mod}.
$$

代码使用两组不同的模数与底数，并调用通用模板的 `substring(0,j-1)` 得到前缀哈希。随后把两个哈希值拼成一个 `u64`，作为 `unordered_map` 的键，记录每种前缀出现了多少次。

使用双哈希后，不同字符串发生哈希冲突的概率可以忽略。

### 4. 动态维护答案

处理第 $i$ 个字符串前，答案中需要新加入 $j=i$ 这一项。此时 $f_{i,i}$ 初始为 $0$，所以先加入

$$
0\oplus i=i.
$$

如果一次前缀更新使 $f_c$ 从 `old` 变成 `len`，就在总答案中删除旧贡献，再加入新贡献：

$$
sum\gets sum-(old\oplus c)+(len\oplus c).
$$

这样处理完当前字符串的所有前缀后，`sum` 就是当前需要输出的答案。

## 正确性证明

对于任意 $j$，若一个前缀 $p$ 至少属于 $j$ 个字符串，就可以选择其中恰好 $j$ 个字符串，因此 $f_{i,j}\ge |p|$。另一方面，任意 $j$ 个字符串的最长公共前缀必然同时出现在这 $j$ 个字符串中，因此它也是一个出现次数至少为 $j$ 的前缀。故 $f_{i,j}$ 正好等于出现次数至少为 $j$ 的前缀的最大长度。

考虑插入一个出现次数从 $c-1$ 变为 $c$ 的前缀。对于所有 $j<c$，它在插入前就已经出现至少 $j$ 次，其长度已经参与过 $f_j$ 的更新；对于 $j>c$，它仍然没有出现足够多次。因此这次变化只可能更新 $f_c$。

双字符串哈希为相同前缀产生相同键，所以 `mp` 正确维护每个前缀的出现次数。每次出现次数变为 $c$ 时，代码用该前缀长度更新 $f_c$，故所有 $f_{i,j}$ 都被正确维护。

最后，代码在每个 $f_c$ 发生变化时同步替换它在异或和中的贡献，因此输出的 `sum` 就是题目要求的

$$
\sum_{j=1}^{i}(f_{i,j}\oplus j).
$$

## 复杂度

设所有字符串的长度之和为 $S$。

- 时间复杂度：期望 $O(S+n)$；
- 空间复杂度：$O(S+n)$。

## 其他可行算法

### Trie

可以把所有字符串插入 Trie。每经过一个节点就令它的出现次数加一，并用节点深度更新对应的 $f_c$。

这种方法没有哈希冲突，时间复杂度也是 $O(S+n)$，但如果每个节点都保存 26 个儿子，空间常数会更大。本题要求使用字符串哈希，因此代码没有采用 Trie。

### 离线哈希加离散化

也可以先计算所有前缀的双哈希，把哈希值排序离散化。相同哈希会得到相同编号，然后按照原输入顺序统计编号出现次数。

这种方法不需要 `unordered_map`，复杂度为 $O(S\log S+n)$，常数和代码长度都稍大。

### 暴力枚举

对每个 $i$ 枚举字符串子集，再计算所选字符串的最长公共前缀，可以直接得到所有 $f_{i,j}$，但复杂度至少为 $O(2^n)$，只能用于小数据对拍。

## 代码

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

static const int mod1 = 1E9 + 7, base1 = 127;
static const int mod2 = 1E9 + 9, base2 = 131;
vector<int> val1, val2;

void init(int n) {
    val1.resize(n + 1);
    val2.resize(n + 1);
    val1[0] = val2[0] = 1;
    for (int i = 1; i <= n; i++) {
        val1[i] = 1LL * val1[i - 1] * base1 % mod1;
        val2[i] = 1LL * val2[i - 1] * base2 % mod2;
    }
}

struct String {
    vector<int> hash1;
    vector<int> hash2;
    string s;

    String(string s_) : s(s_), hash1{1}, hash2{1} {
        for (auto it: s) {
            hash1.push_back((1LL * hash1.back() * base1 + it) % mod1);
            hash2.push_back((1LL * hash2.back() * base2 + it) % mod2);
        }
    }
    pair<int, int> get() {
        return {hash1.back(), hash2.back()};
    }
    pair<int, int> substring(int l, int r) {
        if (l > r) swap(l, r);
        int len = r - l + 1;
        int ans1 = (hash1[r + 1] - 1LL * hash1[l] * val1[len] % mod1 + mod1) % mod1;
        int ans2 = (hash2[r + 1] - 1LL * hash2[l] * val2[len] % mod2 + mod2) % mod2;
        return {ans1, ans2};
    }
    pair<int, int> modify(int idx, char x) {
        int n = s.size() - 1;
        int ans1 = (hash1.back() + 1LL * val1[n - idx] * (x - s[idx]) % mod1 + mod1) % mod1;
        int ans2 = (hash2.back() + 1LL * val2[n - idx] * (x - s[idx]) % mod2 + mod2) % mod2;
        return {ans1, ans2};
    }
};

u64 getKey(pair<int, int> h) {
    return u64(uint32_t(h.first)) << 32 | uint32_t(h.second);
}

void solve() {
    cin >> n;
    init(500000);
    vector<int> f(n + 1);
    unordered_map<u64, int> mp;
    mp.reserve(1000000);
    mp.max_load_factor(0.7);

    i64 sum = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        String str(s);
        sum += i;
        for (int j = 1; j <= (int)s.size(); j++) {
            int c = ++mp[getKey(str.substring(0, j - 1))];
            if (f[c] < j) {
                sum -= f[c] ^ c;
                f[c] = j;
                sum += f[c] ^ c;
            }
        }
        cout << sum << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
```

## Tag

`字符串哈希` `双哈希` `前缀` `计数` `在线维护`
