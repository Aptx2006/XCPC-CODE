#include<bits/stdc++.h>
using namespace std;
#define int long long
using ld = long double;
#define dbg(A) cout<<#A<<" : "<<A<<endl;
#define all(A) A.begin(), A.end()
const int N = 2e5+5,M = 1e9+7;
int n,m,a[N],ans;
void solve(){
    int x1,x2,x3;
    cin >> x1 >> x2 >> x3;
    cout<<"100\n";
    for(int i=0;i<50;i++) cout<<x1<<' ';
    for(int i=50;i<95;i++) cout<<x2<<' ';
    for(int i=95;i<99;i++) cout<<x3<<' ';
    cout<<M-7<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; //cin >> T;
    while(T--) solve();
}