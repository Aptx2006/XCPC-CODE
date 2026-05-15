#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

const i64 MOD = 998244353;

i64 qpow(i64 a, i64 b) {
    i64 res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int T, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<i64> a(n), b(n);
    i64 sum = 0;
    for(auto &x: a) {
        cin >> x;
        sum += x;
    }
    for(auto &x: b) cin >> x;

    if (sum == 0) {
        cout << 0 << '\n';
        return;
    }

    i64 invs = qpow(sum % MOD, MOD - 2);
    i64 inv2 = qpow(2, MOD - 2);
    
    i64 ans = 0;
    i64 pb = 0;
    for (int i = 0; i < n; i++) {
        i64 win_prob = (pb + b[i] % MOD * inv2 % MOD) % MOD;
        ans = (ans + a[i] % MOD * win_prob % MOD) % MOD;
        pb = (pb + b[i]) % MOD;
    }
    
    cout << ans * invs % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
