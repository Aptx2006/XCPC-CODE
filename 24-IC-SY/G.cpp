#include<bits/stdc++.h>
using namespace std;
#define int long long
#define dbg(A) cout<<#A<<':'<<A<<'\n';
#define all(A) A.begin(),A.end()
using ld = long double;
mt19937_64 rnd (time(0));
const int N = 2e5+5, M = 1e9+7;
int n,m,a[N],b[N];
pair<int,int> query(int l,int r){
    cout<<"? "<<(l+r)<<" "<<2<<endl;
    int x,y;cin>>x>>y;
    return {x,y};
}
void add(int x,int y,int &up,int &down){
        int temp1=up*y+x*down;
        int temp2=y*down;
        up=temp1;
        down=temp2;
        up=up/__gcd(temp1,temp2);
        down=down/__gcd(temp1,temp2);
}
void solve(){
    cin >> n;
    map<int,int>mp;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        mp[a[i]]++;
    }
    
    vector<int>G;
    vector<pair<int,int>>ans;
    bool f=0;
    for(auto [x,y]:mp){
        G.push_back(x);
        if(y>=2)f=1;
    }
    int truen=G.size();
    int up=0,down=1;
    if(f){
    for(int i=1;i<truen;i++){
        auto [x,y]=query(G[i],G[i-1]);
        int di=G[i]-G[i-1];
            add(di*x,y,up,down);
    }
}else{
    ans.push_back({0,1});
    for(int i=1;i<truen-1;i++){
        auto [x,y]=query(G[i],G[i]);
        ans.push_back({x,y});
    }
    ans.push_back({0,1});
    for(int i=1;i<truen;i++){
        int tx=ans[i].first,ty=ans[i].second;
        add(ans[i-1].first,ans[i-1].second,tx,ty);
        add(tx*(G[i]-G[i-1]),ty*2,up,down);
    }  
}
    cout<<"! "<<up<<" "<<down<<endl;
}
signed main(){
    int T = 1; cin>>T;
    while(T--) solve();
    return 0;
}
