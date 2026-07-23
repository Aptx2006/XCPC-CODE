#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2005, M = 1e9+7;
int n,m,ans;
int a[N][N],vis[N];
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++){
            cin >> a[i][j];
        }
    vector<int>G[N];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            int x=a[1][i]^a[1][j]^a[i][j];
            if (x==i) G[i].push_back(j);
            if (x==j) G[j].push_back(i);
    }
    vector<int>cnt[N];
    for(int i=1;i<=n;i++)
        cnt[G[i].size()].push_back(i);
    vector<pair<int,int>>res;
    for(int len=1;len<n;len++)
        for(int x:cnt[len])
            for(auto y:G[x]){
                if(!vis[y]){
                    res.push_back({x,y});
                    vis[y]=1;
                }
            }
    for(auto [x,y]:res) cout<<x<<' '<<y<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}
