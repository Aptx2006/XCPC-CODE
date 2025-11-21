#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5,M=1e9+7;
int n,m,a[N];
vector<int>G[N];
void solve(){
    cin >> n;
    vector<int>mp(n+1,0);
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];if(!mp[a[i]])cnt++;
        mp[a[i]]++;
        G[i].clear();
    }
    for(int i=1;i<=n;i++){
        G[a[i]].push_back(i);
    }
    if(mp[a[1]]==2){
        cout<<"1\n";
    }else cout<<"0\n";
    vector<int>odd,even;
    for(int i=1;i<=n;i++){
        if(mp[i]==0)even.push_back(i);
        else if(mp[i]==1)odd.push_back(i);
    }
    vector<int>ans(n+1,0);
    if(cnt==n){
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" \n"[i==n];
        }
    }else{
        if(mp[a[1]]==2){
            mp[a[1]]=1;
            int cureven=0,curodd=0;
            for(int i=2;i<=n;i++){
                if(mp[a[i]]==2){
                    for(int i:G[a[i]])ans[i-1]=even[cureven];
                    cureven++;
                    mp[a[i]]=0;
                }
            }
            int l=1;
            for(int i=1;i<=n;i++){
                while(ans[l]!=0)l++;
                if(mp[a[i]])ans[l]=i;
            }
            for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
        }else{
            int cureven=0,curodd=0;
            for(int i=2;i<=n;i++){
                if(mp[a[i]]==2){
                    for(int i:G[a[i]])ans[i-1]=even[cureven];
                    cureven++;
                    mp[a[i]]=0;
                }
            }
            int l=1;
            for(int i=1;i<=n;i++){
                while(ans[l]!=0)l++;
                if(mp[a[i]]!=0)ans[l]=i;
            }
            for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}