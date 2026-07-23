#include<bits/stdc++.h>
using namespace std;
#define int long long
#define dbg(A) cout<<#A<<':'<<A<<'\n';
#define all(A) A.begin(),A.end()
using ld = long double;
mt19937_64 rnd (time(0));
const int N = 2e5+5, M = 1e9+7;
int n,m,a[4];
map<int,int>mp;
map<int,int>mapp;//id->map
map<int,int>rmap;//map->id
void dfs(int initId,vector<int>need,int cost){
    if(need.size()==0){
        mp[initId]=min(mp[initId],cost);
    }
    int sz=need.size();
    for(int i=0;i<sz;i++){
        vector<int>copy=need;
        int tcost=0;
        
    }
}
int tot=1;
void init(){
    for(int i=1;i<=(1<<4);i++){
        rmap[i]=tot;
        mapp[tot++]=i;
    }
    for(int i=1;i<=(1<<16);i++){
        mp[i]=100000000000;
        int t=i;
        vector<int>have;
        int cnt=0;
        while(t){
            if(t&1)have.push_back(mapp[(1<<cnt)]);
            cnt++;
            t>>=1;
        }
        dfs(i,have,0);
    }
}
void solve(){
    cin >> m;
    
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T >> a[0] >> a[1] >> a[2] >> a[3];
    init();
    while(T--) solve();
    return 0;
}
