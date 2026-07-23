#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5,M=1e9+7;
int n,m,k,a[N],ans,u,v;

void solve(){
    string s,ss;
    cin >> s;
    n = s.size();
    //cout<<s<<endl;
    int c[3]{};
    for(int i=0;i<s.size();i++){
        if(s[i]=='2') c[2]++;
        else if(i&1)c[s[i]-'0']++;
        else c[s[i]-'0']--;
    }
    c[0] = abs(c[0]),c[1] = abs(c[1]),c[2] = abs(c[2]);
    
    int mn = min(c[0],c[2]);
    c[0] -= mn,c[2] -= mn;
    mn = min(c[1],c[2]);
    c[1] -= mn,c[2] -= mn;
    c[2] &= 1;
    cout<<c[0]+c[1]+c[2]<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
    return 0;
}
