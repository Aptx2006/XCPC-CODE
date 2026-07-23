#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;
int n,ans;
vector<int>G[20];
void dfs(int cur,vector<int>s1,vector<int>s2){
    if(cur==n+1&&(!s1.empty()&&!s2.empty())){
        set<int>st1(s1.begin(),s1.end()),st2(s2.begin(),s2.end());
        int nn=0,cnt=0;
        for(auto x:s1){
            for(auto nx:G[x])
                if(st1.count(nx))cnt++;
        }
        nn+=cnt/2;
        cnt=0;
        for(int x:s2){
            for(auto nx:G[x])
                if(st2.count(nx))cnt++;
        }
        nn+=cnt/2;
        ans=min(ans,nn);
    }
    if(cur>n)return;
    s1.push_back(cur);
    dfs(cur+1,s1,s2);
    s1.pop_back();
    s2.push_back(cur);
    dfs(cur+1,s1,s2);
}
void solve(){
    int m;
    ans = LLONG_MAX;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v),G[v].push_back(u);
    }
    vector<int>s1,s2;
    dfs(1,s1,s2);
    cout<<ans;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
