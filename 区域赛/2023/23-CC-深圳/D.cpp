#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
#define all(A) A.begin(), A.end()
#define dbg(A) cerr << (#A) << ':' << (A) << endl;

int n,m;

void solve(){
    cin >> n>>m;
    vector<vector<int>>G(n+1);
    vector<int>in(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        in[u]++;
        in[v]++;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int>out(n+1);
    auto dfs=[&](auto &&dfs,int x,int fa)->void{
        for(auto nx:G[x]){
            if(nx!=fa){
                dfs(dfs,nx,x);
                out[x]++;
            }
        }
    };
    dfs(dfs,n,0);
    bool f=1;
    int ans=0,ans2=0;
    for(int i=1;i<=n;i++){
        if(out[i]==m){
            ans++;
        }
        if(out[i]==1){
            ans2++;
        }
    }
    cout<<((ans==1 and ans2==n-1)?"Doddle\n":"Tie\n");
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}