// Problem: D. Simons and Beating Peaks
// Contest: Codeforces - Codeforces Round 1083 (Div. 2)
// URL: https://codeforces.com/contest/2205/problem/D
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

const int MAXN = 5E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;

using cv = const vector<int>;

int dfs(int u, cv& L, cv& R) {
    if (u == 0) {
        return 0;
    }
    return 1 + max(dfs(L[u], L, R), dfs(R[u], L, R));
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> ar[i];

    vector<int> L(n + 1, 0), R(n + 1, 0), fa(n + 1, 0);
    vector<int> st;

    for (int i = 1; i <= n; i++) {
        int flag = 0;
        while (!st.empty() and ar[st.back()] < ar[i]) {
            flag = st.back();
            st.pop_back();
        }
        if (!st.empty()) {
            R[st.back()] = i;
            fa[i] = st.back();
        }
        if (flag) L[i] = flag, fa[flag] = i;
        st.push_back(i);
    }

    int root = 1;
    while (fa[root]) root = fa[root];

    cout << n - dfs(root, L, R) << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
