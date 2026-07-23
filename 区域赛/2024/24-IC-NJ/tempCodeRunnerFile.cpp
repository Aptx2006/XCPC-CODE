#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5,M=1e9+7;
int n,m,a[N],ans;
void solve(){
    cin >> n >> m;
    string s;
    cin >> s;
    m = m % n;
    string b = s.substr(0,m);
    s += b;
    int id = s.find("nanjing");
    //cout<<id<<endl;
    while(id!=-1){
        ans++;
        id = s.find("nanjing",id+7);
    }
    int i = n;
    id = s.find("nanjing",i);
    while(id!=-1){
        ans--;
        id = s.find("nanjing",id+7);
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
    return 0;
}