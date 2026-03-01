// Problem: B. Seats
// Contest: Codeforces - Codeforces Round 1077 (Div. 2)
// URL: https://codeforces.com/contest/2188/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
//#define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
    string s;
    cin >> n >> s;
    cnt = ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            cnt++;
        else {
            if (cnt == i) cnt++;
            ans += cnt / 3;
            cnt = 0;
        }
    }
    t = count(all(s), '1');
    if (cnt != 0) {
        if (t == 0)
            ans = (cnt + 2) / 3;
        else
            ans += (cnt + 1) / 3;
    }
    cout << ans + t << '\n';
}
// 000000 -> 01 0010010010 1
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
