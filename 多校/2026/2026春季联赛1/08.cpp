#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize(2)
/*i32 : -2e9~2e9
i64: -9e18~9e18
u64: 0~1.8e19*/
using i64 = long long;
using u64 = unsigned long long;
#define dbg(A) cout << #A << "==" << A << '\n';
#define all(A) A.begin(), A.end()
#define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], cnt, k, q;
i64 ans;

const vector<int> pri = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int fac[31][10];

i64 qpow(int base, int mi, int res = 1) {
    while (mi) {
        if (mi & 1) res *= base;
        base *= base;
        mi >>= 1;
    }
    return res;
}

void solve() {
    cin >> n >> m >> q;
    vector<vector<int>> dp(n + 1, vector<int>(10, 0));
    vector<pair<int, int>> G[10];

    for (int i = 0, x, y, g; i < m; i++) {
        cin >> x >> y >> g;
        for (int j = 0; j < 10; j++) {
            if (fac[g][j]) {
                dp[x][j] = max(dp[x][j], fac[g][j]);
                dp[y][j] = max(dp[y][j], fac[g][j]);
            } else {
                G[j].push_back({x, y});
            }
        }
    }

    bool must[n + 1][10];
    for (int j = 0; j < 10; j++) {
        queue<int> Q;
        vector<bool> vis(n + 1, 0);
        for (int x = 1; x <= n; ++x) {
            if (dp[x][j] > 0) {
                must[x][j] = 1;
                Q.push(x);
                vis[x] = 1;
            }
        }
        while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            for (auto& [u, v] : G[j]) {
                if (u == x and !vis[v]) {
                    must[v][j] = 0;
                    vis[v] = 1;
                }
                if (v == x and !vis[u]) {
                    must[u][j] = 0;
                    vis[u] = 1;
                }
            }
        }
    }

    for (int i = 0, x, y; i < q; i++) {
        cin >> x >> y;
        ans = 1;
        for (int j = 0; j < 10; j++) {
            if (must[x][j] and must[y][j]) {
                ans *= qpow(pri[j], min(dp[x][j], dp[y][j]));
            }
        }
        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    for (int i = 1; i <= 30; i++) {
        int ii = i;
        for (int j = 0; j < 10; j++) {
            int p = pri[j];
            while (ii % p == 0 and ii) ii /= p, fac[i][j]++;
        }
    }
    cin >> times;
    while (times--) solve();
    return 0;
}
