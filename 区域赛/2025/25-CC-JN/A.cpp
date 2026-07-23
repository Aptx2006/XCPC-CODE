#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N = 2e5+5,M=1e9+7;
int n,m;
int qpow(int base,int mi,int res = 1){
    while(mi){
        if(mi&1) res *= base;
        base *= base;
        mi >>= 1;
    }return res;
}
void solve(){
    cin >> n >> m;
    for(int i=994996658310742016;;i++){
        int ans = qpow(n,i);
        if(ans==m){
            cout<<i<<endl;return;
        }
    }cout<<"no\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}