#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 100;
vector<int>G[N];
int n;
void solve(){
    cin >> n;
    for(int i=1;i<n;i++){
        int u,v;cin >> u >> v;
        G[u].push_back(v),G[v].push_back(u);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(G[i].size()>1)cnt++;
    }
    if(cnt == 0 or cnt & 1){
        cout<<"Bob\n";
    }else
        cout<<"Alice\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}
