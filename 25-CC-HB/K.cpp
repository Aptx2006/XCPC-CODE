#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5,M=1e9+7;
int n,m,a[N];
void solve(){
    cin >> n;
    vector<int>ans{0,n,n+1};
    for(int i=3;i<=n;i++) ans.push_back(ans.back()+n+1);
    cout<<n<<'\n';
    for(int i=1;i<=n;i++) cout<<i<<" \n"[i==n];
    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; //cin >> T;
    while(T--) solve();
}