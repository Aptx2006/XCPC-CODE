#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5, M = 1e9+7;
int n,m,ans,a[N];
void solve(){
    cin >> n;
    vector<int>a(n);
    vector<int>b,c;
    for(auto &x:a) cin >> x;
    sort(a.begin(),a.end());
    int mx = 0,mn = 0;
    int tmp = 0;
    for(auto x:a){
        if(x<tmp) mx++;
        else mx--;
    }
    sort(a.rbegin(),a.rend());
    tmp = 0;
    for(auto x:a){
        if(x<tmp) mn++;
        else mn--;
    }
    cout<<mx<<' '<<mn<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;cin >> T;
    while(T--) solve();
    return 0;
}
