// Problem: C. Restricted Sorting
// Contest: Codeforces - Codeforces Round 1077 (Div. 2)
// URL: https://codeforces.com/contest/2188/problem/C
// Memory Limit: 256 MB
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
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int mx = *max_element(all(a)), mn = *min_element(all(a));
    int f = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            f = 1;
        }
    }
    if (!f) {
        cout << "-1\n";
        return;
    }
    int l = 1, r = mx - mn;
    ans = -1;
    vector<int> aa = a;
    sort(all(aa));
    auto isok = [&](int mid) {
        int f = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] + mid > mx and a[i] - mid < mn and a[i] != aa[i]) f = 0;
        }
        return f;
    };
    while (l <= r) {
        int mid = l + r >> 1;
        if (isok(mid)) {
            ans = mid, l = ++mid;
        } else
            r = --mid;
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
