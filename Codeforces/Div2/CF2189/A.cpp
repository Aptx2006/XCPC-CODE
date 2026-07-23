// Problem: A. Table with Numbers
// Contest: Codeforces - Codeforces Round 1075 (Div. 2)
// URL: https://codeforces.com/contest/2189/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
//#define int long long

const int MAXN = 1E4 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, h, l, m, t, ar[MAXN], ans, cnt, k;

void solve() {
    cin >> n >> h >> l;
    vector<int> a(n);
    // vector<int> mp(MAXN);
    ans = cnt = k = 0;
    for (auto &x : a) {
        cin >> x;
        if (x <= min(h, l))
            cnt++;
        else if (x <= max(h, l))
            k++;
    }
    if (cnt >= k) {
        ans += k + (cnt - k) / 2;
    } else
        ans = cnt;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
