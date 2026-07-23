#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+7,mod=1e9+7;
vector<int>G[N];
int n,m,ans=1;
int vis[N],del[N];
int cnt=0;
void dfs(int x,int step){
    vis[x]=step;
    for(int nx:G[x]){
        if(!del[nx]&&!vis[nx]){
            dfs(nx,step+1);
        }
    } 
}
void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    while(cnt<n-1){
        for(int i=1;i<=n;i++)vis[i]=0;
        for(int i=1;i<=n;i++){
            if(!del[i]){
                dfs(i,1);break;
            }
        }
        int point1=0,maxstep=0;
        for(int i=1;i<=n;i++){
            if(maxstep<vis[i])maxstep=vis[i],point1=i;
        }
        for(int i=1;i<=n;i++)vis[i]=0;
        dfs(point1,1);maxstep=0;
        for(int i=1;i<=n;i++){
            maxstep=max(maxstep,vis[i]);
        }
        vector<int>endd;
        for(int i=1;i<=n;i++){
            if(vis[i]==maxstep){endd.push_back(i);}
        }
        for(int i=0;i<endd.size()-1;i++)del[endd[i]]=1,cnt++;
        for(int i=cnt;i>1;i--)ans=ans*i%mod;
    }
    cout<<ans;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int times = 1;//cin >> times;
    while(times--) solve();
    return 0;
}
