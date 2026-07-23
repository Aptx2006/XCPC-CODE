#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(A) A.begin(),A.end()
using ld = long double;
const int N = 2e5+5,M = 1e9+7;
int n,a,b,c;
vector<unordered_set<int>>team(500);
void solve(){
    cin >> n;
    while(n--){
        cin >> a >> b >> c;
        if(c<240){
            if(!team[a].count(b)){
                cout<<b<<'\n';
                team[a].insert(b);
            }else 
                cout<<"0\n";
        }else{
            if(!team[a].count(b) and team[a].size()<3){
                cout<<b<<'\n';
                team[a].insert(b);
            }else 
                cout<<"0\n";
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; //cin >> T;
    while(T--) solve();
}
