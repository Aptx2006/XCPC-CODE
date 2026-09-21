#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m;
int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};

void solve() {
    cin >> n >> m;
    vector<pair<i64, i64>> a(n);
    for(auto &[x, y]: a) cin >> x >> y;
    sort(all(a), greater<pair<i64, i64>>());
    //for(auto &[x, y]: a) cout << x << ' ' << y << endl;
    i64 ans = 0;
    for(auto &[x, y]: a) {
        i64 cur = min(y, m);
        ans += x * cur;
        m -= cur;
        if(m == 0) break;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
