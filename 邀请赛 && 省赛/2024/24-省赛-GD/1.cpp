#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define dbg(A) cout << (#A) << ':' << A << endl;

int n, m;
struct nod{
    i64 x,len;
};
void solve() {
    cin >> n;
    vector<i64>a(n+1),sum(n+1);
    vector l=a,r=a,fa=a;
    vector<vector<int>>G(n+1),P(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i++){
        int u;cin>>u;
        G[u].push_back(i);
    }
    int tot=1;

    auto dfs=[&](auto &&dfs,int x)->void{
        l[x]=tot++;
        sum[x]+=a[x];
        for(auto nx:G[x]){
            dfs(dfs,nx);
            sum[x]+=sum[nx];
        }
        r[x]=tot-1;
    };
    
    dfs(dfs,1);
    i64 ans=0;
    for(int i=1;i<=n;i++){
        ans+=a[i]*l[i];
    }
    auto f=[&](auto &&f,int x)->void{
        //cout<<x<<' ';
        vector<nod>t;
        i64 tm=1e9;
        for(auto nx:G[x]){
            f(f,nx);
            t.push_back({nx,r[nx]-l[nx]+1});
            tm=min(tm,l[nx]);
        }
        sort(t.begin(),t.end(),[&](nod a1,nod a2){
            return sum[a1.x]*(a2.len+1) < sum[a2.x]*(a1.len+1);
        });
        
        for(auto [nx,len]:t){
            ans+=sum[nx]*(tm-l[nx]);
            tm+=len;
            P[x].push_back(nx);
        }
    };
    
    f(f,1);
    cout<<ans<<'\n';
    auto d=[&](auto &&d,int x)->void{
        cout<<x<<' ';
        for(auto nx:P[x]){
            d(d,nx);
        }
    };
    d(d,1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}