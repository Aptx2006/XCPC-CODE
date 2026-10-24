#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

using P = pair<i64, i64>;

const int N = 3e5 + 5;
const i64 INF = 4e18;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
struct SCC{
    int n,now,cnt;
    int id;
    vector<vector<int>>ver;
    vector<int>dfn,low,col,S;
    SCC(int n):n(n),ver(n+1),low(n+1){
        dfn.resize(n+1,-1);
        col.resize(n+1,-1);
        now=cnt=0;
    }
    void add(int x,int y){
        ver[x].push_back(y);
    }
    void tarjan(int x,int e){
        if(x==e)id=x;
        dfn[x]=low[x]=now++;
        S.push_back(x);
        for(auto y:ver[x]){
            if(dfn[y]==-1){
                tarjan(y,e);
                low[x]=min(low[x],low[y]);
            }else if(col[y]==-1){
                low[x]=min(low[x],dfn[y]);
            }
        }
        if(dfn[x]==low[x]){
            int pre;
            cnt++;
            do{
                pre=S.back();
                col[pre]=cnt;
                S.pop_back();
            }while(pre!=x);
        }
    }
    void work(int &a,vector<vector<int>>&b,vector<int>&c,vector<int>&d,int e){
        int ansid=0;
        for(int i=1;i<=n;i++){
            if(dfn[i]==-1){
                tarjan(i,e);
            }
        }
        vector<int>siz(cnt+1);
        vector<vector<int>>adj(cnt+1);
        for(int i=1;i<=n;i++){
            siz[col[i]]++;
            for(auto j:ver[i]){
                int x=col[i],y=col[j];
                if(x!=y){
                    adj[x].push_back(y);
                }
            }
        }
        a=cnt;
        b=adj;
        c=col;
        d=siz;
        return ;
    }
    

};
void solve() {
    int n;cin>>n;
    vector<int>num,x(n),y(n);
    vector<pair<int,int>>point;
    map<pair<int,int>,int>pnum,wall;
    int tot=1;
    num.push_back(0);
    point.push_back({0,0});
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
        num.push_back(x[i]);
        num.push_back(y[i]);
        num.push_back(x[i]+1);
        num.push_back(y[i]+1);
        num.push_back(x[i]-1);
        num.push_back(y[i]-1);
        wall[{x[i],y[i]}]=1;
        for(int j=0;j<4;j++){
            point.push_back({x[i]+dx[j],y[i]+dy[j]});
        }
    }

    sort(point.begin(),point.end());
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    point.erase(unique(point.begin(),point.end()),point.end());
   
    auto find=[&](int x){
        return lower_bound(num.begin(),num.end(),x)-num.begin();
    };

    for(int i=0;i<point.size();i++){
        pnum[point[i]]=tot++;
    }

    int sz=num.size();
    vector<vector<int>>Gx(sz),Gy(sz),G(tot);
    for(int i=0;i<n;i++){
        Gx[find(x[i])].push_back(y[i]);
        Gy[find(y[i])].push_back(x[i]);
    }

    for(int i=0;i<sz;i++){
        Gx[i].push_back(-2e9);
        Gx[i].push_back(2e9);
        Gy[i].push_back(-2e9);
        Gy[i].push_back(2e9);
        sort(Gx[i].begin(),Gx[i].end());
        sort(Gy[i].begin(),Gy[i].end());
    }

    for(int i=0;i<tot-1;i++){
        auto [curx,cury]=point[i];
        int curid=pnum[{curx,cury}];
        int nxx,nxy,nxid;
        if(wall[point[i]])continue;
        auto it=0;
        it=upper_bound(Gx[find(curx)].begin(),Gx[find(curx)].end(),cury)-Gx[find(curx)].begin();
        if(Gx[find(curx)][it]!=2e9){
            nxid=pnum[{curx,Gx[find(curx)][it]-1}];
            if(curid!=nxid){
                G[curid].push_back(nxid);
                //cout<<curx<<' '<<cury<<"->"<<curx<<' '<<Gx[find(curx)][it]-1<<'\n';
            }
        }
        it=lower_bound(Gx[find(curx)].begin(),Gx[find(curx)].end(),cury)-Gx[find(curx)].begin()-1;
        if(Gx[find(curx)][it]!=-2e9){
            nxid=pnum[{curx,Gx[find(curx)][it]+1}];
            if(curid!=nxid){
                G[curid].push_back(nxid);
                //cout<<curx<<' '<<cury<<"->"<<curx<<' '<<Gx[find(curx)][it]+1<<'\n';
            }
        }
        it=upper_bound(Gy[find(cury)].begin(),Gy[find(cury)].end(),curx)-Gy[find(cury)].begin();
        if(Gy[find(cury)][it]!=2e9){
            nxid=pnum[{Gy[find(cury)][it]-1,cury}];
            if(curid!=nxid){
                G[curid].push_back(nxid);
                //cout<<curx<<' '<<cury<<"->"<<Gy[find(cury)][it]-1<<' '<<cury<<'\n';
            }
        }
    
        it=lower_bound(Gy[find(cury)].begin(),Gy[find(cury)].end(),curx)-Gy[find(cury)].begin()-1;
        if(Gy[find(cury)][it]!=-2e9){
            nxid=pnum[{Gy[find(cury)][it]+1,cury}];
            if(curid!=nxid){
                G[curid].push_back(nxid);
                //cout<<curx<<' '<<cury<<"->"<<Gy[find(cury)][it]+1<<' '<<cury<<'\n';
            }
        }
        

    }

    SCC scc(tot-1);

    for(int i=1;i<tot;i++){
        for(int j:G[i]){
            scc.add(i,j);
        }
    }
    int cnt=0;
    vector<vector<int>>adj;
    vector<int>siz,col;
    scc.work(cnt,adj,col,siz,pnum[{0,0}]);
    vector<int>in(cnt+1),ans(cnt+1,1);
    queue<int>Q;
    vector<vector<int>>P(cnt+1);
   // for(int i=1;i<=cnt;i++)cout<<siz[i]<<" \n"[i==cnt];
    Q.push(col[pnum[{0,0}]]);
    //cout<<col[pnum[{0,0}]]<<'\n';
    for(int i=1;i<=cnt;i++){
        ans[i]=siz[i];
        sort(adj[i].begin(),adj[i].end());
        adj[i].erase(unique(adj[i].begin(),adj[i].end()),adj[i].end());
    }
    vector<int>vis(cnt+1);
    while(!Q.empty()){
        int p=Q.front();
        vis[p]=1;
        Q.pop();
        for(int nx:adj[p]){
            //ans[nx]+=ans[p];
            ans[nx]=max(ans[nx],ans[p]+siz[nx]);
            Q.push(nx);
        }
    }
    int anss=0;
    for(int i=1;i<=cnt;i++){
        if(vis[i])anss=max(anss,ans[i]);
    }
    cout<<anss<<'\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while(T--) solve();
    return 0;
}