#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

const int mod = 998244353;
const int N = 1e6 + 5;
const int inv2 = (mod + 1) / 2;

/*
oeis A069891
*/

vector<int> g(N, 1), pre(N);
vector<bool> vis(N);

i64 sqr(i64 x) {
    i64 y = sqrtl(x);
    while((y + 1) * (y + 1) <= x) y++;
    while(y * y > x) y--;
    return y;
}

void init() {
    for(int p = 2; p < N; p++) {
        if(vis[p]) continue;
        for(int j = p; j < N; j += p) {
            vis[j] = true;
            g[j] = 1LL * g[j] * (1 - 1LL * p * p % mod + mod) % mod;
        }
    }

    for(int i = 1; i < N; i++) {
        pre[i] = (pre[i - 1] + g[i]) % mod;
    }
}

i64 calc(i64 n) {
    if(n <= 0) return 0;

    i64 res = 0;
    i64 lim = sqr(n);

    for(i64 l = 1, r; l <= lim; l = r + 1) {
        i64 q = n / (l * l);

        r = sqr(n / q);
        r = min(r, lim);

        i64 s = (pre[r] - pre[l - 1] + mod) % mod;

        i64 sum = q % mod;
        sum = sum * ((q + 1) % mod) % mod;
        sum = sum * inv2 % mod;

        res = (res + s * sum) % mod;
    }

    return res;
}

void solve() {
    i64 l, r;
    cin >> l >> r;

    cout << (calc(r) - calc(l - 1) + mod) % mod << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    for(cin >> T; T--; solve());
    return 0;
}
