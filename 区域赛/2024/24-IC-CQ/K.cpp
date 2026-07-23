#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5, MOD = 1e9+7;
int n,m,a[N];
void solve(){
    cin>>n;
    string s,s1;
    cin>>s>>s1;
    for(int i=0;i<n;i++){
        if(s[i]!='1'&&s1[i]!='1'){
            cout<<"0";return;
        }
    }
    cout<<"1";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int times=1;
    while(times--)solve();
    return 0;
} 
