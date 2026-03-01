// Problem: C. Test Generator
// Contest: Codeforces - Educational Codeforces Round 187 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2203/problem/C
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
    cin >> n >> m;
    int l = 1, r = n, ans = -1;

    auto isok = [&](int x) {
        int L = 0, R = 0;
        for (int b = 0; b <= 63; b++) {
            int tag = (n >> b) & 1ll;
            int mn = L, mx = R;
            if ((m >> b) & 1ll) mx += x;
            if ((mn & 1ll) != tag) mn++;
            if ((mx & 1ll) != tag) mx--;
            if (mn > mx) return false;
            L = mn >> 1, R = mx >> 1;
        }
        for (int b = 0; b <= 63; b++) {
            int tag = 0;
            int mn = L, mx = R;
            // if ((m >> b) & 1ll) mx += x;
            if ((mn & 1ll) != tag) mn++;
            if ((mx & 1ll) != tag) mx--;
            if (mn > mx) return false;
            L = mn >> 1, R = mx >> 1;
        }
        return L == 0 and R == 0;
    };

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (isok(mid)) {
            ans = mid, r = --mid;
        } else
            l = ++mid;
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
