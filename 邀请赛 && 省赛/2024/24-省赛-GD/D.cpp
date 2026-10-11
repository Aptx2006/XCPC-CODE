#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define dbg(A) cout << (#A) << ':' << A << endl;
#define all(A) (A).begin(), (A).end()

int n, m;
const int N = 2e5 + 10;
i64 sz[N], sum[N], w[N], dp[N];
i64 l, r, ans;
#define int long long
struct nod{
    int a,b;
};
void solve() {
    cin>>n>>m;
    vector<vector<nod>>P(n+1);
    vector<vector<int>>G(n+1);
    vector<int>a(n+1),in(n+1);
    for(int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        G[b].push_back(a);
        G[c].push_back(a);
        P[a].push_back({b,c});
        in[a]+=2;
    }
    queue<int>Q;
    for(int i=1;i<=n;i++){
        if(in[i]==0)Q.push(i);
    }
    for(int i=1;i<=n;i++)a[i]=1;
    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        for(auto [q,w]:P[x]){
            a[x]=max(a[x],a[q]+a[w]);
        }
        //cout<<x<<":"<<a[x]<<'\n';
        for(int nx:G[x]){
            in[nx]--;
            if(in[nx]==0){
                Q.push(nx);
            }
        }
    }
    i64 ans=0;
    for(int i=1;i<=n;i++){
        ans+=a[i];
        if(in[i]!=0 or ans>1e9){
            cout<<"-1\n";return;
        }
    }
    cout<<ans<<'\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}