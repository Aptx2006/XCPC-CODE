#include<bits/stdc++.h>
using namespace std;
using i64=long long;
#define int long long
using point=pair<int,int>;
struct nod{
    int nx,a,b;
    bool operator <(const nod&y)const{
        return a*b>y.a*y.b||(a*b==y.a*y.b &&a>y.a);
    }
};
void solve(){
    int n,m;cin>>n>>m;
    vector<vector<nod>>G(n+1);
    for(int i=1;i<=m;i++){
        int u,v,a,b;cin>>u>>v>>a>>b;
        G[u].push_back({v,a,b});
    }
    vector<vector<int>>dp(n+1,vector<int>(n*201,1e18));//dp[i][j]此时在点i，a的值为j时，b的最小值
    dp[1][0]=0;
    priority_queue<nod>Q;
    Q.push({1,0,0});
    vector<bool>ok(n+1,0);
    while(!Q.empty()){
        auto [x,a,b]=Q.top();
        Q.pop();
        if(ok[x])continue;
        ok[x]=1;
        for(auto[nx,nxa,nxb]:G[x]){
            for(int i=0;i<=n*200;i++){
                if(dp[x][i]!=1e18){
                    dp[nx][i+nxa]=min(dp[nx][i+nxa],dp[x][i]+nxb);
                    Q.push({nx,i+nxa,dp[nx][i+nxa]});
                }
            }
        }
    }
    int ans=1e18;
    for(int i=1;i<=200*n;i++){
        if(dp[n][i]!=1e18){
            ans=min(ans,i*dp[n][i]);
        }
    }
    for(int i=1;i<=200*n;i++){
        if(i*dp[n][i]==ans){
            cout<<i<<' '<<dp[n][i]<<'\n';return;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
