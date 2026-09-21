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
