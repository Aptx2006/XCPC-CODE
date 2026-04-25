# jiangly 常用算法模板学习笔记

> 本文整理自 [hh2048/XCPC jiangly模板收集](https://github.com/hh2048/XCPC/tree/main/03%20-%20jiangly%E6%A8%A1%E6%9D%BF%E6%94%B6%E9%9B%86)
> 
> 每个模板均配有注释、用法说明和典型例题，便于日常查阅和学习。

---

## 1. 线段树（LazySegmentTree）

### 模板代码
```cpp
// 区间加、区间和、区间平方和等通用懒标记线段树
struct Tag {
    i64 add = 0;
    void apply(const Tag &t) { add = (add + t.add) % MOD; }
};
struct Info {
    i64 sum = 0, sum2 = 0;
    void apply(const Tag &t, int l, int r) {
        i64 len = r - l;
        sum2 = (sum2 + 2 * t.add % MOD * sum % MOD + len % MOD * t.add % MOD * t.add % MOD) % MOD;
        sum = (sum + len % MOD * t.add % MOD) % MOD;
    }
};
Info operator+(const Info &a, const Info &b) {
    return {(a.sum + b.sum) % MOD, (a.sum2 + b.sum2) % MOD};
}

template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    // ...模板实现同上...
};
```

### 用法说明
- 支持区间加、区间和、区间平方和等操作。
- 只需自定义 Info/Tag 结构体和 apply 逻辑即可适配多种题型。
- 区间加：`st.rangeApply(l, r, Tag{val});`
- 区间查询：`auto res = st.rangeQuery(l, r);`

### 典型例题
- [AtCoder ABC343 F - Merge Slimes](https://atcoder.jp/contests/abc343/tasks/abc343_f)
- [Codeforces 438D - The Child and Sequence](https://codeforces.com/problemset/problem/438/D)

---

## 2. 树状数组（Fenwick）

### 模板代码
```cpp
struct Fenwick {
    int n;
    std::vector<i64> a;
    Fenwick(int n_) : n(n_), a(n_ + 1) {}
    void add(int x, i64 v) { for (++x; x <= n; x += x & -x) a[x] += v; }
    i64 sum(int x) { i64 r = 0; for (; x; x -= x & -x) r += a[x]; return r; }
    i64 rangeSum(int l, int r) { return sum(r) - sum(l); }
};
```

### 用法说明
- 单点加，前缀和/区间和查询。
- 下标从 0 开始，sum(x) 返回 [0, x) 的和。

### 典型例题
- [洛谷 P3368 - 树状数组 2](https://www.luogu.com.cn/problem/P3368)
- [Codeforces 1208D - Restore Permutation](https://codeforces.com/problemset/problem/1208/D)

---

## 3. 并查集（DSU）

### 模板代码
```cpp
struct DSU {
    std::vector<int> f;
    DSU(int n) : f(n) { std::iota(f.begin(), f.end(), 0); }
    int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
    bool same(int x, int y) { return find(x) == find(y); }
    void merge(int x, int y) { f[find(x)] = find(y); }
};
```

### 用法说明
- 支持集合合并、查找。
- 可扩展维护集合大小、权值等。

### 典型例题
- [洛谷 P3367 - 并查集](https://www.luogu.com.cn/problem/P3367)
- [Codeforces 1108D - Diverse Garland](https://codeforces.com/problemset/problem/1108/D)

---

## 4. 欧拉筛（线性筛）

### 模板代码
```cpp
std::vector<int> minp, primes;
void eulerSieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    for (int i = 2; i <= n; ++i) {
        if (!minp[i]) minp[i] = i, primes.push_back(i);
        for (int p : primes) {
            if (p > minp[i] || p * i > n) break;
            minp[p * i] = p;
        }
    }
}
```

### 用法说明
- minp[x] 为 x 的最小质因数。
- primes 存所有质数。

### 典型例题
- [洛谷 P3383 - 【模板】线性筛素数](https://www.luogu.com.cn/problem/P3383)

---

## 5. 组合数（预处理逆元）

### 模板代码
```cpp
const int N = 1e6 + 10, MOD = 998244353;
i64 fac[N], ifac[N];
i64 qpow(i64 a, i64 b) { i64 r = 1; for (; b; b >>= 1, a = a * a % MOD) if (b & 1) r = r * a % MOD; return r; }
void initComb(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % MOD;
    ifac[n] = qpow(fac[n], MOD - 2);
    for (int i = n; i; --i) ifac[i - 1] = ifac[i] * i % MOD;
}
i64 C(int n, int m) { return m < 0 || m > n ? 0 : fac[n] * ifac[m] % MOD * ifac[n - m] % MOD; }
```

### 用法说明
- 先调用 initComb(n) 预处理。
- C(n, m) 返回组合数。

### 典型例题
- [洛谷 P3811 - 【模板】乘法逆元](https://www.luogu.com.cn/problem/P3811)
- [Codeforces 888G - Xor-MST](https://codeforces.com/problemset/problem/888/G)

---

## 6. 字符串哈希

### 模板代码
```cpp
struct StringHash {
    static const i64 P = 131, MOD = 1e9 + 7;
    std::vector<i64> h, p;
    StringHash(const std::string &s) {
        int n = s.size();
        h.assign(n + 1, 0); p.assign(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            h[i + 1] = (h[i] * P + s[i]) % MOD;
            p[i + 1] = p[i] * P % MOD;
        }
    }
    i64 get(int l, int r) { // [l, r)
        return (h[r] - h[l] * p[r - l] % MOD + MOD) % MOD;
    }
};
```

### 用法说明
- 支持 O(1) 求任意子串哈希。
- 可用于字符串判重、哈希表等。

### 典型例题
- [洛谷 P3370 - 字符串哈希](https://www.luogu.com.cn/problem/P3370)
- [Codeforces 126B - Password](https://codeforces.com/problemset/problem/126/B)

---

## 7. 后缀自动机（SAM）

### 模板代码
```cpp
struct SAM {
    struct Node { int len, link; std::map<char, int> ch; };
    std::vector<Node> t; int last;
    SAM() { t.push_back({0, -1}); last = 0; }
    void extend(char c) {
        int cur = t.size(); t.push_back({t[last].len + 1, 0});
        int p = last;
        while (p != -1 && !t[p].ch.count(c)) t[p].ch[c] = cur, p = t[p].link;
        if (p == -1) t[cur].link = 0;
        else {
            int q = t[p].ch[c];
            if (t[p].len + 1 == t[q].len) t[cur].link = q;
            else {
                int clone = t.size(); t.push_back(t[q]);
                t[clone].len = t[p].len + 1;
                while (p != -1 && t[p].ch[c] == q) t[p].ch[c] = clone, p = t[p].link;
                t[q].link = t[cur].link = clone;
            }
        }
        last = cur;
    }
};
```

### 用法说明
- 支持在线构建后缀自动机，适合处理子串、出现次数等问题。

### 典型例题
- [洛谷 P3804 - 后缀自动机](https://www.luogu.com.cn/problem/P3804)
- [Codeforces 126B - Password](https://codeforces.com/problemset/problem/126/B)

---

> 更多模板可参考原仓库和实际题目需求扩展。
