#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define all(A) A.begin(), A.end()

const int N = 3e5 + 5, INF = 1e9 + 10;
int n, m, q, ans, pos, last, root;
vector<int> G[N], a;

void dfs(int u, int fa) {
    if (u != root and a.size() < n - 3)   a.push_back(u);
    for(auto &v: G[u]) {
        if (v != fa) dfs(v, u);
    }
}

void build(int u) {
    if(pos <= m) {
        int k = a[pos] - a[pos - 1];
        for(int i = 0; i < k + 1; i++) {
            G[u].push_back(++last);
        }
        pos++;
        for(auto &v: G[u]) build(v);
    }else if (last == n - 1) {
        G[u].push_back(n);
        last++;
    }
}

void print(int u) {
    for(auto &v: G[u]) {
        cout << u << ' ' << v << '\n';
        print(v);
    }
}

void nailong() {
    cin >> n;
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(G[i].size() == 1){
            root = i;
        }
    }
    dfs(root, 0);
    cout << a.size() << '\n';
    for(auto &x: a) cout << x << ' ';
}

void bblong() {
    cin >> n >> m;
    a.resize(m + 1);
    a[0] = 2;
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    G[1].push_back(2);
    pos = 1;
    last = 2;
    build(2);
    print(1);
}

void solve() {
    cin >> q;
    if(q == 1) {
        nailong();
    }else {
        bblong();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
