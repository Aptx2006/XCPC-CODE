/**********************************************************************
	Solution ID: 17178
	Problem: I
	User: team0307
	Language: C++
	Result: AC
	Time: 155ms
	Memory: 1408KB
	Submit Time: 2026-10-11 13:43:19
	Code Length: 1555 chars
**********************************************************************/

#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define dbg(A) cout << (#A) << ':' << A << endl;

int n, m;
struct nod{
    i64 x,len;
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>fa(n+1);
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    auto findfa=[&](auto &&findfa,int x)->int{
        return x==fa[x]?fa[x]:fa[x]=findfa(findfa,fa[x]);
    };
    cout<<m<<endl;

    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        cout<<u<<' '<<v<<endl;
        int fau=findfa(findfa,u),fav=findfa(findfa,v);
        fa[fau]=fav;
    }

    cin>>m;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        int fau=findfa(findfa,u),fav=findfa(findfa,v);
        fa[fau]=fav;
    }

    cin>>m;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        int fau=findfa(findfa,u),fav=findfa(findfa,v);
        fa[fau]=fav;
    }
    
    cin>>m;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        int fau=findfa(findfa,u),fav=findfa(findfa,v);
        fa[fau]=fav;
    }
    set<int>s;
    for(int i=1;i<=n;i++){
        s.insert(findfa(findfa,i));
    }
    cout<<s.size()<<endl;
}
void solve2(){
    int n,m;cin>>n>>m;
    cout<<m<<endl;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        cout<<u<<' '<<v<<endl;
    }
    int t;cin>>t;
    cout<<t<<endl;
}
int main(int argc, char *argv[]) {
    int id = argc > 1 ? atoi(argv[1]) : 0;
    if(id==0){
        solve();
    }else{
        solve2();
    }
    return 0;
}
