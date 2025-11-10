#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5,M = 1e9+7;
int n,m,ans;
void solve(){
    int n;
    cin >> n;
    vector<int>a(n),res;
    for(auto &x:a) cin >> x;
    int mx = *max_element(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(a[i]==mx) res.push_back(i+1);
    }
    for(auto x:res) cout<<x<<' ';cout<<'\n';
} 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
    return 0;
}
