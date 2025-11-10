#include<bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cout<<#x<<'='<<x<<endl;
const int N = 5e5+5,MOD = 1e9 + 7;
int n,m,ans;
int tree[N];
int ask(int pos,int res = 0){
    for(;pos;pos-=(pos&-pos)) res+=tree[pos];
    return res; 
}void add(int pos,int v){
    for(;pos<=n;pos+=(pos&-pos)) tree[pos] += v;
}void solve(){
    cin >> n >> m;
    vector<int>a(n+1);ans = 0;
    for(int i=1;i<=n;i++) cin >> a[i];
    
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int times = 1;cin >> times;
    while(times--) solve();
    return 0;
}
