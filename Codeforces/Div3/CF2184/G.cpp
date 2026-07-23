// Problem: G. Nastiness of Segments
// Contest: Codeforces - Codeforces Round 1072 (Div. 3)
// URL: https://codeforces.com/contest/2184/problem/G
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

int n, q;
struct Block {
    int sz, cnt;
    vector<int> a, mn;
    Block(vector<int>& _a) {
        sz = sqrt(n);
        cnt = (n - 1 + sz) / sz;
        a.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) a[i] = _a[i - 1];
        mn.assign(cnt + 1, INF);
        for (int i = 1; i <= n; i++) {
            int bid = getid(i);
            mn[bid] = min(mn[bid], a[i]);
        }
    }
    int getid(int i) { return (i - 1) / sz + 1; }
    void upd(int i, int val) {
        a[i] = val;
        int bid = getid(i);
        mn[bid] = INF;
        int st = (bid - 1) * sz + 1, end = min(n, bid * sz);
        for (int j = st; j <= end; j++) mn[bid] = min(mn[bid], a[j]);
    }
    int qry(int l, int r) {
        if (l > r) return INF;
        int res = INF;
        int lid = getid(l);
        int rid = getid(r);
        if (lid == rid) {
            for (int i = l; i <= r; i++) res = min(a[i], res);
            return res;
        }

        for (int i = l; i <= lid * sz; i++) res = min(res, a[i]);
        for (int i = lid + 1; i <= rid - 1; i++) res = min(res, mn[i]);
        for (int i = (rid - 1) * sz + 1; i <= r; i++) res = min(res, a[i]);

        return res;
    }
};

void solve() {
    cin >> n >> q;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    Block B(a);
    while (q--) {
        int op, i, x, l, r;
        cin >> op;
        if (op - 1) {
            cin >> l >> r;
            int L = 0, R = r - l, ans = -1;
            while (L <= R) {
                int mid = (L + R) >> 1;
                int mn = B.qry(l, l + mid);
                if (mn <= mid) {
                    ans = mid, R = --mid;
                } else
                    L = ++mid;
            }
            if (ans == -1)
                cout << "0\n";
            else if (B.qry(l, l + ans) == ans)
                cout << "1\n";
            else
                cout << "0\n";
        } else {
            cin >> i >> x;
            B.upd(i, x);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
