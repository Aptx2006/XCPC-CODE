// Problem: D - Paid Walk
// Contest: AtCoder - AtCoder Beginner Contest 441 (Promotion of Engineer Guild
// Fes) URL: https://atcoder.jp/contests/abc441/tasks/abc441_d Memory Limit:
// 1024 MB Time Limit: 2000 ms
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
int l, s;
vector<vector<pair<int, int>>> G;
set<int> res;

void dfs(int u, int dp, int cost) {
    if (dp > l or cost > t) return;
    int re = l - dp;
    if (cost + re * 1e8 < s) return;
    if (dp == l) {
        if (cost >= s and cost <= t) res.insert(u);
        return;
    }
    for (auto& [v, c] : G[u]) dfs(v, dp + 1, cost + c);
}

void solve() {
    cin >> n >> m >> l >> s >> t;
    G.resize(n + 1);
    for (int i = 0, u, v, c; i < m; i++) {
        cin >> u >> v >> c;
        G[u].push_back({v, c});
    }
    dfs(1, 0, 0);
    for (auto& x : res) cout << x << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;  // cin >> times;
    while (times--) solve();
    return 0;
}
