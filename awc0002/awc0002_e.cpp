// Problem: E - Assortment of Sweets
// Contest: AtCoder - AtCoder Weekday Contest 0002 Beta
// URL: https://atcoder.jp/contests/awc0002/tasks/awc0002_e
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
#define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int N = n / 2, M = n - n / 2;
    vector<int> l, r;
    for (int b = 0; b < (1 << N); b++) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (b & (1ll << i)) sum += a[i];
        }
        l.push_back(sum);
    }
    for (int b = 0; b < (1 << M); b++) {
        int sum = 0;
        for (int i = 0; i < M; i++) {
            if (b & (1ll << i)) sum += a[N + i];
        }
        r.push_back(sum);
    }
    sort(all(r));
    for (auto &x : l) {
        int tag = m - x;
        int it = lower_bound(all(r), tag) - upper_bound(all(r), tag);
        ans -= it;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;  // cin >> times;
    while (times--) solve();
    return 0;
}
