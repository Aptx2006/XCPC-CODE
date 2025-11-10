#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5, MOD = 998244353;
int n,m,a[N];
vector<int>G[N];
void solve(){
    cin>>n>>m;
    int maxx=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    while(m--){
        int u,v;cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(a[i]==maxx&&G[i].size()>1){
            cout<<maxx;return;
        }
    }
    sort(a+1,a+1+n);
    cout<<a[max(1ll,n-1)];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int times=1;
    while(times--)solve();
    return 0;
} 
