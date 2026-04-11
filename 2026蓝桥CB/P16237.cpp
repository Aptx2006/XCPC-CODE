#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 10;
int n, m, ans, cnt;
vector<int> G[N];

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ans = 0;
    for(int i = 1; i <= n; i++) if(G[i].empty()) ans++;
    if(n < 2) {
        cout << ans << " 0\n";
        return;
    }
    for(int i = 1; i <= n; i++) cnt = max(cnt, (int)G[i].size());
    cout << ans << ' ' << cnt << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}