// Problem: D - Keys and Treasure Boxes
// Contest: AtCoder - AtCoder Weekday Contest 0002 Beta
// URL: https://atcoder.jp/contests/awc0002/tasks/awc0002_d
// Memory Limit: 1024 MB
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
//#define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    sort(all(a)), sort(all(b));
    int pa = 0, pb = 0;
    while (pa < n and pb < m) {
        if (a[pa] <= b[pb++]) cnt++, pa++;
    }
    cout << cnt << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;  // cin >> times;
    while (times--) solve();
    return 0;
}
