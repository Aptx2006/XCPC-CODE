#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20, MOD = 998244353;
int n,m,a[N];
void solve(){
    cin >> n;
    string str = string(n+1,' ');
    vector<string>G(8,str);
    cin >> G[1] >> G[7];
    int ct1 = count(G[1].begin(),G[1].end(),'#');
    int ct2 = count(G[7].begin(),G[7].end(),'#');
    if(ct1==ct2 and ct1==n){
        cout<<"Yes\n";
        for(int i=0;i<7;i++) cout<<G[1]<<'\n';
        return;
    }else if(ct1==n or ct2==n){
        cout<<"No\n";return;
    }
    cout<<"Yes\n";
    for (int i = 2; i <= 6; ++i) {
            G[i] = G[1];
    }
    for(int i=0;i<n;i++){
        if(G[1][i]=='#')G[2][i]='.';
        else G[2][i]='#';
        if(G[7][i]=='#')G[6][i]='.';
        else G[6][i]='#';
    }
    int x = 0, y = 0;
    while (G[2][x] != '.' or (!x||G[2][x - 1] != '#') and G[2][x+1] =='.') {
        ++x;
    }
    while (G[6][y] != '.' or (!y||G[6][y - 1] != '#') and G[6][y+1] =='.') {
        ++y;
    }   
    for (int i = 0; i <= n - 1; ++i) {
            G[3][i] = '.';
    }
    G[4] = G[5] = G[3];
    G[3][x] = G[5][y] = '#';    
    if (abs(x - y) <= 1) {
        G[4] = G[5];
    } else {
        int mn = min(x, y),mx = max(x, y);
        for (int j = mn + 1; j <= mx - 1; ++j) {
            G[4][j] = '#';
        }
    }
    for(int i=1;i<8;i++) cout<<G[i]<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int times;cin >> times;
    while(times--)solve();
    return 0;
} 
