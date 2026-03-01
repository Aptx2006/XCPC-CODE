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

int n, m, t, ans, cnt, k;

void solve() { 
    cin >> n;
    vector<int> a(n), suf(n + 1);
    for(auto &x : a) cin >> x;
    //for(int i = n - 1; i >= 0; i--) suf[i] = suf[i + 1] + a[i];
    int mn = -a[n - 1], mx = a[n - 1];
    for(int i = n - 2; i >= 0 ;i--) {
        ans = mn + max(0ll, a[i] + mx);
        mn -= a[i];
        mx = max(mx, ans - mn);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1; cin >> times;
    while (times--) solve();
    return 0;
}
