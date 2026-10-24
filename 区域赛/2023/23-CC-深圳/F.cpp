#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

using P = pair<i64, i64>;

const int N = 3e5 + 5;
const i64 INF = 4e18;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

void solve() {
    int n;
    cin>>n;
    vector<vector<int>>G(n+1);
    vector<int>in(n+1);
    map<int,int>mp;
    for(int i=1;i<=n;i++){
        int u,v;cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        in[u]++;
        in[v]++;
    }
    for(int i=1;i<=n;i++){
        mp[in[i]]++;
    }
    vector<int>vis(n+1);
    stack<int>s;
    vector<int>c;
    bool find=0;
    auto dfs=[&](auto &&dfs,int x,int fa)->void{
        if(find)return;
        if(vis[x]){
            if(find)return;
            find=1;
            c.push_back(x);
            while(!s.empty() and s.top()!=x){
                c.push_back(s.top());
                s.pop();
            }
            return;
        }
        vis[x]=1;
        s.push(x);
        for(auto nx:G[x]){
            if(nx==fa)continue;
            dfs(dfs,nx,x);
        }
        if(!s.empty())s.pop();
    };
    dfs(dfs,1,0);
    c.push_back(c[0]);
    i64 ans=0;
    auto add=[&](int x){
        mp[in[x]]--;
        if(mp[in[x]]==0)mp.erase(mp.find(in[x]));
        in[x]++;
        mp[in[x]]++;
    };
    auto sub=[&](int x){
        mp[in[x]]--;
        if(mp[in[x]]==0)mp.erase(mp.find(in[x]));
        in[x]--;
        mp[in[x]]++;
    };
    for(int i=0;i+1<c.size();i++){
        int u=c[i],v=c[i+1];
        //cout<<u<<' '<<v<<'\n';
        sub(u);sub(v);
        if(mp.rbegin()->first >=5){
            ans+=0;
        }else{
            if( (mp.rbegin()->first ==4) and (mp.rbegin()->second==1) )ans+=(n-1);
            else if( (mp.rbegin()->first ==4) and (mp.rbegin()->second!=1) )ans+=0;
            else ans+=n;
        }
        add(u);add(v);
        //cout<<ans<<'\n';
    }
    cout<<ans<<'\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while(T--) solve();
    return 0;
}