// Problem: E. Idiot First Search
// Contest: Codeforces - Codeforces Round 1080 (Div. 3)
// URL: https://codeforces.com/contest/2195/problem/E
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

const int MAXN = 3E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;

int G[MAXN], res[MAXN], l[MAXN], r[MAXN];

void dfs1(int u) {
    if (l[u] == 0) {
        G[u] = 1;
        return;
    }
    dfs1(l[u]), dfs1(r[u]);
    G[u] = (G[l[u]] + G[r[u]] + 3) % MOD;
}

void dfs2(int u, int s) {
    s = (s + G[u]) % MOD;
    res[u] = s;
    if (l[u]) {
        dfs2(l[u], s);
        dfs2(r[u], s);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
    dfs1(1);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) cout << res[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
