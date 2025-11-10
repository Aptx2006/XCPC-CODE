#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5, M = 1e9+7;
int n,m,ans;
vector<int>weizhi(N+1);
struct nod{
    int x,y;
    bool operator < (const nod &rhs) const{
        return llabs(weizhi[y]-weizhi[x]) > llabs(weizhi[rhs.y]-weizhi[rhs.x]);
    }
};
priority_queue<nod>pq;
void solve(){
    cin >> n;
    vector<int>goal(n+1,0);
    vector<int>fangxiang(n+1,0);
    vector<int>ans(n+1,0);
    vector<int>G[n+1];
    map<pair<int,int>,int>mp;
    for(int i=1;i<=n;i++){
        cin>>goal[i];
        G[goal[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        cin>>weizhi[i];
    }
    for(int i=1;i<=n;i++){
        if(weizhi[i]<weizhi[goal[i]]){
            fangxiang[i]=1;//right
        }
        else{
            fangxiang[i]=-1;//left
        }
    }
    for(int i=1;i<=n;i++){
        if(fangxiang[i]!=fangxiang[goal[i]]){
            pq.push({i,goal[i]});
        }
    }
    while(!pq.empty()){
        auto [x,y]=pq.top();
        pq.pop();
        if(mp.count({x,y})||mp.count({y,x})){
            continue;
        }
        else{
            if(goal[x]==y){
                double temp=1.0*(weizhi[x]+weizhi[y])/2;
                mp[{x,y}]=1;
                ans[x]=llabs(weizhi[x]-weizhi[y]);
                queue<int>Q;
                for(int j=0;j<G[x].size();j++){
                    if(fangxiang[G[x][j]]==fangxiang[x])
                    Q.push(G[x][j]);
                    // if(ans[G[x][j]]==0)
                    // ans[G[x][j]]=llabs((weizhi[G[x][j]]-temp)*2);
               //     cout<<j<<"qi e qu x"<<G[x][j]<<"\n";
                }
                while(!Q.empty()){
                    int cur=Q.front();
                    Q.pop();
                    for(int i:G[cur]){
                        if(fangxiang[i]==fangxiang[cur])
                    Q.push(i);
                    }
                    ans[cur]=llabs((weizhi[cur]-temp)*2);
                }
            }
            else if(goal[y]==x){
                double temp=1.0*(weizhi[x]+weizhi[y])/2;
                mp[{y,x}]=1;
                ans[y]=llabs(weizhi[x]-weizhi[y]);
                queue<int>Q;
                for(int j=0;j<G[y].size();j++){
                    if(fangxiang[G[y][j]]==fangxiang[y])
                    Q.push(G[y][j]);
                }
                while(!Q.empty()){
                    int cur=Q.front();
                    Q.pop();
                    for(int i:G[cur]){
                        if(fangxiang[i]==fangxiang[cur])
                    Q.push(i);
                    }
                    
                    ans[cur]=llabs((weizhi[cur]-temp)*2);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}
