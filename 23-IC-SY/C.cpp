#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 1e5+5;
int n,m,a[N],ans;
void solve(){
    cin >> n >> m;
    if(n==0 && m==0) cout<<4;
    else if(n==0 && m==1) cout<<4;
    else if(n==0 && m==2) cout<<6;
    else if(n==1 && m==0) cout<<3;
    else if(n==1 && m==1) cout<<3;
    else if(n==1 && m==2) cout<<4;
    else cout<<2;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int times = 1;//cin >> times;
    while(times--) solve();
    return 0;
}
