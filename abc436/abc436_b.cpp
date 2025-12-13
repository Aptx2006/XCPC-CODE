// Problem: B - Magic Square
// Contest: AtCoder - AtCoder Beginner Contest 436
// URL: https://atcoder.jp/contests/abc436/tasks/abc436_b
// Memory Limit: 1024 MB
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
#define dbg(A) cout << #A << "==" << A << endl;
#define all(A) A.begin(), A.end()
//#define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
    cin >> n;
    vector<vector<int>> G(n, vector<int>(n, 0));
    G[0][(n - 1) / 2] = 1;
    int r = 0, c = (n - 1) / 2, k = 1;
    cnt = n * n - 1;
    while (cnt--) {
        if (G[(r + n - 1) % n][(c + 1) % n])
            r = (r + 1) % n;  // G[(r + 1) % n][c] = k + 1;
        else
            r = (r + n - 1) % n,
            c = (c + 1) % n;  // G[(r + n - 1) % n][(c + 1) % n] = k + 1;
        G[r][c] = k + 1;
        k++;
    }
    for (auto &v : G) {
        for (auto &x : v) cout << x << ' ';
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;  // cin >> times;
    while (times--) solve();
    return 0;
}
