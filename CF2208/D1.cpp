// Problem: D1. Tree Orientation (Easy Version)
// Contest: Codeforces - Codeforces Round 1086 (Div. 2)
// URL: https://codeforces.com/contest/2208/problem/D1
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
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

int n, m, t, ar[MAXN], cnt, k;

#define GO              \
    {                   \
        cout << "NO\n"; \
        return;         \
    }

void solve() {
    cin >> n;
    vector<string> s(n);
    for (auto& x : s) cin >> x;
    for (int i = 0; i < n; i++) {
        if (s[i][i] != '1') GO;
        for (int j = i + 1; j < n; j++) {
            if (s[i][j] == '1' and s[j][i] == '1') GO;
        }
    }
    vector<vector<int>> G(n + 5), GG(n + 5);
    cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i or s[i][j] == '0') continue;
            bool f = 1;
            for (int k = 0; k < n; k++) {
                if (k == j or k == i) continue;
                if (s[i][k] == '1' and s[k][j] == '1') {
                    f = 0;
                    break;
                }
            }
            if (f) {
                G[i].push_back(j), cnt++;
                GG[i].push_back(j), GG[j].push_back(i);
            }
        }
    }
    if (cnt != n - 1) GO;
    vector<int> vis(n + 5, 0);
    auto dfs = [&](auto&& dfs, int x) -> void {
        vis[x] = 1;
        for (auto& u : GG[x]) {
            if (!vis[u]) dfs(dfs, u);
        }
    };
    dfs(dfs, 0);
    for (int i = 0; i < n; i++)
        if (!vis[i]) GO;
    string s0(n, '0');
    vector<string> ss(n, s0);
    auto dfs2 = [&](auto& dfs2, int u, int v) -> void {
        ss[u][v] = '1';
        for (auto& vv : G[v]) {
            if (ss[u][vv] == '0') {
                dfs2(dfs2, u, vv);
            }
        }
    };
    for (int i = 0; i < n; ++i) dfs2(dfs2, i, i);
    if (ss != s)
        cout << "NO\n";
    else {
        cout << "YES\n";
        for (int u = 0; u < n; u++)
            for (auto& v : G[u]) cout << u + 1 << ' ' << v + 1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
