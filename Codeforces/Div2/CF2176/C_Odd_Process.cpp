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

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;

void solve() { 
    cin >> n;
    vector<i64> odd, eve;
    for(int i  = 0; i < n ; i ++) {
        cin >> t;
        if(t & 1) odd.push_back(t);
        else eve.push_back(t);
    }
    int lene = eve.size(), leno = odd.size();
    if(!leno){
        for(int i = 0; i < n ; i ++) 
            cout << 0 << " \n"[i == n - 1];
        return;
    }
    sort(all(eve), greater<i64>());
    sort(all(odd), greater<i64>());

    vector<i64> psum(lene + 1, 0);
    for(int i = 1; i <= lene; i ++) 
        psum[i] = psum[i - 1] + eve[i - 1];

    int m = lene + leno;
    if(~leno & 1) m--;
    for(int i = 1; i <= m; i ++) {
        i64 ans = 0;
        if(lene >= 1 and i >= 1){
            int p = min(i, lene);
            ans = psum[p - 1] + odd[0];
        }
        if(i >= lene + 1 && i % 2 != lene % 2) 
            ans = max(ans, psum[lene] + odd[0]);
        cout << ans << " \n"[i == n];
    }
    if(~leno & 1) cout << "0\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1; cin >> times;
    while (times--) solve();
    return 0;
}
