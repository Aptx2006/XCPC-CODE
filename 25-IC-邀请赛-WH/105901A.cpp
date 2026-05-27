#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

const int INF = 2E9;
i64 T, n, m, k, ans, cnt;

void solve() {
    int q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector< pair<int, int> > upd(n, {-1, INF});
    while(q--) {
        int i, l, r;
        cin >> i >> l >> r;
        auto &[ll, rr] = upd[i - 1];
        ll = max(ll, l), rr = min(rr, r);
    }
    ans = 0;
    for(int i = 0; i < n; i++) {
        auto &[ll, rr] = upd[i];
        if(ll > rr) {
            ans = -1;
            break;
        }
        if(a[i] > rr) ans += a[i] - rr;
        else if(a[i] < ll) ans += ll - a[i];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
