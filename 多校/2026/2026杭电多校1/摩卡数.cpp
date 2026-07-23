#include<bits/stdc++.h>
using namespace std;
using i64=long long;
void solve(){
    int k;
    cin>>k;
    i64 x=1;
    while(x*(x+1)/2<k){
        x++;
    }
    i64 y=k-(x-1)*x/2;
    cout<<x+y<<' '<<2<<'\n';
    for(int i=1;i<=x;i++)cout<<'a';
    for(int i=1;i<=y;i++)cout<<'b';
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
