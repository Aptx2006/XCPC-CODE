#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=200005;
const int P=998244353;
vector<pair<int,int> > G[N],H[N];
string s;
int dp[N],q[N];
int dis[N];
int vis[N],cnt[N];
// map<pair<int,int> > mp;

int qpow(int x,int y){
    int res=1;
    for(;y;y/=2,x*=x,x%=P)if(y&1)res*=x,res%=P;
    return res;
}

int inv(int x){
    return qpow(x,P-2);
}

void dfs(int u){
    if(vis[u])return;
    vis[u]=1;
    for(auto [v,w]:G[u]){
        dfs(v);
        dis[u]=min(dis[u],dis[v]+w);
    }
    for(auto [v,w]:G[u]){
        if(dis[v]+w==dis[u]){
            cnt[u]+=cnt[v];
            cnt[u]%=P;
            // mp[{u,v}]=cnt[v];
            // cout<<"\t"<<u<<" "<<v<<"\n";
        }
    }
}

void sol(int u){
    if(vis[u])return;
    vis[u]=1;
    if(s[u]=='0'){
        for(auto [v,w]:G[u]){
            sol(v);
            dp[u]+=w+dp[v];
            dp[u]%=P;
        }   
        dp[u]*=inv(G[u].size());
        dp[u]%=P;
    }else{
        for(auto [v,w]:G[u]){
            sol(v);
            if(dis[v]+w==dis[u]){
                dp[u]+=(w+dp[v])*cnt[v]%P;
                dp[u]%=P;
                // cout<<"\t"<<u<<" "<<v<<"\n";
            }
        }   
        dp[u]*=inv(cnt[u]);
        dp[u]%=P;
    }
}

void solve() {
    int n,m,t;
    cin>>n>>m>>t;
    cin>>s;
    s=" "+s;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        G[x].push_back({y,z});
        H[y].push_back({x,z});
    }
    memset(dis,0x3f,sizeof dis);
    cnt[t]=1;
    dis[t]=0;vis[t]=1;
    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i);
    }
    memset(vis,0,sizeof vis);
    dp[t]=0;vis[t]=1;
    for(int i=1;i<=n;i++){
        if(!vis[i])sol(i);
    }
    // sol(4);
    // for(int i=1;i<=n;i++)cout<<cnt[i]<<" \n"[i==n];
    for(int i=1;i<=n;i++)cout<<dp[i]<<" \n"[i==n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}