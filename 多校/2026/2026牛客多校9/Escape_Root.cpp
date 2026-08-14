#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, cnt;

struct Tree {
    int n;
    vector<vector<int>> ver, val;
    vector<int> lg, dep;
    Tree(int n) {
        this->n = n;
        ver.resize(n + 1);
        val.resize(n + 1, vector<int>(30));
        lg.resize(n + 1);
        dep.resize(n + 1);
        for(int i = 1; i <= n; i++) {
            lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
        }
    }
    void add(int x, int y) {
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    void dfs(int x, int fa) {
        val[x][0] = fa;
        dep[x] = dep[fa] + 1;
        for(int i = 1; i <= lg[dep[x]]; i++) {
            val[x][i] = val[val[x][i - 1]][i - 1];
        }
        for(auto y : ver[x]) {
            if(y == fa) continue;
            dfs(y, x);
        }
    }
    int lca(int x, int y) {
        if(dep[x] < dep[y]) swap(x, y);
        while (dep[x] > dep[y]) {
            x = val[x][lg[dep[x] - dep[y]] - 1];
        }
        if(x == y) return x;
        for(int k = lg[dep[x]] - 1; k >= 0; k--) {
            if(val[x][k] == val[y][k]) continue;
            x = val[x][k];
            y = val[y][k];
        }
        return val[x][0];
    }
    int clac(int x, int y) {
        return dep[x] + dep[y] - 2 * dep[lca(x, y)];
    }
    void work(int root = 1) {
        dfs(root, 0);
    }
};

int time1;
vector<int> dfn;

void dfs(Tree& tree, int u, int fa) {
    dfn[u] = ++time1;
    for(int v : tree.ver[u]) {
        if(v != fa) {
            dfs(tree, v, u);
        }
    }
}

void solve() {
    cin >> n >> m;
    Tree tree(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        tree.add(u, v);
    }
    tree.work();

    time1 = 0;
    dfn.resize(n + 1);
    dfs(tree, 1, 0);

    vector<array<int,3>> hum(m + 1);
    int sum = 0;
    map<int,int> mp;
    for(int i = 1; i <= m; i++) {
        cin >> hum[i][0] >> hum[i][1];
        hum[i][2] = i;
        int key = tree.dep[hum[i][0]] + hum[i][1];
        if(!mp.count(key)) {
            mp[key] = ++sum;
        }
    }

    vector<vector<int>> pos(sum + 1);
    for(int i = 1; i <= m; i++) {
        int key = tree.dep[hum[i][0]] + hum[i][1];
        pos[mp[key]].push_back(i);
    }

    const int B = max(1, (int)sqrt(m));
    vector<int> ans(m + 1, 0);
    vector<int> nx(n + 2, 0);

    for(int g = 1; g <= sum; g++) {
        vector<int> vec = pos[g];

        if((int)vec.size() <= B) {
            sort(all(vec), [&](int a, int b) {
                return dfn[hum[a][0]] < dfn[hum[b][0]];
            });

            while((int)vec.size() > 1) {
                int sz = (int)vec.size();
                vector<int> fa(sz);
                int mxdp = 0;
                for(int i = 1; i < sz; i++) {
                    fa[i] = tree.lca(hum[vec[i-1]][0], hum[vec[i]][0]);
                    mxdp = max(mxdp, tree.dep[fa[i]]);
                }
                vector<bool> vis(sz);
                for(int i = 1; i < sz; i++) {
                    if(tree.dep[fa[i]] == mxdp) {
                        vis[i-1] = vis[i] = true;
                    }
                }
                vector<int> nxt;
                for(int i = 0; i < sz; i++) {
                    if(!vis[i]) nxt.push_back(vec[i]);
                }
                vec = nxt;
            }
            if(!vec.empty()) ans[vec[0]] = 1;

        }else {
            using arr = array<int,3>;
            priority_queue<arr, vector<arr>, greater<arr>> pq;
            vector<int> vt;
            auto get = [&](int u) {
                if(nx[u] == 0) vt.push_back(u);
                nx[u]++;
            };
            for(auto &p: vec) {
                get(hum[p][0]);
                pq.push({hum[p][1], hum[p][0], p});
            }
            while(!pq.empty()) {
                auto [s, u, idx] = pq.top();
                if(u == 0) break;
                pq.pop();
                if(nx[u] >= 2) continue;
                int par = tree.val[u][0];
                get(par);
                pq.push({s + 1, par, idx});
            }
            if(!pq.empty()) ans[pq.top()[2]] = 1;
            for(auto &u: vt) nx[u] = 0;
        }
    }
    for(int i = 1; i <= m; i++) cout << ans[i];
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
