// Problem: 静海拾光
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/contest/problem?cid=1198&pid=1010
// StartTime 2026-03-27 21:55:35
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
#define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
    cin >> n >> k;
    vector<int> res;
    int x = n, ck = k;
    while (1) {
        int f = 1;
        for (int i = 1; i <= x; i++) {
            int mi = x - i;
            int p = 1ll << mi;
            if (mi > 60) p = INF;
            if (ck > p)
                ck -= p;
            else {
                res.push_back(i);
                if (ck == 1) goto A;
                ck--;
                x = mi;
                f = 0;
                break;
            }
        }
        if (f) break;
    }
A:
    for (auto &x : res) cout << x << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
