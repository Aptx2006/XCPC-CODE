#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    //cin >> n;
    vector<i64> a(3);
    for(auto &x: a) cin >> x;
    i64 ans = 0;
    if(3 * a[1] > a[2]) {
        ans = a[0] / 3 * a[2];
        a[0] = a[0] % 3;
        ans += min(a[0] * a[1], a[2]);
    }else {
        ans = a[0] * a[1];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
