#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5,M=1e9+7;
int a[N],n,ind[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ind[a[i]]=i;
    }
    int q;cin>>q;
    while(q--){
        int t;cin>>t;
        map<int,int>mp;
        for(int i=1;i<=t;i++){
            int num;cin>>num;
            if(num<=n)
            if(ind[num]==1||mp[ind[num]]<mp[ind[num]-1])mp[ind[num]]++;
        }
        cout<<mp[n]<<"\n";
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1;// cin >> T;
    while(T--) solve();
}