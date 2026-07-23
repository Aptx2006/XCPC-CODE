#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;

void solve() {
    i64 x, y;
    cin >> x >> y >> n >> m;
    vector<i64> a(n), b(m);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    i64 inf = 1e9;
    a.push_back(0),
    b.push_back(0);
    vector<i64> X{x, x + *max_element(all(a)), x + *min_element(all(a))};
    vector<i64> Y{y, y + *max_element(all(b)), y + *min_element(all(b))};
    ans = x * y;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            ans = max(ans, X[i] * Y[j]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
