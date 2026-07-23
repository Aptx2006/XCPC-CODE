#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 220,M = 1e9+7;
const double eps = 1e-7;
#define dbg(A) cout<<#A<<':'<<A<<' ';
int n,m,a[N];
int G[N][N];
int vis[N][N],dx[] = {-1,0,0,1},dy[]={-1,-1,1,1};
void bfs(){
    queue<pair<int,int>>Q;
    Q.push({1,1});
    vis[1][1]=1;
    while(!Q.empty()){
        auto[x,y]=Q.front();
        Q.pop();
        //dbg(x) dbg(y)
        if(G[x][y]==0 and (!x or !y))continue;
        for(int i=0;i<4;i++){
            if(y%2==0&&i==3)continue;
            if(y%2==1&&i==0)continue;
            //dbg(x+dx[i]) dbg(y+dy[i]) cout<<endl;
            if(!vis[x+dx[i]][y+dy[i]] and G[x+dx[i]][y+dy[i]]){
                vis[x+dx[i]][y+dy[i]]=vis[x][y]+1;
                Q.push({x+dx[i],y+dy[i]});
            }
        }
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*i-1;j++){
            cin>>G[i][j];
            if(i&1){
                G[i][j] = (G[i][j]==(5-((j-1)%4+1)));
            }else
                G[i][j] = (G[i][j]==(j-1)%4+1);
            //cout<<G[i][j]<<' ';
        }
    }
    int x,y;cin>>x>>y;
    bfs();
    cout<<vis[x][y]-1<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    //int times;cin >> times;while(times-)
    solve();
    return 0;
}
