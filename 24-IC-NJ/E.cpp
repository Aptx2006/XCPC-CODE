#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5,M=1e9+7;
int n,m,a[N],ans;
void solve(){
    cin >> n >> m;
    string s,nj = "nanjing";
    cin >> s;
    m = min(7ll,m),ans = 0;
    for(int i=0;i<=m;i++){
        int tmp = 0,id = s.find(nj);
        while(id!=-1){
            tmp ++;
            id = s.find(nj,id+1);
        }
        ans = max(ans,tmp);        
        string b = s.substr(0,1);
        s += b;
        string c = s.substr(1,n+1);
        s = c;
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
