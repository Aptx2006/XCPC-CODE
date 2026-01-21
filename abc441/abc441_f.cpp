// Problem: F - Must Buy
// Contest: AtCoder - AtCoder Beginner Contest 441 (Promotion of Engineer Guild
// Fes) URL: https://atcoder.jp/contests/abc441/tasks/abc441_f Memory Limit:
// 1024 MB Time Limit: 2500 ms
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
    vector<int> p(n + 1), v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i] >> v[i];
    }

    vector<vector<int>> dp1(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        dp1[i] = dp1[i - 1];
        for (int j = m; j >= p[i]; j--) {
            if (dp1[i][j] < dp1[i][j - p[i]] + v[i]) {
                dp1[i][j] = dp1[i][j - p[i]] + v[i];
            }
        }
    }

    vector<vector<int>> dp2(n + 2, vector<int>(m + 1, 0));
    for (int i = n; i >= 1; i--) {
        dp2[i] = dp2[i + 1];
        for (int j = m; j >= p[i]; j--) {
            if (dp2[i][j] < dp2[i][j - p[i]] + v[i]) {
                dp2[i][j] = dp2[i][j - p[i]] + v[i];
            }
        }
    }

    int mx = dp1[n][m];
    string res;

    for (int i = 1; i <= n; i++) {
        auto &L = dp1[i - 1];
        auto &R = dp2[i + 1];

        int mn = 0;
        for (int a = 0; a <= m; a++) {
            int b = m - a;
            if (b < 0) break;
            mn = max(mn, L[a] + R[b]);
        }
        bool f2 = (mn == mx);

        bool f1 = false;
        if (p[i] <= m) {
            int j = m - p[i];
            int pk = 0;
            for (int a = 0; a <= j; a++) {
                int b = j - a;
                if (b < 0) break;
                pk = max(pk, L[a] + R[b]);
            }
            if (v[i] + pk == mx) {
                f1 = true;
            }
        }

        if (f1 and !f2) {
            res += 'A';
        } else if (f1 and f2) {
            res += 'B';
        } else {
            res += 'C';
        }
    }

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;  // cin >> times;
    while (times--) solve();
    return 0;
}
