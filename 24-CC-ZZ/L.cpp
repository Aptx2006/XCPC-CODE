#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5,M = 1e9+7;
int n,m,a[N];
void solve(){
    int l,r;
    cin >> l >> r;
    int ans = 0;
    for(int i=63;i>=0;i--){
          //  cout<<((1ll<<i)&l)<<" "<<((1ll<<i)&r)<<endl;
        if(((1ll<<i)&l) != ((1ll<<i)&r)){
            ans = l;
        }
        else{
            l = l & (~(1ll<<i));
            r = r & (~(1ll<<i));
        }
        if(ans!=0)break;
    }
    cout<<ans<<'\n';
    return;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int times; cin >> times;
    while(times--) solve();
    return 0;
}
