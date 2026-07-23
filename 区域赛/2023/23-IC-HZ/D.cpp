#include<bits/stdc++.h>
using namespace std;
#define int long long
using ld = long double;
const int N = 2e5+5,M=1e9+7;
int n,m,a[N];
void solve(){
    cin >> n;
    vector<int>ans;
    ans.push_back((n&1)?3-2*n:5-2*n);
    for(int i=0;i<n-1;i++) {
        ans.push_back(-2);
        ans.push_back(1);
    }
    ans.push_back((n&1)?-1:1);
    for(auto x:ans) cout<<x<<" ";cout<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}