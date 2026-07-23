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

const int MOD = 998244353, INF = 1E18;

int n, m, t, ans, cnt, k;

void solve() { 
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    sort(all(a)), sort(all(b));
    vector<int> pre(m + 1);
    for(int i = 0; i < m; i++) {
        pre[i + 1] = pre[i] + b[i];
        if(pre[i + 1] >= MOD) pre[i + 1] -= MOD;
    }
    auto it = b.begin();
    for(auto &x : a) {
        it = upper_bound(it, b.end(), x);
        k = it - b.begin();
        int sum = x * k % MOD;
        sum -= pre[k];
        if(sum < 0) sum += MOD;
        ans += sum;
        if(ans >= MOD) ans -= MOD;
        int sum2 = pre[m] - pre[k];
        if(sum2 < 0) sum2 += MOD;
        sum2 = (sum2 + (k - m) * x) % MOD;
        while(sum2 < 0) sum2 += MOD;
        ans += sum2;
        if(ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;// cin >> times;
    while (times--) solve();
    return 0;
}
