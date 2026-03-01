// Problem: D. Absolute Cinema
// Contest: Codeforces - Codeforces Round 1080 (Div. 3)
// URL: https://codeforces.com/contest/2195/problem/D
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
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> b(n);
    int sum = 0, cnt = 0;
    for (int i = 1; i < n - 1; i++) {
        b[i] = (a[i - 1] + a[i + 1] - 2 * a[i]) / 2;
        sum += b[i];
        cnt += b[i] * i;
    }
    cout << a[1] - a[0] + sum + (a[0] - cnt) / (n - 1) << " ";
    for (int i = 1; i < n - 1; i++) cout << b[i] << " ";
    cout << (a[0] - cnt) / (n - 1) << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
