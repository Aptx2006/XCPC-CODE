// Problem: D - Teleport Maze
// Contest: AtCoder - AtCoder Beginner Contest 436
// URL: https://atcoder.jp/contests/abc436/tasks/abc436_d
// Memory Limit: 1024 MB
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
#define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void solve() {
    cin >> n >> m;
    vector<string> G(n);
    for (auto &x : G) cin >> x;
    unordered_map<char, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (G[i][j] <= 'z' and G[i][j] >= 'a')
                mp[G[i][j]].push_back({i, j});
    }
    vector<vector<int>> vis(n, vector<int>(m, 0)), dp(n, vector<int>(m, INF));
    queue<pair<int, int>> Q;
    Q.push({0, 0}), vis[0][0] = 1, dp[0][0] = 0;
    while (!Q.empty()) {
        auto [x, y] = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= n or nx < 0 or ny >= m or ny < 0) continue;
            if (G[nx][ny] == '#') continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            dp[nx][ny] = min(dp[nx][ny], dp[x][y] + 1);
            Q.push({nx, ny});
        }
        if (G[x][y] <= 'z' and G[x][y] >= 'a') {
            for (auto [nx, ny] : mp[G[x][y]]) {
                if (!vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    dp[nx][ny] = min(dp[nx][ny], dp[x][y] + 1);
                    Q.push({nx, ny});
                }
            }
            mp.erase(G[x][y]);
        }
    }
    cout << (dp[n - 1][m - 1] == INF ? -1 : dp[n - 1][m - 1]) << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;  // cin >> times;
    while (times--) solve();
    return 0;
}
