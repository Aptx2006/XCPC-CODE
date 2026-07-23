#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(A) A.begin(),A.end()
using ld = long double;
const int N = 2e5+5,M = 1e9+7;
int n,s;
struct qw{
    int px,py,qx,qy;
};
void solve(){
    cin >> n >> s;
    vector<qw>a(n);
    int dx = 0,dy = 0;
    for(auto &[px,py,qx,qy]:a) {
        cin >> px >> py >> qx >> qy;
        dx += px - qx;
        dy += py - qy;
    }
    for(int i=0;i<n;i++){
        auto [px,py,qx,qy] = a[i];
        if(2*(a[s-1].px - qx) == dx and 2*(a[s-1].py - qy) == dy){
            cout<<i+1<<'\n';return;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; //cin >> T;
    while(T--) solve();
}
