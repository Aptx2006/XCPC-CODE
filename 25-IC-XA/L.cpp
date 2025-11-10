#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5, M = 1e9+7;
int n,m,ans;
void solve(){
    cin >> n;
    vector<int>a(n),pre(n+1,0);
    for(auto &x:a) cin >> x;
    sort(a.begin(),a.end());
    for(int i=1;i<=n;i++) pre[i] = pre[i-1] + a[i-1];
    int mx = 0,mxid = 0;
    vector<int>res(n+1,0);
    if(pre[n-1]-pre[0]>a[n-1]){
        res[n] = pre[n];
    }
    int l = 0,r = n;// pre[r-1] - pre[l-1]
    for(int len = n; len >= 1;len--){
        l++;
        while(l>1 and pre[r-1]-pre[l-1]<=a[r-1]){
            l--,r--;
        }
        if(pre[r-1]-pre[l-1]>a[r-1]) res[len] = pre[r] - pre[l-1];
    }
    for(int i=1;i<=n;i++)cout<<res[i]<<' ';
    cout<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
    return 0;
}
