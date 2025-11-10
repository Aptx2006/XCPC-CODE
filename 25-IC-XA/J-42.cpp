#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=300005;
int a[N];
vector<int> G[N];
int n,m;
int d[N],f[20][N],dp[20][N],dep[N];

bool cmp(int x,int y){
    return d[x]<d[y];
}

void dfs(int u,int fa,int depth){
    dep[u]=depth;
    f[0][u]=fa;
    for(int v:G[u]){
        if(v==fa)continue;
        dfs(v,u,depth+1);
    }
    if(G[u].size()<2){
        d[u]=a[u];
        return ;
    }
    sort(G[u].begin(),G[u].end(),cmp);
    d[u]=min(d[G[u][0]]+d[G[u][1]],a[u]);
    for(int i=0;i<G[u].size();i++){
        if(i)dp[0][G[u][i]]=d[G[u][0]];
        else dp[0][G[u][i]]=d[G[u][1]];
    }
}
void A(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        G[i].clear();
        cin>>a[i];
        d[i]=2e9;
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1,0,0);
    for(int k=1;k<20;k++){
        for(int i=1;i<=n;i++){
            if(dep[i]>=(1<<k))f[k][i]=f[k-1][f[k-1][i]],dp[k][i]=dp[k-1][i]+dp[k-1][f[k-1][i]];
        }
    }
    while(m--){
        int x,y;
        cin>>x>>y;
        ll cost=0;
        int fl=0;
        for(int k=19;k>=0;k--){
            if(dep[x]>=dep[y]+(1<<k))cost+=dp[k][x],x=f[k][x];
        }
        if(x==y){
            cout<<cost<<"\n";
        }else cout<<"-1\n";
    }
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        A();
    }
    return 0;
}