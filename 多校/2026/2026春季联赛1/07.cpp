#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize(2)
/*i32 : -2e9~2e9
i64: -9e18~9e18
u64: 0~1.8e19*/
using i64 = long long;
using u64 = unsigned long long;
#define dbg(A) cout << #A << "==" << A << '\n';
#define all(A) A.begin(), A.end()
// #define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
    cin >> n;
    vector<i64> A(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];
    vector<vector<int>> G(n + 1);
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<vector<int>> son(n + 1);
    vector<int> fa(n + 1, -1);
    queue<int> q;
    q.push(1);
    fa[1] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v : G[u]) {
            if (v != fa[u]) {
                fa[v] = u;
                son[u].push_back(v);
                q.push(v);
            }
        }
    }
    vector<int> size(n + 1);
    vector<i64> f(n + 1), sum(n + 1);
    stack<pair<int, bool>> st;
    st.emplace(1, 0);
    while (!st.empty()) {
        auto [u, vis] = st.top();
        st.pop();
        if (!vis) {
            st.emplace(u, 1);
            for (auto &v : son[u]) st.emplace(v, 0);
        } else {
            sum[u] = A[u];
            size[u] = 1;
            for (auto &v : son[u]) {
                sum[u] += sum[v];
                size[u] += size[v];
            }
            f[u] = sum[u] / size[u];
            for (int v : son[u]) f[u] = min(f[u], f[v]);
        }
    }
    for (int i = 1; i <= n; i++) cout << f[i] << " \n"[i == n];
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int times = 1;
    int size(256 << 20);  // 256M
    __asm__("movq %0, %%rsp\n" ::"r"((char *)malloc(size) + size));
    cin >> times;
    while (times--) solve();
    exit(0);
}
