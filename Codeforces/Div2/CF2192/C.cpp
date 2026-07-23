// Problem: C. All-in-one Gun
// Contest: Codeforces - Codeforces Round 1081 (Div. 2)
// URL: https://codeforces.com/contest/2192/problem/C
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

void solve() {
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> pre(n + 5), mn(n + 5), mx(n + 5);
    pre[1] = mn[1] = a[0];
    for (int i = 2; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
        mn[i] = min(mn[i - 1], a[i - 1]);
        // mx[i] = max(mx[i - 1], a[i - 1]);
    }
    mx[n] = a[n - 1];
    for (int i = n - 1; i > 0; i--) mx[i] = max(mx[i + 1], a[i - 1]);

    ans = -1;
    for (int i = 1; i <= n; i++) {
        int csum = pre[i];
        if (i < n) {
            csum = max(csum, csum + mx[i + 1] - mn[i]);
        }
        t = 0;
        if (m > csum) t = (m - csum + pre[n] - 1) / pre[n];
        t *= (n + k);
        if (ans == -1 or ans > t + i) ans = t + i;
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
