#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5,M=1e9+7;
int n,m,k,a[N],ans,u,v;
void solve(){
    cin >> n >> m >> k;
    ans=0;
    vector<int>fri(k+5),d(k+5);
    for(int i=0;i<n;i++){
        cin >> u;
        fri[u]++;
    }
    map<pair<int,int>,int>mp;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        if(u>v) swap(u,v);
        if(fri[u] and fri[v]){
            ans++;
        }else if(u==v or fri[u]){
            d[v]++;
        }else if(fri[v]){
            d[u]++;
        }else
            mp[{u,v}]++;
    }
    int cnt = 0;
    for(auto [p,y]:mp){
        auto [u,v] = p;
        cnt = max(cnt,y + d[u] + d[v]);
    }
    sort(d.rbegin(),d.rend());
    cnt = max(cnt,d[1]+d[0]);
    ans += cnt;
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
    return 0;
}
