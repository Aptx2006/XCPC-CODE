#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

const int INF = 2e9 + 7;

struct Point {
    int p, c, id;
};

struct KDNode {
    int min_p, max_p;
    int min_c, max_c;
    int p, c;
    int ls, rs;
} tr[200005];

int root;

void pushup(int u) {
    if (tr[u].ls) {
        tr[u].min_p = min(tr[u].min_p, tr[tr[u].ls].min_p);
        tr[u].max_p = max(tr[u].max_p, tr[tr[u].ls].max_p);
        tr[u].min_c = min(tr[u].min_c, tr[tr[u].ls].min_c);
        tr[u].max_c = max(tr[u].max_c, tr[tr[u].ls].max_c);
    }
    if (tr[u].rs) {
        tr[u].min_p = min(tr[u].min_p, tr[tr[u].rs].min_p);
        tr[u].max_p = max(tr[u].max_p, tr[tr[u].rs].max_p);
        tr[u].min_c = min(tr[u].min_c, tr[tr[u].rs].min_c);
        tr[u].max_c = max(tr[u].max_c, tr[tr[u].rs].max_c);
    }
}

int build(int l, int r, int dim, vector<Point>& pts) {
    if (l > r) return 0;
    int mid = l + (r - l) / 2;
    if (dim == 0) {
        nth_element(pts.begin() + l, pts.begin() + mid, pts.begin() + r + 1, [](const Point& a, const Point& b) {
            return a.p < b.p;
        });
    } else {
        nth_element(pts.begin() + l, pts.begin() + mid, pts.begin() + r + 1, [](const Point& a, const Point& b) {
            return a.c < b.c;
        });
    }
    int u = mid;
    tr[u].p = tr[u].min_p = tr[u].max_p = pts[mid].p;
    tr[u].c = tr[u].min_c = tr[u].max_c = pts[mid].c;
    tr[u].ls = build(l, mid - 1, dim ^ 1, pts);
    tr[u].rs = build(mid + 1, r, dim ^ 1, pts);
    pushup(u);
    return u;
}

inline int eval(int x, int limit, int d) {
    if (x < limit) return 0;
    if (x < limit + d) return x;
    return limit + d;
}

inline int get_est(int u, int tp, int tc, int d) {
    int est_p = (tr[u].min_p < tp) ? 0 : eval(tr[u].min_p, tp, d);
    int est_c = (tr[u].min_c < tc) ? 0 : eval(tr[u].min_c, tc, d);
    return est_p + est_c;
}

void query(int u, int tp, int tc, int d, int &ans) {
    if (!u) return;
    int cur = eval(tr[u].p, tp, d) + eval(tr[u].c, tc, d);
    ans = min(ans, cur);
    
    int dl = tr[u].ls ? get_est(tr[u].ls, tp, tc, d) : INF;
    int dr = tr[u].rs ? get_est(tr[u].rs, tp, tc, d) : INF;
    
    if (dl < dr) {
        if (dl < ans) query(tr[u].ls, tp, tc, d, ans);
        if (dr < ans) query(tr[u].rs, tp, tc, d, ans);
    } else {
        if (dr < ans) query(tr[u].rs, tp, tc, d, ans);
        if (dl < ans) query(tr[u].ls, tp, tc, d, ans);
    }
}

void solve() {
    cin >> n;
    vector<int> p(n), c(n);
    for(auto &x: p) cin >> x;
    for(auto &x: c) cin >> x;
    cin >> m;
    vector<int> tp(m), tc(m), d(m);
    for(auto &x: tp) cin >> x;
    for(auto &x: tc) cin >> x;
    for(auto &x: d) cin >> x;

    vector<Point> pts(n + 1);
    for (int i = 1; i <= n; i++) {
        pts[i] = {p[i - 1], c[i - 1], i};
    }
    root = build(1, n, 0, pts);

    for (int i = 0; i < m; i++) {
        int ans = INF;
        query(root, tp[i], tc[i], d[i], ans);
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(T = 1; T--; solve());
    return 0;
}
