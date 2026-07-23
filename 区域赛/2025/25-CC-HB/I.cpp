#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5,M=1e9+7;
#define all(A) A.begin(),A.end()
#define dbg(A) cout<<#A<<":"<<A<<' ';
int n,m,a[N];string s;
void solve(){
    cin >> n >> m;
    set<tuple<int,int,int>>st;
    for(int i=1;i<=n;i++){
        int x,y,z;cin>>x>>y>>z;
        if(st.count({x,y,z}))st.erase({x,y,z});
        else st.insert({x,y,z});
    }
    for(int i=1;i<=m;i++){
        int x,y,z;cin>>x>>y>>z;
        if(st.count({x,y,z}))st.erase({x,y,z});
        else st.insert({x,y,z});
    }
    map<int,int>mpx,mpy,mpz;int sum=st.size();
    vector<tuple<int,int,int>>P(all(st));
    for(auto [x,y,z]:P){
        mpx[x]++;
        mpy[y]++;
        mpz[z]++;
    }
    if(st.size()==0){
        cout<<"YES\n";return;
    }
    if(st.size()<6||st.size()%2==1){
        cout<<"NO\n";
    }else{
        for(auto [x,y]:mpx){
            if(y%2==1){
                cout<<"NO\n";return;
            }
        }
        for(auto [x,y]:mpy){
            if(y%2==1){
                cout<<"NO\n";return;
            }
        }
        for(auto [x,y]:mpz){
            if(y%2==1){
                cout<<"NO\n";return;
            }
        }
        cout<<"YES\n";
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}