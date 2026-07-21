#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;
const i64 mod = 998244353;

i64 qpow(i64 a, i64 b) {
    i64 res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

vector<i64> inv(2000005);

void solve() {
    cin >> n;
    vector<i64> a(n);
    i64 sum = 0;
    for(auto &x: a) cin >> x;
    for(auto x : a) sum = (sum + x) % mod;
    i64 cur = (a[0] + a[n - 1]) % mod;
    i64 ans = ((n + 3) * sum + cur) % mod * inv[6] % mod;
    cout << ans % mod << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    inv[1] = 1;
    for(int i = 2; i < (int)inv.size(); i++) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
    for(cin >> T; T--; solve());
    return 0;
}
