// Problem: 三途川畔
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/contest/problem?cid=1198&pid=1004
// StartTime 2026-03-27 21:19:25
// Memory Limit: 524288 MB
// Time Limit: 1000 ms
// Coder:Aptx4869
//
// Powered by CP Editor (https://cpeditor.org)

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
// #define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
    cin >> n >> k;
    if ((n + k) & 1) {
        cout << "3 " << (n + 1 + k) / 2 << " ";
    } else {
        cout << "2 " << n + k << " ";
    }
    for (int i = 2; i < n; i++) cout << 1 << " \n"[i == n - 1];
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
