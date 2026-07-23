#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N = 5005, MOD = 998244353;

i64 n, m, k;

void solve() {
    cin >> n >> m >> k;
    vector<i64> a(n);
    for(auto &x: a) cin >> x;

    i64 cnt = (n - k) / m + 1;
    i64 g = __gcd(n, m);
    i64 L = n / g;
    
    i64 ans = -2e18;

    for (int i = 0; i < g; i++) {
        vector<i64> b(L);
        for (int j = 0; j < L; j++) {
            b[j] = a[(i + j * m) % n];
        }
        vector<i64> pre(2 * L + 1, 0);
        for (int j = 0; j < 2 * L; j++) {
            pre[j + 1] = pre[j] + b[j % L];
        }
        for (int j = 0; j < L; j++) {
            ans = max(ans, pre[j + cnt] - pre[j]);
        }
    }
    
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
