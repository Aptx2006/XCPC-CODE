// Problem: C - 2x2 Placing
// Contest: AtCoder - AtCoder Beginner Contest 436
// URL: https://atcoder.jp/contests/abc436/tasks/abc436_c
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
#define dbg(A) cout << #A << "==" << A << '\n';
#define all(A) A.begin(), A.end()
//#define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
    cin >> n >> m;
    set<pair<int, int>> st;
    while (m--) {
        int i, j;
        cin >> i >> j;
        if (!st.count({i, j}) and !st.count({i + 1, j}) and
            !st.count({i, j + 1}) and !st.count({i + 1, j + 1})) {
            st.insert({i, j}), st.insert({i + 1, j}), st.insert({i, j + 1}),
                st.insert({i + 1, j + 1});
        }
    }
    cout << st.size() / 4;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;  // cin >> times;
    while (times--) solve();
    return 0;
}
