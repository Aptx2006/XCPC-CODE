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

int n, m, t, cnt, k;

void solve() { 
    cin >> n >> m;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    vector<int> id(n);
    iota(all(id), 0);
    sort(all(id), [&](auto o1, auto o2){
        return a[o1] < a[o2];
    });
    if(m == 0) {
        vector<int> suf(n + 1);
        suf[n - 2] = a[id[n - 2]];
        for(int i = n - 3; i >= 0; i--) {
            suf[i] = suf[i + 1] + a[id[i]];
        }
        int xid = -1;
        for(int i = n - 2; i >= 0; i--) {
            if(suf[i] >= a[id[n - 1]]) {
                xid = i;
                break;
            }
        }
        if(xid == -1) {
            cout << -1 << '\n';
            return;
        }
        vector< pair<int, int> > ans;
        for(int i = 0; i < xid; i++) ans.push_back({id[i], id[i + 1]});
        for(int i = xid + 1; i < n - 1; i++) ans.push_back({id[i], id[n - 1]});
        ans.push_back({id[xid], id[n - 1]});
        cout << n - 1 << '\n';
        for(auto &[x, y] : ans ) cout << x + 1 << ' ' << y + 1 << '\n';
    }else if(m == 1) {
        cout << n - 1 << '\n';
        for(int i = 1; i < n; i++) cout << id[i - 1] + 1 << ' ' << id[i] + 1 << '\n';
    }else {
        vector< pair<int, int> > ans;
        if(n < 2 * m) {
            cout << -1 << '\n';
            return;
        }
        cout << n - m << '\n';
        for(int i = 0; i < n - m; i++) cout << id[i] + 1 << ' ' << id[n - m] + 1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1; cin >> times;
    while (times--) solve();
    return 0;
}
