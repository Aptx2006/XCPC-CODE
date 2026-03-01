// Problem: C. Dice Roll Sequence
// Contest: Codeforces - Codeforces Round 1080 (Div. 3)
// URL: https://codeforces.com/contest/2195/problem/C
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
    vector<int> a(n), mn(10);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < 6; i++) mn[i] = (i != a[0] - 1);
    for (int i = 1; i < n; i++) {
        vector<int> mnn(10, INF);
        for (int j = 0; j < 6; j++) {
            t = (j != a[i] - 1);
            for (int k = 0; k < 6; k++) {
                if (j != k and j + k != 5) {
                    mnn[j] = min(mnn[j], mn[k] + t);
                }
            }
        }
        mn = mnn;
    }
    cout << *min_element(all(mn)) << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
