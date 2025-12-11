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

const int MAXN = 2E5 + 5, MOD = 998244353, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;
//vector<int> G[MAXN];

void solve() { 
    //for(int i = 1; i <= n; i ++) G[i].clear();
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> ar[i];
    vector< pair<int, int> > G(m);
    for(auto &[u, v] : G) cin >> u >> v;
    sort(all(G), [&](auto o1, auto o2){
        return ar[o1.second] < ar[o2.second];
    });

    ans = 0;
    vector< map<int, int> > mp(n + 1);
    // a b c ,c = a + b, a = c - b
    for(auto &[u, v] : G) {
        int last = ar[v] - ar[u];
        if(last > 0 and  mp[u].count(last)) {
            ans = (ans + mp[u][last] + 1) % MOD;
            mp[v][ ar[u] ] = (mp[v][ar[u]] + mp[u][last] + 1) % MOD;
        }else {
            ans = (ans + 1) % MOD;
            mp[v][ ar[u] ] = (mp[v][ ar[u] ] + 1) % MOD;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1; cin >> times;
    while (times--) solve();
    return 0;
}
