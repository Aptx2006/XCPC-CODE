#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define endl '\n'
int n, m, s, t, q;
const int N = 100;
vector<pair<int, int>> G[N];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
vector<int> dist(N, 1e9);
vector<bool> vis(N, false);
bool is_power_of_2(int n){ // 判断一个整数是否是 2 的幂
    return n > 0 && n == (n & -n);
}
void dijkstra(int sta){
    dist[sta] = 0;
    pq.push({0, sta});
    while(!pq.empty()){
        auto [dis, u] = pq.top();
        pq.pop();
        if(vis[u])
            continue;
        vis[u] = true;
        for(auto [v, w] : G[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
void solve(){
    cin >> n >> m >> s >> t >> q;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dijkstra(s);
    int cnt = log2(dist[t]);
    if(!is_power_of_2(dist[t]))
        cnt += 1;
    cout << dist[t] << endl;
    if(q >= cnt)
        cout << "YES" << endl;
    else
        cout << "NO" << endl << cnt << endl;
}
signed main(){
    // int _; cin >> _;
    // while(_--)
        solve();

    return 0;
}
