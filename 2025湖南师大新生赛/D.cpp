// Problem: CirnoNine 的数学问题
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/124874/D
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

const int MAXN = 1E7 + 5, MOD = 998244353, INF = 1E18;
int pow10[MAXN];
int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
    cin >> n;
    ans = pow10[n + 1] - 1;
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    pow10[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pow10[i] = 2 * pow10[i - 1];
        while (pow10[i] > MOD) pow10[i] -= MOD;
    }
    int times = 1;  // cin >> times;
    while (times--) solve();
    return 0;
}
