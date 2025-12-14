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
//#define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E9;

int n, m, t, ar[MAXN], ans, cnt, k;
vector<int> G[MAXN];
void solve() { 
    cin >> n >> m;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    for(int i = 0, u , v; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v),G[v].push_back(u);
    }
    int mx = *max_element(all(a));
    for(int i = 0; i < n; i++){
        if(a[i] == mx and (int)G[i].size() >= 2){
            cout << mx; return;
        }
    }
    if(n == 1) cout << a[0];
    else {
        sort(all(a));
        cout << a[n - 2];
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1; //cin >> times;
    while (times--) solve();
    return 0;
}
