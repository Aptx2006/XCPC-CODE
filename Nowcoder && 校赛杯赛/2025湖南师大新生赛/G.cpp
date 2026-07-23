// Problem: Maxduan 的数组转化
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/124874/G
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
    cin >> n;
    vector<int> a(n), b(n);
    int suma = 0, sumb = 0;
    for (auto &x : a) cin >> x, suma += x;
    for (auto &x : b) cin >> x, sumb += x;
    k = 2 - n;
    if (n == 1) {
        if (suma <= sumb)
            cout << "YES\n";
        else
            cout << "NO\n";
    } else if (n == 2) {
        if (suma == sumb)
            cout << "YES\n";
        else
            cout << "NO\n";
    } else {
        if (suma < sumb or (suma - sumb) % k != 0)
            cout << "NO\n";
        else {
            int tag = (sumb - suma) / k;
            for (int i = 0; i < n; i++) {
                t = (b[i] - a[i]) + tag;
                if (t < 0 or t & 1) {
                    cout << "NO\n";
                    return;
                }
            }
            cout << "YES\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
