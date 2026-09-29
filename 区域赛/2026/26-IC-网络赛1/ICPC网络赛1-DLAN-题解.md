# D.

## 1. 题面简述

给定一个长度为 $n$ 的 01 串，定义

$$
p_i=\sum_{j=1}^{i}[s_i\ne s_j].
$$

现在只知道 $p_1,p_2,\ldots,p_n$ 组成的多重集，要求计算有多少个 01 串能够得到这个多重集，答案对 $998244353$ 取模。

## 2. 分析

首先考虑 $p_i$ 到底记录了什么。假设扫描到当前位置时，前面已经有 $x$ 个 `0` 和 $y$ 个 `1`：

- 当前字符填 `0`，那么 $p_i=y$；
- 当前字符填 `1`，那么 $p_i=x$。

换句话说，每加入一个字符，产生的 $p_i$ 就是另一种字符当前出现的数量。

不难发现，每一对不同字符会被统计恰好一次。假设整个字符串中有 $a$ 个 `0` 和 $b$ 个 `1`，那么

$$
\sum p_i=ab=a(n-a).
$$

因此，我们可以从 $a=0$ 开始枚举，找到第一个满足

$$
a(n-a)=\sum p_i
$$

的 $a$。这个 $a$ 就是两种字符数量中较小的那个，另一个为 $n-a$。

接下来令 $c_i$ 表示数值 $i$ 在多重集中还剩多少个。假设当前两种字符分别出现了 $i$ 次和 $now$ 次，并且 $i\le now$。

注意到，想要继续产生数值 $i$，只能加入当前数量较多的字符，所以剩余的 $c_i$ 个数值必须在这里一次用完：

$$
now\gets now+c_i.
$$

一旦数量较少的字符从 $i$ 增加到 $i+1$，以后两种字符的数量都大于 $i$，再也不可能产生数值 $i$。

如果 $i<a$，说明数量较少的字符还要继续增加。此时加入一次较少字符，产生的数值就是当前的 $now$，所以需要执行 `c[now]--`。

特殊地，如果 $i=now$，说明两种字符数量相等。下一步既可以填 `0`，也可以填 `1`，两种选择会进入同一个无序状态，但是对应两个不同字符串，所以答案乘二。

由此可知，整个重构过程除了两种字符数量相等时有两种选择，其他时刻都是唯一的，答案一定是若干个 $2$ 相乘得到的结果。

时间复杂度为 $O(n)$，空间复杂度为 $O(n)$。

如果直接枚举所有 01 串，复杂度为 $O(n2^n)$，只能用于小数据对拍；也可以把字符串看成网格路径搜索，但是需要额外记录整个多重集状态，本质上仍然是指数级。

## 3. 代码

<details>
<summary>点击查看代码</summary>

```cpp
#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

const int mod = 998244353;

void solve() {
    cin >> n;
    vector<int> c(n + 1);
    i64 sum = 0;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        c[x]++;
        sum += x;
    }

    int a = 0;
    while (1LL * a * (n - a) != sum) a++;

    i64 res = 1;
    int now = 0;
    for (int i = 0; i < a; i++) {
        if (now == i) res = res * 2 % mod;
        now += c[i];
        c[i] = 0;
        c[now]--;
    }
    if (now == a && c[a]) res = res * 2 % mod;
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

# L.

## 1. 题面简述

依次给出 $n$ 个字符串。对于前 $i$ 个字符串，定义 $f_{i,j}$ 为：从中恰好选择 $j$ 个字符串，它们的最长公共前缀长度最大是多少。

对于每个 $i$，要求计算

$$
\sum_{j=1}^{i}(f_{i,j}\oplus j).
$$

## 2. 分析

首先考虑怎样描述 $f_{i,j}$。如果一个前缀 $p$ 在前 $i$ 个字符串中出现了至少 $j$ 次，我们就可以从这些字符串中任选 $j$ 个，它们的最长公共前缀长度至少为 $|p|$。

反过来，如果选出的 $j$ 个字符串有长度为 $len$ 的公共前缀，那么这个前缀一定在前 $i$ 个字符串中出现了至少 $j$ 次。

所以有

$$
f_{i,j}=\max\{|p|\mid p\text{ 在前 }i\text{ 个字符串中至少出现 }j\text{ 次}\}.
$$

问题就从“枚举选择哪些字符串”变成了“统计每种前缀出现了多少次”。

假设一个长度为 $len$ 的前缀原来出现了 $c-1$ 次，插入当前字符串以后变成了 $c$ 次。在此之前，它已经可以贡献给 $f_1,f_2,\ldots,f_{c-1}$，所以这次只会新增一个可能的转移：

$$
f_c\gets\max(f_c,len).
$$

由此可知，每个字符对应的前缀只需要进行一次单点取最大值，总操作次数就是所有字符串的长度之和。

为了快速判断两个前缀是否相同，这里使用 WIDA 的双字符串哈希模板。使用两组模数和底数计算哈希，再把两个不超过 32 位的哈希值拼进一个 `u64`：

```cpp
return u64(uint32_t(h.first)) << 32 | uint32_t(h.second);
```

这里一定要先转成 `u64` 再左移。如果先对 `int` 执行 `h1 << 32`，会超过 `int` 的位宽，产生未定义行为。

处理第 $i$ 个字符串时，答案中新出现了 $j=i$ 这一项。因为它的初值是 $f_i=0$，所以先加入 $0\oplus i=i$。如果某次更新令 $f_c$ 从 $old$ 变成 $len$，则将总答案修改为

$$
sum\gets sum-(old\oplus c)+(len\oplus c).
$$

设所有字符串的长度之和为 $S$，时间复杂度为期望 $O(S+n)$，空间复杂度为 $O(S+n)$。

本题也可以使用 Trie，复杂度同样为 $O(S+n)$，并且没有哈希冲突；但是每个节点保存儿子会带来更大的空间常数。也可以把全部前缀哈希离线排序，复杂度为 $O(S\log S)$。

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

const int mod1 = 1E9 + 7, base1 = 127;
const int mod2 = 1E9 + 9, base2 = 131;
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

</details>

# A. Recall

## 1. 题面简述

有一个初始为空的栈，原操作包括入栈 `+ x`、查询 `? x` 和弹栈 `-`。现在所有弹栈操作丢失了，只留下：

- `+ x`：将 $x$ 入栈；
- `T x`：查询时 $x$ 在栈中；
- `F x`：查询时 $x$ 不在栈中。

要求重新插入若干个 `-`，使栈中元素始终互不相同，并保证所有查询结果正确。

## 2. 分析

注意到，一个入栈元素只有在成功查询 `T x` 时才被要求继续留在栈里。

我们为每次 `+ x` 建立一个编号，并记录：

- $l_{id}$：本次入栈的位置；
- $r_{id}$：本次入栈以后，最后一次 `T x` 的位置。

如果后面没有成功查询，初始令 $r_{id}=l_{id}$。读到 `T x` 时，用哈希表找到 $x$ 最近一次入栈的编号，将右端点更新为当前位置。

然后按照操作顺序扫描所有区间。遇到 $l_{id}$ 时把编号压入辅助栈。如果当前栈顶满足

$$
r_{id}\le i,
$$

说明它要求保留到的最后一次成功查询已经结束，可以立即弹出。弹出后新的栈顶可能也早已完成任务，所以继续判断，直到栈顶仍然需要留到未来。

每弹出一个区间，就令 `del[i]++`，最后在第 $i$ 个原操作后输出对应数量的 `-`。

这个过程相当于给每次入栈选择最早的合法出栈时间。如果遇到新的 `+ x` 或 `F x` 时旧的 $x$ 仍未弹出，说明它上面压着一个未来仍需成功查询的元素，任何方案都无法在不破坏查询的情况下删除旧 $x$，与题目保证有解矛盾。因此，合法输入中这个贪心一定成立。

参考写法可以使用 `map` 并在最后排序所有出栈位置，复杂度为 $O(n\log n)$。这里改用 `unordered_map`，并在弹栈时直接记录 `del[i]`，省去了排序。

期望时间复杂度为 $O(n)$，空间复杂度为 $O(n)$，每个入栈元素最多只会进入和离开辅助栈各一次。

另一种写法是倒序预处理每个值的下一次操作：如果栈顶元素下一次不是 `T` 就弹出，否则保留。这个做法同样正确，但是需要额外维护下一次出现位置。

## 3. 代码

<details>
<summary>点击查看代码</summary>

```cpp
#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<char> op(n + 1);
    vector<int> l(n), r(n), del(n + 1);
    unordered_map<int, int> id;
    id.reserve(2 * n);

    int tot = 0;
    for (int i = 1, x; i <= n; i++) {
        cin >> op[i] >> x;
        if (op[i] == '+') {
            l[tot] = r[tot] = i;
            id[x] = tot++;
        } else if (op[i] == 'T') {
            r[id[x]] = i;
        }
    }

    vector<int> stk;
    stk.reserve(tot);
    int p = 0;
    for (int i = 1; i <= n; i++) {
        if (p < tot && l[p] == i) stk.push_back(p++);
        while (!stk.empty() && r[stk.back()] <= i) {
            stk.pop_back();
            del[i]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (op[i] == '+' ? '+' : '?');
        while (del[i]--) cout << '-';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
```

</details>

# N.

## 1. 题面简述

给定一个长度为 $n$ 的序列，每个位置可能包含红、黄、蓝三种棋子中的若干种。需要把序列划分成若干连续段。

如果一个连续段满足

$$
R\ge Y,\qquad R\ge B,
$$

就称它为红色段。求所有红色段长度之和的最大值。

## 2. 分析

首先考虑一个朴素 DP。令 $f_i$ 表示前 $i$ 个位置中，能够被红色段覆盖的最大长度。对于最后一段 $(j,i]$，如果它是红色段，就有

$$
f_i=\max(f_i,f_j+i-j).
$$

当然，也可以不覆盖位置 $i$，令 $f_i\gets f_{i-1}$。直接枚举 $j$ 的复杂度为 $O(n^2)$，无法通过 $n\le10^6$。

注意到区间需要同时满足红色数量不少于黄色和蓝色，所以定义两种前缀差：

$$
x_i=\sum_{k=1}^{i}(r_k-y_k),\qquad
y_i=\sum_{k=1}^{i}(r_k-b_k).
$$

区间 $(j,i]$ 是红色段，当且仅当

$$
x_j\le x_i,\qquad y_j\le y_i.
$$

原来的区间判断就变成了二维偏序。

为了让维护的值更简单，定义

$$
g_i=i-f_i,
$$

表示前 $i$ 个位置中最少有多少个位置没有被红色段覆盖。转移变成

$$
g_i=\min\left(g_{i-1}+1,
\min_{j<i,\ x_j\le x_i,\ y_j\le y_i}g_j\right).
$$

所以我们只需要维护已经出现的点 $(x_j,y_j)$，查询左下矩形中的最小 $g_j$。

这里使用树状数组套树状数组。外层 BIT 维护 $x$，每个外层节点再放一个维护 $y$ 的 BIT。所有前缀点可以提前得到，所以先离线收集每个外层节点中会出现的 $y$，排序去重后建立内层树状数组。

内层直接复用普通 BIT 的写法，只把求和改为取最小值。单次修改和查询都会经过两层 BIT，复杂度为 $O(\log^2 n)$。

还有一个很实用的优化：如果二维查询得到的 `best` 已经成为当前的 $g_i$，说明存在一个更早的点在两个坐标上都不大于当前点，并且代价不大于当前点。以后当前点能转移到的位置，那个更早的点也一定能够转移到，所以当前状态没有必要再次插入。只有 `g[i-1]+1` 严格更小时才插入当前点。

最终答案为

$$
n-g_n.
$$

时间复杂度为 $O(n\log^2 n)$，空间复杂度为 $O(n\log n)$。

本题也可以使用 CDQ 分治处理下标、$x$、$y$ 三维偏序，复杂度一般也是 $O(n\log^2 n)$；或者使用线段树套平衡树，但实现和常数都会更大。

## 3. 代码

<details>
<summary>点击查看代码</summary>

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

struct BIT2 {
    const int inf = 1e9;
    int n;
    vector<vector<int>> ys;
    vector<BIT> w;

    BIT2(int n, const vector<int> &x, const vector<int> &y) : n(n), ys(n + 1), w(n + 1) {
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

void solve() {
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

    BIT2 bit(mx - mn + 1, x, y);
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
```

</details>

# Tag

`贪心` `字符串哈希` `栈` `动态规划` `二维偏序` `树状数组套树状数组`
