#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using u128 = unsigned __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

template<class T> struct Segt {
    struct node {
        int l, r;
        T w, rmq, lazy;
    };
    vector<T> w;
    vector<node> t;

    Segt() {}
    Segt(int n) { init(n); }
    Segt(vector<int> in) {
        int n = in.size() - 1;
        w.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            w[i] = in[i];
        }
        init(in.size() - 1);
    }
    
    #define GL (k << 1)
    #define GR (k << 1 | 1)
    
    void init(int n) {
        w.resize(n + 1);
        t.resize(n * 4 + 1);
        auto build = [&](auto self, int l, int r, int k = 1) {
            if (l == r) {
                t[k] = {l, r, w[l], w[l], -1}; // 如果有赋值为 0 的操作，则懒标记必须要 -1
                return;
            }
            t[k] = {l, r, 0, 0, -1};
            int mid = (l + r) / 2;
            self(self, l, mid, GL);
            self(self, mid + 1, r, GR);
            pushup(k);
        };
        build(build, 1, n);
    }
    void pushdown(node &p, T lazy) { /* 【在此更新下递函数】 */
        p.w = max(p.w, lazy);
        p.rmq = max(p.rmq, lazy);
        p.lazy = max(p.lazy, lazy);
    }
    void pushdown(int k) {
        if (t[k].lazy == -1) return;
        pushdown(t[GL], t[k].lazy);
        pushdown(t[GR], t[k].lazy);
        t[k].lazy = -1;
    }
    void pushup(int k) {
        auto pushup = [&](node &p, node &l, node &r) { /* 【在此更新上传函数】 */
            p.w = max(l.w, r.w);
            p.rmq = max(l.rmq, r.rmq); // RMQ -> min/max
        };
        pushup(t[k], t[GL], t[GR]);
    }
    void modify(int l, int r, T val, int k = 1) { // 区间修改
        if (l <= t[k].l && t[k].r <= r) {
            pushdown(t[k], val);
            return;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;
        if (l <= mid) modify(l, r, val, GL);
        if (mid < r) modify(l, r, val, GR);
        pushup(k);
    }
    T rmq(int l, int r, int k = 1) { // 区间询问最小值
        if (l <= t[k].l && t[k].r <= r) {
            return t[k].rmq;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;
        T ans = numeric_limits<T>::lowest(); // RMQ -> 为 max 时需要修改为 ::lowest()
        if (l <= mid) ans = max(ans, rmq(l, r, GL)); // RMQ -> min/max
        if (mid < r) ans = max(ans, rmq(l, r, GR)); // RMQ -> min/max
        return ans;
    }
    T ask(int l, int r, int k = 1) { // 区间询问
        if (l <= t[k].l && t[k].r <= r) {
            return t[k].w;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;
        T ans = numeric_limits<T>::lowest();
        if (l <= mid) ans = max(ans, ask(l, r, GL));
        if (mid < r) ans = max(ans, ask(l, r, GR));
        return ans;
    }
    void debug(int k = 1) {
        cout << "[" << t[k].l << ", " << t[k].r << "]: ";
        cout << "w = " << t[k].w << ", ";
        cout << "Min = " << t[k].rmq << ", ";
        cout << "lazy = " << t[k].lazy << ", ";
        cout << endl;
        if (t[k].l == t[k].r) return;
        debug(GL), debug(GR);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> seg(n);
    vector<int> a;
    for(auto &[x, y] : seg) {
        cin >> x >> y;
        a.push_back(y);
    }
    vector<array<int, 3>> qry(q);
    for(int i = 0; i < q; i++) {
        cin >> qry[i][0] >> qry[i][1];
        qry[i][2] = i;
        a.push_back(qry[i][1]);
    }
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    auto get = [&](int x) {
        return int(lower_bound(all(a), x) - a.begin()) + 1;
    };

    sort(all(seg), [](auto &a, auto &b) {
        if(a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    });
    sort(all(qry), [](auto &a, auto &b) {
        if(a[0] != b[0]) return a[0] > b[0];
        return a[1] > b[1];
    });

    Segt<int> st((int)a.size());
    vector<int> ans(q);
    int p = 0;
    for(auto &qq : qry) {
        int L = qq[0], R = qq[1], id = qq[2];
        while(p < n and seg[p].first >= L) {
            int pos = get(seg[p].second);
            int len = seg[p].second - seg[p].first + 1;
            st.modify(pos, pos, len);
            p++;
        }
        int rr = upper_bound(all(a), R) - a.begin();
        if(rr == 0) ans[id] = 0;
        else {
            ans[id] = st.ask(1, rr);
        }
    }
    for(int i = 0; i < q; i++) cout << ans[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
