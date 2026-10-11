#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define dbg(A) cout << (#A) << ':' << A << endl;
#define all(A) (A).begin(), (A).end()

int n, m;
const int N = 2e5 + 10;
i64 sz[N], sum[N], w[N], dp[N];
i64 l, r, ans;
vector<int> G[N];

void dfs(int u) {
    sum[u] = w[u];
    for(auto &v: G[u]) {
        dfs(v);
        sum[u] += sum[v];
    }
    
    sort(all(G[u]), [&](auto o1, auto o2) {
        return sz[o1] * sum[o2] > sz[o2] * sum[o1];
    });

    dp[u] = w[u];
    sz[u] = 1;
    for(auto &v: G[u]) {
        dp[u] += dp[v] + sz[u] * sum[v];
        sz[u] += sz[v];
    }
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for(int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        G[u].push_back(i);
    }
    dfs(1);
    cout << dp[1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}