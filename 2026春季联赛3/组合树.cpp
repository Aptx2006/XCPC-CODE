
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N = 5005, MOD = 998244353;

i64 n, fact[N], invf[N];

i64 qpow(i64 base, i64 mi, i64 res = 1) {
    while(mi) {
        if (mi & 1) 
            res = res * base % MOD;
        base = base * base % MOD;
        mi >>= 1; 
    }
    return res;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = 1LL * fact[i - 1] * i % MOD;
    invf[N - 1] = qpow(fact[N - 1], MOD - 2);
    for (int i = N - 1; i; i--) invf[i - 1] = 1LL * invf[i] * i % MOD;
}

i64 C(int n, int m) {
    if (m < 0 or m > n) return 0;
    return fact[n] * invf[m] % MOD * invf[n - m] % MOD;
}

void solve() {
    cin >> n;
    vector<i64> a(n);
    for(auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    i64 ans = 0;
    for (int i = 1; i < n; i++) {
        i64 v = a[i], x = a[0], y = a[i - 1];
        if (llabs(v - 2 * x) >= llabs(v - 2 * y)) {
            ans = (ans + C(v, x)) % MOD;
        } else {
            ans = (ans + C(v, y)) % MOD;
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
