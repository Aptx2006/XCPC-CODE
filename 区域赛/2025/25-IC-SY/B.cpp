#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(A) A.begin(),A.end()
using ld = long double;
const int N = 2e5+5,M = 1e9+7;
int n,m,a,b;
void solve(){
    cin >> n >> m >> a >> b;
    vector<int>buc(n*m+1,0);
    for(int i=0;i<n;i++){
        for(int t,j=0;j<m;j++){
            cin >> t;
            buc[t]++;
        }
    }
    int ans1 = (n*m-buc[0])*a ,ans2 = 0;
    vector<int>id(n*m+1);
    iota(all(id),0);
    sort(all(id),[&](auto o1,auto o2){
        return buc[o1] > buc[o2];
    });
    int cb = 0;
    for(int i=0;i<=n*m;i++){
        if(id[i]==0) continue;
        if(buc[id[i]]*cb+buc[0]*b<buc[id[i]]*a){
            ans2+=buc[id[i]]*cb+buc[0]*b;
            cb+=b;
        }else{
            ans2+=buc[id[i]]*a;
        }
    }
    cout<<min(ans1,ans2)<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}
