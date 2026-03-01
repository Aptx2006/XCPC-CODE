// Problem: C. War Strategy
// Contest: Codeforces - Hello 2026
// URL: https://codeforces.com/contest/2183/problem/C
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
//#define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
    cin >> n >> m >> k;
    ans = 1;
    for (int i = 1; i <= n; i++) {
        if (i > k - 1 or m + 1 < 2 * i) break;
        t = min({i, n - k, m + 1 - 2 * i});
        ans = max(ans, i + t + 1);
    }
    for (int i = 1; i <= n; i++) {
        if (i > n - k or m + 1 < 2 * i) break;
        t = min({i, k - 1, m + 1 - 2 * i});
        ans = max(ans, i + t + 1);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
