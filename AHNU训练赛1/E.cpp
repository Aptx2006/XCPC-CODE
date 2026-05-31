#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

struct edge {
    int u, v, w;
    int id;
    bool operator <(const edge &o) const{
        return w < o.w;
    }
};

struct DSU {
    vector<int> fa;
    DSU(int _n) : fa(_n) { iota(all(fa), 0); }
    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        fa[x] = y;
        return true;
    }
};

void solve() {
    cin >> n >> m >> k;
    vector<edge> G;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G.push_back({u, v, w, i});
    }

    sort(all(G));

    DSU dsu(n + 1);
    vector<edge> mst;
    for(auto& e : G) {
        if(dsu.merge(e.u, e.v)) {
            mst.push_back(e);
        }
    }

    sort(all(mst), [](auto &a, auto &b){ return a.w > b.w; });

    int cnt = 0; 
    for(auto &e : mst) {
        if(cnt < k and e.w > 1) {
            cnt++;
        }
    }

    iota(all(dsu.fa), 0);
    i64 ans = 0;
    vector<int> out;

    for(int i = cnt; i < mst.size(); i++) {
        dsu.merge(mst[i].u, mst[i].v);
        ans += mst[i].w;
        out.push_back(mst[i].id);
    }

    int nid = m;
    vector<pair<int, int>> add;
    for(int i = 1; i < n; i++) {
        if(dsu.merge(i, i + 1)) {
            add.push_back({i, i + 1});
            ans += 1;
            out.push_back(nid++);
        }
    }

    cout << add.size() << "\n";
    for(auto &[x, y] : add) {
        cout << x << " " << y << "\n";
    }
    cout << ans << "\n";
    for(int i = 0; i < out.size(); i++) {
        cout << out[i] + 1 << " \n"[i + 1 == (int)out.size()];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
