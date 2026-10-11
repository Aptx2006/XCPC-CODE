#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

using P = pair<i64, i64>;

const int N = 1e5 + 5;
const i64 INF = 4e18;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
struct nod{
    int x,y;
};
unordered_set<int> buc;

void solve() {
    int n,m,q;cin>>n>>m>>q;
    vector a(n,vector<int>(m)),in(n,vector<int>(m));
    vector sg=a;
    //vector s(n,vector<set<int>>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    auto mex=[](){
        int ans=0;
        while(buc.count(ans))ans++;
        return ans;
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                int nx=i+dx[k],ny=j+dy[k];
                if(nx<0 or ny<0 or nx>=n or ny>=m)continue;
                if(a[i][j]>a[nx][ny]){
                    in[nx][ny]++;
                }
            }
        }
    }
    queue<nod>Q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(in[i][j]==0){
                Q.push({i,j});
                sg[i][j]=0;
            }
        }
    }
    while(!Q.empty()){
        auto [x,y]=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0 or ny<0 or nx>=n or ny>=m or a[nx][ny]<a[x][y])continue;
            buc.insert(sg[nx][ny]);
        }
        sg[x][y]=mex();
        buc.clear();
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0 or ny<0 or nx>=n or ny>=m or a[nx][ny]>a[x][y])continue;
            in[nx][ny]--;
            if(in[nx][ny]==0)Q.push({nx,ny});
        }
    }
    while(q--){
        int x,y;cin>>x>>y;
        x--;y--;
        cout<<(sg[x][y]?1:0)<<'\n';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
 