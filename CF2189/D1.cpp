// Problem: D1. Little String (Easy Version)
// Contest: Codeforces - Codeforces Round 1075 (Div. 2)
// URL: https://codeforces.com/contest/2189/problem/D1
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
    cin >> n >> m;
    string s;
    cin >> s;
    if (m == 1 or s[0] == '0' or s[n - 1] == '0') {
        cout << "-1\n";
        return;
    }
    ans = 1;
    int cc = ans % m;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '1') {
            ans = (ans << 1) % MOD;
            cc = (cc << 1) % m;
        } else {
            ans = (ans * i) % MOD;
            cc = (cc * i) % m;
        }
    }
    if (cc % m == 0)
        cout << "-1\n";
    else
        cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
