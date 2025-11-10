#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    for(int i=1;i<=n;i++){
        if(i!=(n+1)/2) cout<<s[i-1];
    }cout<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
