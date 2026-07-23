// Problem: C. Simons and Posting Blogs
// Contest: Codeforces - Codeforces Round 1083 (Div. 2)
// URL: https://codeforces.com/contest/2205/problem/C
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

int n, m, t, ar[MAXN], cnt, k;

void solve() {
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> t;
        a[i].resize(t);
        for (int j = 0; j < t; j++) cin >> a[i][j];
    }

    auto reduce = [](const vector<int>& a) {
        set<int> st;
        vector<int> res;
        for (int i = a.size() - 1; i >= 0; i--) {
            if (!st.count(a[i])) {
                st.insert(a[i]);
                res.push_back(a[i]);
            }
        }
        return res;
    };

    vector<vector<int>> b(n);
    for (int i = 0; i < n; i++) b[i] = reduce(a[i]);

    set<int> s;
    vector<int> ans, vis(n + 5, 1);

    auto fun = [&](const vector<int>& b) {
        vector<int> res;
        for (int x : b)
            if (!s.count(x)) res.push_back(x);
        return res;
    };

    for (int k = 0; k < n; k++) {
        int id = -1;
        vector<int> cur;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) continue;
            vector<int> tmp = fun(b[i]);
            if (id == -1 or tmp < cur) {
                id = i;
                cur = tmp;
            }
        }
        vis[id] = 0;
        ans.insert(ans.end(), all(cur));
        for (auto& x : b[id]) s.insert(x);
    }

    for (auto& x : ans) cout << x << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
