#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k;

void solve() {
    cin >> n;
    vector<vector<int>> G(n + 1);
    for(int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        G[u].push_back(i);
    }
    cin >> m;
    vector<bool> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        mp[a] = true;
    }
    vector<int> cnt(n + 1, 0), ans;
    auto dfs = [&](auto dfs, int u) -> void{
        cnt[u] = int(mp[u]);
        vector<int> a;
        for(auto &v: G[u]) {
            dfs(dfs, v);
            cnt[u] += cnt[v];
            if (cnt[v] > 0) {
                a.push_back(v);
            }
        }
        if(mp[u]) {
            for(auto &v: a) {
                ans.push_back(v);
            }
        }else {
            for(int i = 1; i < (int)a.size(); i++) {
                ans.push_back(a[i]);
            }
        }
    };
    dfs(dfs, 1);
    cout << ans.size() << ' ';
    for(auto &x: ans)  cout << x << ' ';
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}