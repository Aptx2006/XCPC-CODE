#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;
const int MOD = 998244353;

struct nod{
    i64 u, v, w;
};

i64 qpow(i64 a, i64 b, i64 res = 1) {
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    cin >> n >> m;
    vector<nod> a(n);
    for(auto &[u, v, w]: a) cin >> u >> v >> w;
    auto calc = [&](i64 x) -> i64{
        if (x <= 0) return 2e18;
        i64 cnt = 0;
        for (int i = 0; i < n; i++) {
            i64 cur = (x + a[i].w - 1) / a[i].w;
            if (a[i].u >= cur) {
                cnt += (a[i].u - cur) / a[i].v + 1;
            }
        }
        return cnt;
    };

    i64 l = 1, r = 1e12, X;
    while (l <= r) {
        i64 mid = (l + r) >> 1;
        if(calc(mid) <= m) {
            X = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    i64 inv2 = qpow(2, MOD - 2), sum = 0;
    ans = 0;
    for(auto &[u, v, w]: a) {
        i64 cur = (X + w - 1) / w;
        if(u >= cur) {
            i64 c = (u - cur) / v + 1;
            sum += c;
            i64 sum_u = c % MOD * u % MOD;
            i64 sum_v = c % MOD * (c - 1) % MOD;
            sum_v = sum_v * inv2 % MOD;
            sum_v = sum_v * v % MOD;
            i64 sum_ = (sum_u - sum_v + MOD) % MOD;
            sum_ = sum_ * w % MOD;
            ans = (ans + sum_) % MOD;
        }
    }
    if(X > 1 and sum < m) {
        i64 add = (min(m - sum, calc(X - 1) - sum) % MOD) * (X - 1) % MOD;
        ans = (ans + add) % MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (; T--; solve());
    return 0;
}
