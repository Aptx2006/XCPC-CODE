#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5+5,MOD = 1e9 + 7;
int n,m,ans;
void solve(){
    string s;
    cin >> s;
    n=s.size();
    int ct1=0,ct2=0;
    string ans;
    for(int i=0;i<n;i++){
        if(s[i]=='(')ct1++;
        else if(ct2<ct1){
            ct2++;
        }else{
            string x(ct1,'(');
            ct1=ct2=0;
            ans += x;
            ans += '(';
        }
    }
    if(ct1==ct2)
    cout<<s<<'\n';
    else cout<<"impossible\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int times = 1;cin >> times;
    while(times--) solve();
    return 0;
}
