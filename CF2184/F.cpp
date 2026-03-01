// Problem: Cherry Tree
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/2184/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
vector<vector<int>> G(n + 5);

array<bool, 3> dfs(int u, int p) {
    array<bool, 3> cdp = {1, 0, 0};
    bool flag = 1;
    for (auto &v : G[u]) {
        if (v == p) continue;
        flag = 0;
        array<bool, 3> sondp = dfs(v, u), ndp = {0, 0, 0};
        for (int i = 0; i < 3; i++) {
            if (!cdp[i]) continue;
            for (int j = 0; j < 3; j++) {
                if (!sondp[j]) continue;
                ndp[(i + j) % 3] = 1;
            }
        }
        cdp.swap(ndp);
    }
    if (flag) return {0, 1, 0};
    cdp[1] = 1;
    return cdp;
}

void solve() {
    cin >> n;
    G.assign(n + 5, vector<int>());
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    array<bool, 3> dp = dfs(1, 0);
    cout << (dp[0] ? "Yes\n" : "No\n");
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
