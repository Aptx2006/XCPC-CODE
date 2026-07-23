// Problem: B. New Year Cake
// Contest: Codeforces - Educational Codeforces Round 186 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2182/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

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

int n, m, t, ar[MAXN], ans, k;

void solve() {
    cin >> n >> m;
    ans = 0;
    int cnt[2] = {0};
    while (1) {
        int need = 1ll << ans;
        int tcnt[2] = {cnt[0], cnt[1]};
        tcnt[~ans & 1] += need;
        if (tcnt[0] <= n and tcnt[1] <= m or (tcnt[1] <= n and tcnt[0] <= m)) {
            ans++;
            cnt[0] = tcnt[0], cnt[1] = tcnt[1];
        } else
            break;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
