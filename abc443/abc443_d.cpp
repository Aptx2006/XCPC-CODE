// Problem: D - Pawn Line
// Contest: AtCoder - Denso Create Programming Contest 2026（AtCoder Beginner
// Contest 443） URL: https://atcoder.jp/contests/abc443/tasks/abc443_d Memory
// Limit: 1024 MB Time Limit: 2000 ms
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

const int MAXN = 3E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;
int dp[MAXN], dpp[MAXN];

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> dp = a;
    for (int i = 1; i < n; i++) {
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = min(dp[i], dp[i + 1] + 1);
    }
    ans = 0;
    for (int i = 0; i < n; i++) ans += a[i] - dp[i];
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
