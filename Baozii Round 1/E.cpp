#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize(2)
/*i32 : -2e9~2e9
i64: -9e18~9e18
u64: 0~1.8e19*/
using i64 = long long;
using u64 = unsigned long long;
#define dbg(A) cout << #A << "==" << A << '\n';
#define all(A) A.begin(), A.end()
#define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;

void solve() { 
    cin >> n;
    vector< pair<int, int> > a(n);
    for(auto &[x, y] : a) cin >> x >> y;
    vector<int> id(n);
    iota(all(id), 0);
    const int B = 1000;
    sort(all(id), [&](auto o1, auto o2){
        auto [x1, y1] = a[o1];
        auto [x2, y2] = a[o2];
        x1 = x1 / B, x2 = x2 / B;
        if(x1 != x2) return x1 < x2;
        if(x1 & 1) return y1 < y2;
        return y1 > y2;
    });
    for(int i = 0; i < n; i++) {
        auto [x1, y1] = a[ id[i] ];
        auto [x2, y2] = a[ id[ (i + 1) % n ] ];
        ans += llabs(x1 - x2) + llabs(y1 - y2);
        cout << id[i] + 1 << ' ';
        //dbg(ans)
    }
    //dbg(ans);
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1; //cin >> times;
    while (times--) solve();
    return 0;
}
