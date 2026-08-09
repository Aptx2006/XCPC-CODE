#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

struct ODT {
    using LL = long long;
    struct node {
        int l, i;
        mutable LL v;
        node(int l, int i = -1, LL v = 0) : l(l), i(i), v(v) {}
        bool operator<(const node &o) const { return l < o.l; }
    };
    set<node> s;
    LL sum_; 

    ODT() { s.clear(); sum_ = 0; }

    auto split(int pos) {
        auto it = s.lower_bound(node(pos));
        if(it != s.end() && it->l == pos) return it;
        it--;
        int l = it->l, i = it->i;
        LL v = it->v;
        s.erase(it);
        s.insert(node(l, pos - 1, v));
        return s.insert(node(pos, i, v)).first;
    }

    void assign(int l, int i, LL x) {
        auto itr = split(i + 1), itl = split(l);
        for (auto it = itl; it != itr; it++) {
            sum_ -= 1LL * (it->i - it->l + 1) * it->v; 
        }
        s.erase(itl, itr);
        s.insert(node(l, i, x));
        sum_ += 1LL * (i - l + 1) * x; 
    }

    LL get_val(int pos) {
        auto it = s.upper_bound(node(pos));
        it--;
        return it->v;
    }
};

struct SegTree {
    int sz;
    vector<int> tree, pos;
    SegTree(int n_in) : sz(n_in), tree(4 * n_in + 5, 0), pos(n_in + 5, 0) {}
    
    void upd(int node, int l, int i, int idx, int val) {
        if(l == i) { tree[node] = val; pos[idx] = val; return; }
        int mid = l + (i - l) / 2;
        if(idx <= mid) upd(2 * node, l, mid, idx, val);
        else upd(2 * node + 1, mid + 1, i, idx, val);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
    
    void upd(int idx, int val) { upd(1, 0, sz + 1, idx, val); }

    int qry(int node, int l, int i, int ql, int limit) {
        if(i < ql || tree[node] >= limit) return -1;
        if(l == i) return l;
        int mid = l + (i - l) / 2;
        int res = qry(2 * node, l, mid, ql, limit);
        if(res != -1) return res;
        return qry(2 * node + 1, mid + 1, i, ql, limit);
    }
    
    int getmex(int mew, int pos) {
        return qry(1, 0, sz + 1, mew + 1, pos);
    }
};

void solve() {
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    ODT odt;
    SegTree seg(n + 1);
    
    odt.s.insert(ODT::node(1, n + 2, 0)); 
    i64 ans = 0;

    for(int i = 1; i <= n; i++) {
        int v = a[i];
        if(v <= n + 1) seg.upd(v, i);

        int mn = i + 1, mx = 0;
        
        int l = 1, r = i;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(odt.get_val(mid) <= v) { 
                mn = mid; 
                r = mid - 1; 
            }else { 
                l = mid + 1; 
            }
        }
        
        l = 1, r = i;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(odt.get_val(mid) >= v) { 
                mx = mid; 
                l = mid + 1; 
            }else { 
                r = mid - 1; 
            }
        }

        if(mn <= mx and odt.get_val(mn) == v) {
            int p = mx;
            while(p >= mn) {
                int nmew = seg.getmex(v, p);
                if(nmew == -1) break; 
                int nl = max(mn, seg.pos[nmew] + 1);
                odt.assign(nl, p, nmew);
                p = nl - 1;
            }
        }
        ans += odt.sum_;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
