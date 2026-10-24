#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n >> m;
    i64 x, y, z;
    cin >> x >> y >> z;
    vector<i64> a(n);
    for(auto &x: a) cin >> x;

    const i64 inf = 4e18;
    vector<i64> f(n, inf);
    i64 cost = x + n * z, res = 0;
    for(int j = 0; j < m; j++) {
        i64 b, mn = res + cost;
        cin >> b;
        res = inf;
        for(int i = 0; i < n; i++) {
            i64 tmp = f[i];
            f[i] = mn + llabs(a[i] - b) * y - z;
            mn = min(mn, tmp);
            res = min(res, f[i]);
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
