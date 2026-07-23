// Problem: D. Christmas Tree Decoration
// Contest: Codeforces - Educational Codeforces Round 186 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2182/problem/D
// Memory Limit: 512 MB
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

const int MAXN = 60, MOD = 998244353, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k, sum, dp[MAXN], inv[MAXN];

i64 qpow(int base, int mi, i64 res = 1) {
    while (mi) {
        if (mi & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        mi >>= 1;
    }
    return res;
}

i64 C(int a, int b) {
    if (b < 0 or a < b) return 0ll;
    return dp[a] * inv[b] % MOD * inv[a - b] % MOD;
}

void solve() {
    cin >> n;
    sum = cnt = ans = 0;
    for (int i = 0; i <= n; i++) cin >> ar[i], sum += ar[i];
    k = sum / n, t = sum % n;
    int need = 0;
    for (int i = 1; i <= n; i++) {
        if (ar[i] > k)
            cnt++;
        else
            need += k - ar[i];
    }
    if (ar[0] < need) {
        cout << "0\n";
        return;
    }
    ar[0] -= need;
    for (int i = 0; i <= t; i++) {
        if (i > ar[0]) break;
        if (i <= n - cnt and (t - i) <= cnt) {
            ans = (ans + C(n - cnt, i) * C(cnt, t - i) % MOD) % MOD;
        }
    }
    //(ans *= dp[t] * dp[n - t] % MOD) % MOD;
    ans = ans * dp[t] % MOD;
    ans = ans * dp[n - t] % MOD;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    dp[0] = inv[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        dp[i] = dp[i - 1] * i % MOD;
        inv[i] = qpow(dp[i], MOD - 2);
    }
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
