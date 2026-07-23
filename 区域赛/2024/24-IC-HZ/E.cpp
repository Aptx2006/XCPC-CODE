#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;
void solve(){
    int n,f;
    cin >> n >> f;
    vector<array<int,3>>peo(n);
    vector<int>an;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>peo[i][0]>>peo[i][1];
        peo[i][2]=i+1;
    }
    sort(peo.begin(),peo.end());
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        int l = peo[i][0],r = peo[i][1],id = peo[i][2];
        if(l<f){
            if(r>f){
                f = r,ans+=r-l;
                an.push_back(id);
                mp[id]++;
            }
        }else{
        ans+=l-f;
        f = r,ans+=r-l;
        an.push_back(id);
        mp[id]++;
        }
    }
    sort(peo.begin(),peo.end(),[](auto x,auto y){
         return x[1]>y[1];
    });
    for(int i=0;i<n;i++){
        int l = peo[i][0],r = peo[i][1],id = peo[i][2];
        if(mp.count(id)) continue;
        an.push_back(id);
        mp[id]++;
        ans+=r-l;
    }
    cout<<ans<<'\n';
    for(int i:an){
        cout<<i<<" ";
    }
    cout<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int times;cin >> times;
    while(times--) solve();
    return 0;
}
