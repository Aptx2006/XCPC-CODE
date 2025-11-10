#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5,M = 1e9+7;
int n,m,q,k;
#define dbg(A) cout<<#A<<':'<<A<<endl;
int a,b,c,d;
void solve(){
    cin>>a>>b>>c>>d;
    int basex=a,basey=b;
    while(basex%2==0){basex/=2;}
    while(basey%2==0){basey/=2;}
    int xl=0,xr=a/basex,yl=0,yr=b/basey;
    int midx=-1,midy=-1;
    if(c%basex!=0||d%basey!=0||c>a||d>b){
        cout<<"-1\n";return;
    }
    vector<vector<int>>ans;
    int xx=c/basex,yy=d/basey;
    if(basex==1)xx=c;
    if(basey==1)yy=d;
    while(midx!=xx||midy!=yy){
        if(xr==xx||xl==xx)xl=xx,xr=xx;
        midx=(xr+xl)/2;
        
        if(yr==yy||yl==yy)yl=yy,yr=yy;
        midy=(yr+yl)/2;

        ans.push_back({xl,yl,xr,yr});
        if(midx>xx)xr=midx;
        else if(midx<xx)xl=midx;
        if(midy>yy)yr=midy;
        else if(midy<yy)yl=midy;
    }
    cout<<ans.size()<<endl;
    for(auto x:ans){
        for(int i=0;i<4;i++){
            if(i%2==0)cout<<x[i]*basex<<" ";
            else cout<<x[i]*basey<<" ";
        }
        cout<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}
