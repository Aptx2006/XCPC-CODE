// Problem: C - Observing Plant Growth
// Contest: AtCoder - AtCoder Weekday Contest 0002 Beta
// URL: https://atcoder.jp/contests/awc0002/tasks/awc0002_c
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

const int MAXN = 2E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, a[MAXN], b[MAXN], ans, cnt, k;

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    int l = 0, r = 1e9;
    auto isok = [&](int mid) {
        for (int i = 1; i <= n; i++) {
            if (a[i] < m - b[i] * mid) return false;
        }
        return true;
    };
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (isok(mid)) {
            ans = mid, r = --mid;
        } else
            l = ++mid;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;  // cin >> times;
    while (times--) solve();
    return 0;
}
