// Problem: E. Swap to Rearrange
// Contest: Codeforces - Codeforces Round 1081 (Div. 2)
// URL: https://codeforces.com/contest/2192/problem/E
// Memory Limit: 512 MB
// Time Limit: 5000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize(2)
/*i32 : -2e9~2e9
i64: -9e18~9e18
u64: 0~1.8e19*/
using i64 = long long;
using u64 = unsigned long long;
#define dbg(A) cout << #A << "==" << A << '\n';
#define all(A) A.begin(), A.end()
//#define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> mp(n + 1, 0);
    for (auto &x : a) cin >> x, mp[x]++;
    for (auto &x : b) cin >> x, mp[x]++;
    for (int i = 1; i <= n; i++) {
        if (mp[i] & 1) {
            cout << "-1\n";
            return;
        }
    }
    vector<vector<pair<int, int>>> G(n + 1);
    for (int i = 0; i < n; i++) {
        G[a[i]].push_back({b[i], i + 1});
        G[b[i]].push_back({a[i], i + 1});
    }
    vector<int> res, vis(n + 1, 0);

    function<void(int)> dfs = [&](int u) {
        while (G[u].size()) {
            auto [v, i] = G[u].back();
            G[u].pop_back();
            if (vis[i]) continue;
            vis[i] = 1;
            if (a[i - 1] != u) res.push_back(i);
            dfs(v);
        }
    };

    for (int i = 1; i <= n; i++)
        if (G[i].size()) dfs(i);
    cout << res.size() << '\n';
    for (auto &x : res) cout << x << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
