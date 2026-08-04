#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
using pii = pair<i64, i64>;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
void solve() {
    int n,m;cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m,0)),sg(n,vector<int>(m,-1)),in(n,vector<int>(m,0));
    vector<vector<vector<pii>>>G(n,vector<vector<pii>>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                int ni=i+dx[k],nj=j+dy[k];
                if(ni<0 or ni>=n or nj<0 or nj>=m)continue;
                if(a[i][j]>a[ni][nj]){
                    in[ni][nj]++;
                    G[i][j].push_back({ni,nj});
                }
            }
        }
    }
    queue<pii>Q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(in[i][j]==0){
                Q.push({i,j});
                sg[i][j]=0;
            }
        }
    }
    auto get_mex=[](vector<int>a){
        set<int>s;
        for(int i:a)s.insert(i);
        for(int i=0;i<=10;i++){
            if(!s.count(i))return i;
        }
    };
    while(!Q.empty()){
        auto [x,y]=Q.front();
        Q.pop();
        for(auto[nx,ny]:G[x][y]){
            in[nx][ny]--;
            if(in[nx][ny]==0){
                Q.push({nx,ny});
                vector<int>num;
                for(int i=0;i<4;i++){
                    int nnx=nx+dx[i],nny=ny+dy[i];
                    if(nnx<0 or nnx>=n or nny<0 or nny>=m)continue;
                    if(a[nx][ny]<a[nnx][nny])num.push_back(sg[nnx][nny]);
                    sg[nx][ny]=get_mex(num);
                }
            }
        }
    }
    int q;cin>>q;
    while(q--){
        int x,y;cin>>x>>y;
        x--;y--;
        cout<<(sg[x][y]>0?"First\n":"Second\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin>>T; T--; solve());
    return 0;
}
