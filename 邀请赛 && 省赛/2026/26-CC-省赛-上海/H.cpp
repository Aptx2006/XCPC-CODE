#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

using P = pair<i64, i64>;

const int N = 3e5 + 5;
const i64 INF = 4e18;

void solve() {
    int n;cin>>n;
    vector<int>t(n),x(n),l(n),r(n);
    for(int i=0;i<n;i++){
        cin>>t[i]>>x[i];
    }
    int nw=1;
    for(int i=0;i<n;i++){
        if(nw+x[i]-1>t[i]){
            cout<<"No\n";return;
        }
        l[i]=nw;
        nw+=x[i];
    }
    nw=t[n-1];
    for(int i=n-1;i>=0;i--){
        nw=min(nw-x[i],t[i]-x[i]);
        r[i]=nw+1;
        if(r[i]<=0){
            cout<<"No\n";return;
        }
    }
    cout<<"Yes\n";
    for(int i=0;i<n;i++){
        cout<<r[i]<<' ';
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
