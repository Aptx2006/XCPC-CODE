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

const int MAXN = 2E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;
const int N = 2e5 + 5;

struct nod {
    int maxS, minS, maxD, minD;
};

const nod n1 = {-INF, INF, -INF, INF};

nod tree[MAXN * 4];
int s[MAXN], d[MAXN];

nod merge(nod x, nod y) {
    nod tmp = n1;
    tmp.maxD = max(x.maxD, y.maxD);
    tmp.maxS = max(x.maxS, y.maxS);
    tmp.minD = min(x.minD, y.minD);
    tmp.minS = min(x.minS, y.minS);
    return tmp;
}

void build(int id, int l, int r) {
    if (l == r) {
        tree[id].maxS = tree[id].minS = s[l];
        tree[id].maxD = tree[id].minD = d[r];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    tree[id] = merge(tree[id << 1], tree[id << 1 | 1]); 
}

void upd(int u, int L, int R, int id, int ss, int dd) {
    if (L == R) {
        tree[u].maxS = tree[u].minS = ss;
        tree[u].maxD = tree[u].minD = dd;
        return; 
    }
    int mid = (L + R) >> 1;
    if (id <= mid) upd(u << 1, L, mid, id, ss, dd);
    else upd(u << 1 | 1, mid + 1, R, id, ss, dd);
    tree[u] = merge(tree[u << 1], tree[u << 1 | 1]); 
}

nod get(int ql, int qr, int id, int l, int r) {
    if (r < ql || l > qr) return n1;
    if (ql <= l && r <= qr) return tree[id];
    int mid = (l + r) >> 1;
    nod ln = get(ql, qr, id << 1, l, mid);
    nod rn = get(ql, qr, id << 1 | 1, mid + 1, r);
    return merge(ln, rn);
}

void solve() { 
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        s[i] = x + y;
        d[i] = x - y;
    }
    build(1, 1, n);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i, x, y;
            cin >> i >> x >> y;
            int ss = x + y, dd = x - y;
            upd(1, 1, n, i, ss, dd);
        } else {
            int l, r, x, y;
            cin >> l >> r >> x >> y;
            nod res = get(l, r, 1, 1, n);
            int cur_s = x + y, cur_d = x - y; 
            int ans = 0;
            ans = max({cur_s - res.minS, res.maxS - cur_s, cur_d - res.minD, res.maxD - cur_d});
            cout << ans << '\n'; 
        }
    }   
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;// cin >> times;
    while (times--) solve();
    return 0;
}
