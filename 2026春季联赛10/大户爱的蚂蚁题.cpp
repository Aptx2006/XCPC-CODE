#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

const int MOD = 1e9 + 7;
const int MAXN = 10000000;

int fact[MAXN + 5], ifact[MAXN + 5];

i64 qpow(i64 base, i64 mi, i64 res = 1) {
    base %= MOD;
    while(mi > 0) {
        if (mi & 1) res = res * base % MOD;
        base = base * base % MOD;
        mi >>= 1;
    }
    return res;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = 1LL * fact[i - 1] * i % MOD;
    }
    ifact[MAXN] = qpow(fact[MAXN], MOD - 2);
    for (int i = MAXN - 1; i >= 0; i--) {
        ifact[i] = 1LL * ifact[i + 1] * (i + 1) % MOD;
    }
}

i64 C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return 1LL * fact[n] * ifact[m] % MOD * ifact[n - m] % MOD;
}

int T, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    if(n & 1) {
        k = 2;
    } else {
        k = (2ll + C(n, n / 2)) % MOD;
    }
    ans = k * qpow(qpow(2, n), MOD - 2) % MOD;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    for(cin >> T; T--; solve());
    return 0;
}
