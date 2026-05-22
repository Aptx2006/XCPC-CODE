#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x)(x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " <<(x) << endl;

int T, n, m, k, ans, cnt;

struct DSU {
    struct upd {
        int x, y, sx, py;
    };

    struct qry {
        int h, bad;
    };

    vector<int> fa, sz, xr;
    vector<upd> his;
    int bad = 0;

    DSU(int n) {
        fa.resize(n + 1);
        sz.assign(n + 1, 1);
        xr.assign(n + 1, 0);
        his.clear();
        bad = 0;
        for(int i = 1; i <= n; i++) fa[i] = i;
    }

    pair<int, int> find(int x) {
        int p = 0;
        while(fa[x] != x) {
            p ^= xr[x];
            x = fa[x];
        }
        return {x, p};
    }

    void add(int u, int v) {
        auto [x, px] = find(u);
        auto [y, py] = find(v);

        if(x == y) {
            if((px ^ py) != 1) ++bad;
            return;
        }

        if(sz[x] < sz[y]) {
            swap(x, y);
            swap(px, py);
        }

        his.push_back({y, x, sz[x], xr[y]});
        fa[y] = x;
        xr[y] = px ^ py ^ 1;
        sz[x] += sz[y];
    }

    qry save() const {
        return {(int)his.size(), bad};
    }

    void back(qry s) {
        while((int)his.size() > s.h) {
            auto c = his.back();
            his.pop_back();
            fa[c.x] = c.x;
            xr[c.x] = c.py;
            sz[c.y] = c.sx;
        }
        bad = s.bad;
    }

    bool ok() const {
        return bad == 0;
    }
};

void solve() {
    cin >> n >> m;

    vector<pair<int, int>> e(m);
    for(auto &x : e) cin >> x.first >> x.second;

    vector<int> res;
    int B = max(1,(int)sqrt(m) + 1);

    for(int L = 0; L < m; L += B) {
        int R = min(m, L + B);
        DSU uf(n);

        for(int i = 0; i < m; i++) {
            if(i < L or i >= R) uf.add(e[i].first, e[i].second);
        }

        if(uf.bad) continue;

        for(int del = L; del < R; del++) {
            auto s = uf.save();

            for(int i = L; i < R; i++) {
                if(i == del) continue;
                uf.add(e[i].first, e[i].second);
                if(uf.bad) break;
            }

            if(!uf.bad) res.push_back(del + 1);
            uf.back(s);
        }
    }

    cout << res.size() << '\n';
    for(auto &id : res) cout << id << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(T = 1; T--; solve());
    return 0;
}
