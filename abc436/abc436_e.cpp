// Problem: E - Minimum Swap
// Contest: AtCoder - AtCoder Beginner Contest 436
// URL: https://atcoder.jp/contests/abc436/tasks/abc436_e
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

const int MAXN = 3E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;
bool vis[MAXN];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> ar[i];
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int ii = i, j = 0;
        for (; !vis[ii]; j++) vis[ii] = 1, ii = ar[ii];
        if (j > 1) ans += j * (j - 1) / 2;
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;  // cin >> times;
    while (times--) solve();
    return 0;
}
