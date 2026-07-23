// Problem: Maxduan 的卡片翻转
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/124874/E
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

int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    cnt = ans = 0;
    int mn = INF;
    for (int i = 0; i < n; i++) {
        if (b[i] > a[i]) cnt++;
        mn = min(mn, llabs(a[i] - b[i]));
    }
    if (cnt <= k) {
        for (int i = 0; i < n; i++) ans += max(a[i], b[i]);
        if ((k - cnt) & 1) ans -= mn;
        cout << ans << '\n';
    } else {
        vector<int> id(n);
        for (int i = 0; i < n; i++) id[i] = i;
        sort(all(id), [&](auto o1, auto o2) {
            return (b[o1] - a[o1]) > (b[o2] - a[o2]);
        });
        for (int i = 0; i < k; i++) {
            swap(a[id[i]], b[id[i]]);
        }
        for (int i = 0; i < n; i++) ans += a[i];
        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
