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
//#define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E9;

int n, m, t, ar[MAXN], ans, cnt, k;

void solve() { 
    cin >> n >> m;
    vector<string> G(n);
    for(auto &x : G) cin >> x;
    vector<int> row(n), col(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(G[i][j] == '1') row[i]++, col[j]++;
        }
    }
    cnt = 0;
    for (auto &x: row) if(x & 1) cnt++;
    for (auto &x: col) if(x & 1) cnt++;
    cnt /= 2;
    cout << min(cnt, n + m - cnt) << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1; cin >> times;
    while (times--) solve();
    return 0;
}
