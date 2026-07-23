#include<bits/stdc++.h>
using namespace std;
#define int long long
using ld = long double;
#define dbg(A) cout<<#A<<" : "<<A<<endl;
#define all(A) A.begin(), A.end()
const int N = 2e5+5,M = 1e9+7;
int n,m,a[N],ans;
void solve(){
    string s;
    cin >> s;
    n=s.size();
    if(count(all(s),'-')==0||n<5||s[0]=='-'||s[n-1]=='-'||s[n-2]=='-'||s[n-3]=='-'){
        cout<<"No\n";return;
    }
    cout<<"Yes ";
    int endindex=n-1;
    while(s[endindex]=='>')endindex--;
    vector<pair<int,int>>ans;
    for(int i=n-1;i>=endindex+3;i--){
        ans.push_back({1,i+1});
    }
    for(int i=1;i<=endindex;i++){
        if(s[i]=='>'){
            ans.push_back({i+1,endindex+4-i});
        }
    }
    cout<<ans.size()<<"\n";
    for(auto [x,y]:ans){
        cout<<x<<" "<<y<<"\n";
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}