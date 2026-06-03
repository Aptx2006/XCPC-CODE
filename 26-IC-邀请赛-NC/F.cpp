#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x)(x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " <<(x) << endl;

int T, n, m, k, ans, cnt;

struct Edge { 
    int to, id; 
};

vector<vector<Edge>> g;
vector<int> d, jp, c, hd, path;
vector<bool> vis;
int ecnt;

void dfs(int u) {
    while(hd[u] <(int)g[u].size()) {
        auto e = g[u][hd[u]++];
        if(vis[e.id]) continue;
        vis[e.id] = true;
        ecnt++;
        
        int v = e.to;
        int nxt = jp[v] ? jp[v] : v;
        dfs(nxt);
        if(jp[v]) path.push_back(v);
    }
    path.push_back(u);
}

void solve() {
    cin >> n >> m >> k;
    
    g.assign(n + 1, vector<Edge>());
    d.assign(n + 1, 0);
    jp.assign(n + 1, 0);
    c.assign(n + 1, 0);
    hd.assign(n + 1, 0);
    vis.assign(m + 1, false);
    path.clear();
    ecnt = 0;
    
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
        d[u]++; d[v]++;
    }
    
    for(int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        jp[u] = v;
        jp[v] = u;
    }
    
    for(int i = 1; i <= n; i++) {
        if(jp[i]) {
            int x = i, y = jp[i];
            if(x < y) {
                int diff = d[x] - d[y];
                if(diff == 2) c[x] = 2;
                else if(diff == -2) c[y] = 2;
                else if(diff == 1) c[x] = 1;
                else if(diff == -1) c[y] = 1;
                else if(diff == 0) {} 
                else { cout << "-1\n"; return; }
            }
        } else {
            if(d[i] & 1) c[i] = 1;
        }
    }
    
    int sum_c = 0;
    for(int i = 1; i <= n; i++) sum_c += c[i];
    if(sum_c > 2) { cout << "-1\n"; return; }
    
    int S = -1;
    if(sum_c == 2) {
        vector<int> odds;
        for(int i = 1; i <= n; i++) {
            if(c[i] == 2) S = i;
            else if(c[i] == 1) odds.push_back(i);
        }
        if(odds.size() == 2) S = odds[0];
    } else if(sum_c == 0) {
        for(int i = 1; i <= n; i++) {
            if(d[i] > 0 and jp[i] == 0) { S = i; break; }
        }
        if(S == -1) {
            for(int i = 1; i <= n; i++) {
                if(d[i] > 0 and jp[i] != 0) { S = i; break; }
            }
        }
    }
    
    if(S == -1) { cout << "-1\n"; return; }
    
    dfs(S);
    
    if(ecnt < m) { cout << "-1\n"; return; }
    
    reverse(all(path));
    
    if(path.size() >= 2 and jp[path[path.size() - 2]] == path.back()) {
        path.pop_back();
    }
    
    cout << path.size() << "\n";
    for(int i = 0; i < (int)path.size(); i++) {
        cout << path[i] << " \n"[i + 1 == path.size()];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}