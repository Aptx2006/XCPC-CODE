#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 3e5+7, M = 1e9+7;
int n,m,ans;
int mincost[N],costbuthave[N];
int a[N],dep[N];
vector<int>G[N],g[N];
int fa[N][30];
void change(int x,int p){
    dep[x]=dep[p]+1;
    fa[x][0]=p;
    for(int i=1;i<=20;i++){
        fa[x][i]=fa[fa[x][i-1]][i-1];
    }
    for(int i:G[x]){
        if(i!=p){
            change(i,x);
            g[x].push_back(i);
        }
    }
}
vector<int>nextcost[N];
int dfs(int x,int st){
    if(g[x].size()==0){
        mincost[x]=a[x];return a[x];
    }
    
    for(int i:g[x]){
        dfs(i,st+1);
    }
    sort(g[x].rbegin(),g[x].rend(),[](int b,int c){
        return mincost[b]<mincost[c];
    });
    mincost[x]=min(a[x],mincost[nextcost[x][0]]+mincost[nextcost[x][1]]);
    return mincost[x];
}
int dfs1(int x,int p,int cur){
    if(x==1){
        for(int i:g[x]){
            dfs1(i,x,i);
        }
        return 0;
    }else{
        int t;
        if(nextcost[p][0]==x)t=nextcost[p][1];
        else t=nextcost[p][0];
        costbuthave[x]=t+costbuthave[p];
        for(int i:g[x]){
            dfs1(i,x,cur);
        }
        return 1;
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    for(int i=20;i>=0;i--){
        if(dep[fa[x][i]]>=dep[y]){
            x=fa[x][i];
        }
    }
    if(x==y)return x;
    for(int i=20;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            x=fa[x][i],y=fa[y][i];
        }
    }
    return fa[x][0];
}
void solve(){
    cin >> n>>m;
    for(int i=1;i<=n;i++){
        costbuthave[i]=2e9;
        mincost[i]=2e9;
        for(int j=0;j<=20;j++){
            fa[i][j]=0;
        }
        G[i].clear();
        g[i].clear();
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    change(1,0);
    dfs(1,0);
    dfs1(1,0,0);
    while(m--){
        int x,y;cin>>x>>y;
        if(lca(x,y)!=y){
            cout<<"-1\n";
        }else{
            cout<<costbuthave[x]-costbuthave[y]<<"\n";
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--)
    solve();
    return 0;
}
