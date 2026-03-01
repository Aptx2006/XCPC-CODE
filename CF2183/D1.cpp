// Problem: D1. Tree Coloring (Easy Version)
// Contest: Codeforces - Hello 2026
// URL: https://codeforces.com/contest/2183/problem/D1
// Memory Limit: 512 MB
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

int n, m, t, ar[MAXN], ans, mp, k;

void solve() {
    cin >> n;
    vector<int> G[n + 5];
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> fa(n + 5), dp(n + 5, -1), son(n + 5, 0);
    queue<int> q;
    q.push(1);
    dp[1] = 0, fa[1] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : G[u]) {
            if (dp[v] == -1) {
                fa[v] = u;
                dp[v] = dp[u] + 1;
                son[u]++;
                q.push(v);
            }
        }
    }
    int mxdp = *max_element(all(dp));
    vector<int> mp(mxdp + 1, 0);
    for (int i = 1; i <= n; i++) {
        mp[dp[i]]++;
    }
    int ans1 = *max_element(all(mp));
    ans = *max_element(all(son)) + 1;
    cout << max(ans1, ans) << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
