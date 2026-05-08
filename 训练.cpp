#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;

const int INF = 1e9;
int n, m, k;            

void solve() {
    cin >> n >> m;
    vector<vector<pii>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    vector<i64> dp(n, INF);
    dp[n - 1] = 0;
    for(int i = n - 2; i >= 0; i--) {
        for(auto &[v, w]: g[i]) {
            dp[i] = min(dp[i], dp[v] + w);
        }
    }
    cout << dp[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
