#include<bits/stdc++.h>
using namespace std;
#define int long long
#define dbg(A) cout<<#A<<':'<<A<<'\n';
const int N = 5e5+5,M = 1e9+7;
int n,m,ans,dp[N][2];
const int inf = 1e9;
void solve(){
    string tag;
    cin >> tag >> n;
    auto getpos = [](string str){
        vector<int>pos;
        int p = str.find("LR");
        while(p!=-1){
            pos.push_back(p);
            p = str.find("LR",p+1);
        }
        return pos;
    };
    int c1=inf,c0=inf;m = tag.size();
    for(int i= m-1;i>=0;i--) {
        dp[i][0] = c0,dp[i][1] = c1;
        (tag[i]=='L'?c0:c1) = i;
    }
    while(n--) {
        string s ; cin >> s;
        if(tag[0]=='L' and s[0]!='L' or (tag.back()=='R' and s.back()!='R')) {
            cout << "NO\n";continue ;
        }
        int u = (s[0] == 'L' ? c0 : c1);
        if(u>=m){
            cout << "NO\n";continue;
        }
        for(int i = 1;i < s.size();i++) {
            if(s[i] == 'L') u = dp[u][0];
            else u = dp[u][1] ;
            if(u >= m) {
                cout << "NO\n";goto AAA;
            }
        }
        cout<<"YES\n";
        AAA:{}
    }
} 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
    return 0;
}
