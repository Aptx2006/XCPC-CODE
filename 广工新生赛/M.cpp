#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int N = 2e5 + 5 , M = 2;
vector<int> G[N];
vector<int> ans(N,0);
vector d(N, vector<int>(M + 1, 0));
int n;

void dfs1(int node, int fa) {
    d[node][0]=1;
    for(int v: G[node]){
        if(v == fa) continue;
        dfs1(v, node); 
        for(int i = 0; i < M; i++){
            d[node][ i+1 ] += d[v][i];
        }
    }
}

void dfs2(int node, int fa){
    ans[node] = d[node][M];
    for(int v: G[node]){
        if(v == fa) continue;
        for(int i = M - 1; i >= 1; i--){
            d[v][ i+1 ] += d[node][i] - d[v][ i-1 ];
        }
        d[v][1] += d[node][0];
        dfs2(v, node);
    }
}
void solve(){
    ans.clear();
    for(int i = 0; i <= n; i++) {
        G[i].clear();
        for(int j = 0; j <= M; j++) 
            d[i][j] = 0;
    }
    cin >> n;
    for(int i = 1; i <= n-1; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, 1);
    dfs2(1, 0);
    int mx = 0;
    for(int i = 1; i <= n; i++) {
        //cout << ans[i] << ' ';
        mx = max(mx, ans[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(ans[i] == mx) {
            cout << i << ' ' << mx << '\n';
            return;
        }
    }
}
signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
    return 0;
}