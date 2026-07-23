#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;
void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    int f = max(0ll,m-k);
    int ans = -1;
    unordered_map<int,int>mp;
    for(int i=1;i<=n*m;i++){
        int x;
        cin >> x;
        mp[(x-1)/m]++;
        if(mp[(x-1)/m]==f){
            ans = i;
            f = 1e18;
        }
    }
    cout<<max(ans,m)<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int times;cin >> times;
    while(times--) solve();
    return 0;
}
