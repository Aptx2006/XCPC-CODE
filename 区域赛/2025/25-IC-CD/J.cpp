#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5,M = 1e9 + 7;
int n,m,a[N],ans,k,b;
int sc[]={-3,-2,-1,0,1,2,3};
void solve(){
    cin>>n>>m>>k>>b;
    ans=0;
    vector<int>a(n),bb(n);
    for(int j=0;j<n;j++){
        for(int t,i=0;i<m;i++){
            cin >> t;
            a[j]+=t;
            if(t>=1) t--;
            else t++;
            bb[j]+=t;
        }
        if(a[j]>=k)ans++;
        else if(bb[j]>=k&&b>0)ans++,b--;
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T=1; cin >> T;
    while(T--) solve();
    return 0;
}
