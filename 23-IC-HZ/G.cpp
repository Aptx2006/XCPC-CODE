#include<bits/stdc++.h>
using namespace std;
#define int long long
using ld = long double;
const int N = 3005,M=1;
int n,m,k,a[N],sx,sy;
int S[N][N],G[N][N],dis[N][N],vis[N][N];
const int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
struct node{
    int x,y,d;
    bool operator <(const node &rhs)const{
        return d > rhs.d;
    }
};
void solve(){
    cin >> n >> m >> k;
    cin>>sx>>sy;
    S[sx][sy] = 1;
    for(int i=2,x,y;i<=k;i++){
        cin >> x >> y;
        S[x][y] = i;
    }
    vector<string>GG(n);
    for(auto &x:GG) cin >> x;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            G[i][j]=(GG[i-1][j-1]=='#'); 
            dis[i][j]=1e9;
        }
    }
    priority_queue<node>pq;
    pq.push({sx,sy,0});
    dis[sx][sy] = 0;
    while(!pq.empty()){
        auto [x,y,d] = pq.top();
        pq.pop();
        if(vis[x][y]) continue;
        vis[x][y] = 1;
        for(int i=0;i<4;i++){
            int nx = x + dx[i], ny = y + dy[i], nd = d+1;
            if(nx<1 or nx>n or ny<1 or ny>m or G[nx][ny]) continue;
            if(S[nx][ny]) nd = max(k-S[nx][ny]+1,nd);
            if(dis[nx][ny]>nd){
                dis[nx][ny] = nd;
                pq.push({nx,ny,nd});
            }
        }
    }
    unsigned long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(dis[i][j]!=1e9)
                ans+=(dis[i][j])*(dis[i][j]);
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; //cin >> T;
    while(T--) solve();
}