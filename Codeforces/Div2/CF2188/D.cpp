// Problem: D. Shortest Statement Ever
// Contest: Codeforces - Codeforces Round 1077 (Div. 2)
// URL: https://codeforces.com/contest/2188/problem/D
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
#define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;
struct nod {
    int cost, pu, pv;
    int ch;  // 00, 01, 10
    nod() : cost(INF), ch(-1), pu(-1), pv(-1){};
};

void solve() {
    cin >> n >> m;
    nod dp[40][3][3];
    dp[32][1][1].cost = 0;
    vector<pair<int, int>> a{{0, 0}, {0, 1}, {1, 0}};
    for (int i = 31; i >= 0; i--) {
        int b = 1ll << i;
        int bx = (n >> i) & 1, by = (m >> i) & 1;
        for (int u = 0; u < 3; u++) {
            for (int v = 0; v < 3; v++) {
                if (dp[i + 1][u][v].cost == INF) continue;
                for (int c = 0; c < 3; c++) {
                    auto [uu, vv] = a[c];
                    int nu = u, nv = v;
                    if (u == 1) {
                        if (uu < bx)
                            nu = 0;
                        else if (uu > bx)
                            nu = 2;
                    }
                    if (v == 1) {
                        if (vv < by)
                            nv = 0;
                        else if (vv > by)
                            nv = 2;
                    }
                    int ncost = 0;
                    if (nu == 0)
                        ncost += (bx - uu) * b;
                    else if (nu == 2)
                        ncost += (uu - bx) * b;
                    if (nv == 0)
                        ncost += (by - vv) * b;
                    else if (nv == 2)
                        ncost += (vv - by) * b;
                    ncost += dp[i + 1][u][v].cost;
                    if (ncost < dp[i][nu][nv].cost) {
                        dp[i][nu][nv].cost = ncost;
                        dp[i][nu][nv].ch = c;
                        dp[i][nu][nv].pu = u;
                        dp[i][nu][nv].pv = v;
                    }
                }
            }
        }
    }
    int endu = -1, endv = -1;
    int mn = INF;
    for (int u = 0; u < 3; u++) {
        for (int v = 0; v < 3; v++) {
            if (dp[0][u][v].cost < mn) {
                mn = dp[0][u][v].cost;
                endu = u, endv = v;
            }
        }
    }
    int p = 0, q = 0;
    for (int i = 0; i <= 31; i++) {
        int c = dp[i][endu][endv].ch;
        auto [uu, vv] = a[c];
        if (uu) p |= (1ll << i);
        if (vv) q |= (1ll << i);
        int pu = dp[i][endu][endv].pu;
        int pv = dp[i][endu][endv].pv;
        endu = pu;
        endv = pv;
    }
    cout << p << " " << q << "\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
