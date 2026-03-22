#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize(2)
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

int qpow(int base, int mi, int res = 1) {
    while (mi) {
        if (mi & 1) res *= base;
        if (res > n or base > n) return n + 1;
        base *= base;
        mi >>= 1;
    }
    return res;
}

void solve() {
    cin >> n >> k;
    int l = 1, r = n;
    ans = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (qpow(mid, k) > n) {
            ans = min(ans, mid);
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << ans - 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
