// Problem: D. Divisibility Game
// Contest: Codeforces - Educational Codeforces Round 187 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2203/problem/D
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

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
    cin >> n >> m;
    vector<int> a(n), b(m);
    vector<int> buc(n + m + 5, 0), dv(n + m + 5, 0);
    for (auto &x : a) cin >> x, buc[x] = 1;
    for (auto &x : b) cin >> x;
    int lcm = 1;
    auto Lcm = [](int a, int b) { return a / __gcd(a, b) * b; };
    for (int i = 1; i <= n + m; i++) {
        if (!buc[i]) continue;
        lcm = Lcm(lcm, i);
        if (lcm > n + m) break;
    }
    for (int i = 1; i <= n + m; i++) {
        if (!buc[i]) continue;
        for (int j = i; j <= n + m; j += i) dv[j] = 1;
    }
    int ct[3] = {0};
    // cout << lcm << endl;
    for (auto &x : b)
        if (x % lcm == 0)
            ct[0]++;
        else if (!dv[x])
            ct[1]++;
        else
            ct[2]++;
    if (ct[0] + (ct[2] & 1) > ct[1])
        cout << "Alice\n";
    else
        cout << "Bob\n";
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
