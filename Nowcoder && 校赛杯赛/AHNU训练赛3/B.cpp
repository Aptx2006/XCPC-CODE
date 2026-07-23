#include<bits/stdc++.h>
using namespace std;
using i64=long long;
#define int long long
void solve(){
    int n;
    cin>>n;
    string s;cin>>s;
    s='9'+s;
    vector<int>num(2,0);
    i64 ans=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='0'){
            num[0]++;ans+=num[1];
        }else{
            num[1]++;//假设全填 ？-> 1
        }
    }
    int num0=0;
    for(int i=n;i;i--){
        if(s[i]=='1'){
            num[1]--;
        }else if(s[i]=='0'){
            num0++;
        }else{
            num[1]--;
            int res1=num0,res2=num[1];
            if(res2>=res1){
                num0++;
                ans=ans+res2-res1;
            }
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
