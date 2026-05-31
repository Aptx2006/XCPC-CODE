#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define all(A) A.begin(),A.end()
#define point pair<int,int>
#define x first
#define y second
const int mod=1e9+7,N=2e6+8;
int n,m,k,a[N];
vector<int>G[N];
void solve(){
    cin>>n;
    string s;
    cin>>s;
    s='0'+s;
    for(int i=1;i<=n;i++)G[i].clear();
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<i64>nums(n+1,0),numc(n+1,0);
    for(int i=1;i<=n;i++){
        if(s[i]=='S'){
            for(int nx:G[i]){
                if(s[nx]=='C')nums[nx]++;
            }
        }
        if(s[i]=='C'){
            for(int nx:G[i]){
                if(s[nx]=='P')numc[nx]++;
            }
        }
    }
    i64 ans=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='C'){
            i64 sc=0,pc=0;
            for(int nx:G[i]){
                sc+=nums[nx];
                if(numc[nx])
                    pc+=numc[nx]-1;
            }
            if(sc>0&&pc>0)ans+=sc*pc;
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;
    while(t--)
    solve();
    return 0;
}