// Problem: Exquisite Array
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/2184/problem/E
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
struct dsu {
    vector<int> fa, sz;
    int sum;
    dsu(int _n) {
        fa.resize(_n);
        iota(all(fa), 0);
        sz.assign(_n, 0);
        sum = 0;
    }
    int find(int i) { return fa[i] == i ? i : fa[i] = find(fa[i]); }
    void merge(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra != rb) {
            sum -= sz[ra] * (sz[ra] + 1) / 2;
            sum -= sz[rb] * (sz[rb] + 1) / 2;
            fa[rb] = ra;
            sz[ra] += sz[rb];
            sum += sz[ra] * (sz[ra] + 1) / 2;
        }
    }
};

void solve() {
    cin >> n;
    vector<int> p(n);
    for (auto &x : p) cin >> x;
    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; i++) {
        G[abs(p[i] - p[i + 1])].push_back(i);
    }
    dsu D(n - 1);
    vector<int> ans(n - 1);
    for (int i = n - 1; i >= 1; i--) {
        for (auto id : G[i]) {
            D.sz[id] = 1, D.sum++;
            if (id != 0 and D.sz[id - 1] > 0) D.merge(id - 1, id);
            if (id != n - 2 and D.sz[id + 1] > 0) D.merge(id, id + 1);
        }
        ans[i - 1] = D.sum;
    }
    for (auto &x : ans) cout << x << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
