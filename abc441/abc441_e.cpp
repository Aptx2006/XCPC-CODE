// Problem: E - A > B substring
// Contest: AtCoder - AtCoder Beginner Contest 441 (Promotion of Engineer Guild
// Fes) URL: https://atcoder.jp/contests/abc441/tasks/abc441_e Memory Limit:
// 1024 MB Time Limit: 2000 ms
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

struct FWT {
    vector<int> tree;
    FWT(int size) : tree(size + 1, 0) {}

    void upd(int idx, int d) {
        while (idx < tree.size()) {
            tree[idx] += d;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int res = 0;
        while (idx > 0) {
            res += tree[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

void solve() {
    string s;
    cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A')
            a[i] = 1;
        else if (s[i] == 'B')
            a[i] = -1;
        else
            a[i] = 0;
    }

    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i - 1];
    }

    vector<int> sp = pre;
    sort(all(sp));
    sp.erase(unique(all(sp)), sp.end());

    FWT ft(sp.size());

    int rank0 = lower_bound(all(sp), pre[0]) - sp.begin() + 1;
    ft.upd(rank0, 1);

    for (int j = 1; j <= n; ++j) {
        int x = pre[j];
        int r = lower_bound(sp.begin(), sp.end(), x) - sp.begin() + 1;
        ans += ft.query(r - 1);
        ft.upd(r, 1);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;  // cin >> times;
    while (times--) solve();
    return 0;
}
