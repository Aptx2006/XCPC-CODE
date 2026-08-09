#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<i64> a(n);
    for(auto &x: a) cin >> x;
    vector<vector<int>> G(n + 5);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= 60; j++) {
            if((a[i] >> j) & 1) {
                G[i + 1].push_back(j + 1);
            }
        }
    }

    ans = 0;

    vector<int> match(65);
    for(int i = 1; i <= n; i++) {
        vector<int> vis(65);
        auto dfs = [&](auto self, int x) -> bool{
            for(auto y : G[x]) {
                if(vis[y]) continue;
                vis[y] = 1;
                if(!match[y] or self(self, match[y])) {
                    match[y] = x;
                    return true;
                }
            }
            return false;
        };
        if(dfs(dfs, i)) {
            ans++;
        }
    }
    cout << n - ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
