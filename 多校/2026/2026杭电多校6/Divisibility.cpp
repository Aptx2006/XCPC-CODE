#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned int;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int_fast64_t T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n >> m >> k;
    vector< vector<int> > G(n + 5);
    for(int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector< vector<i64> > dp(n + 5, vector<i64>(2, -1));
    queue<pair<i64, bool>> Q;
    dp[1][0] = 0;
    Q.push({1ll, 0});
    while(!Q.empty()) {
        auto [u, p] = Q.front();
        Q.pop();
        if(!p) {
            for(auto &v : G[u]) {
                if(dp[v][1] == -1) {
                    dp[v][1] = dp[u][0] + 1;
                    Q.push({v, 1});
                }
            }
        } else {
            for(auto &v : G[u]) {
                if(dp[v][0] == -1) {
                    dp[v][0] = dp[u][1] + 1;
                    Q.push({v, 0});
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        i64 ans = 1e18;
        if(dp[i][0] != - 1) {
            i64 x = (dp[i][0] + k - 1) / k;
            if(k & 1 and x & 1) x++;
            ans = min(ans, x * k);
        }
        if(k & 1 and dp[i][1] != -1) {
            i64 x = (dp[i][1] + k - 1) / k; 
            if(~x & 1) x++;
            ans = min(ans, x * k);
        }
        if(ans == 1e18) ans = -1;
        cout << ans << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
