// Problem: B. MEX Reordering
// Contest: Codeforces - Codeforces Round 1073 (Div. 2)
// URL: https://codeforces.com/contest/2191/problem/B
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
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int c0 = count(all(a), 0), c1 = count(all(a), 1);
    if (!c0 or (!c1 and c0 >= 2))
        cout << "NO\n";
    else
        cout << "YES\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
