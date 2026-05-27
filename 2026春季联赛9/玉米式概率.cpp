#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x)(x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " <<(x) << endl;

int T, n, m, k, ans, cnt;

const i64 MOD = 998244353;
const int N = 1000000;
i64 inv[2 * N + 5];

i64 qpow(i64 a, i64 b) {
    i64 res = 1;
    a %= MOD;
    while(b > 0) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    inv[1] = 1;
    for(int i = 2; i <= 2 * N; i++) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
}

void solve() {
    cin >> n;
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    vector<i64> C(n + 1, 0), D(n + 1, 0);
    i64 A1 = 0, B1 = 0;
    for (int x = n - 1; x >= 1; x--) {
        i64 Ax, Bx;
        if (2 * x >= n) {
            Ax = inv[2 * x];
            Bx = 1;
        } else {
            Ax = inv[2 * x] * (1 - C[2 * x + 1] + MOD) % MOD;
            Bx = (inv[2 * x] * (MOD - D[2 * x + 1]) % MOD + 1) % MOD;
        }
        if (x == 1) {
            A1 = Ax;
            B1 = Bx;
        }
        C[x] = (C[x + 1] + Ax) % MOD;
        D[x] = (D[x + 1] + Bx) % MOD;
    }
    i64 S1 = D[1] * qpow((1 - C[1] + MOD) % MOD, MOD - 2) % MOD;
    i64 ans = (A1 * S1 % MOD + B1) % MOD;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    for(cin >> T; T--; solve());
    return 0;
}
