// Problem: A. Simons and Making It Beautiful
// Contest: Codeforces - Codeforces Round 1083 (Div. 2)
// URL: https://codeforces.com/contest/2205/problem/A
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
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == n) pos = i;
    }
    swap(a[0], a[pos]);
    for (auto x : a) cout << x << " ";
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
