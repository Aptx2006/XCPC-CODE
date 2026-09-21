#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1000005,P=998244353;
int r[N],y[N],b[N];
int n;
int rl[N],rr[N],ry[N],rb[N],cnt;
int ml[N],vis[N];
int dp[N];

void sol(int x){
    int cury=ry[x],curb=rb[x];
    int l=rl[x];
    int minn=1,maxn=n;
    if(x<cnt-1)maxn=rl[x+1]-1;
    if(x>=1)minn=(rr[x-1]+1);
    for(;l>minn;l--){
        if(cury>=y[l-1]&&curb>=b[l-1]){
            cury-=y[l-1];curb-=b[l-1];
        }
        else break;
    }
    int rrr=rr[x];
    while(l<=rl[x]){
        while(rrr<maxn&&cury>=y[rrr+1]&&curb>=b[rrr+1]){
            cury-=y[rrr+1];
            curb-=b[rrr+1];
            rrr++;
        }
        ml[l]=rrr;
        cury+=y[l];
        curb+=b[l];
        l++;
    }
}

void solve() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i]>>y[i]>>b[i];
    }
    int f=0,cy=0,cb=0;
    for(int i=1;i<=n+1;i++){
        if(f==0){
            if(r[i]){
                f=1;
                rl[cnt]=i;
                cy=1-y[i];cb=1-b[i];
            }
        }else{
            if(r[i]){
                cy+=1-y[i];cb+=1-b[i];
            }else{
                f=0;
                rr[cnt]=i-1;
                ry[cnt]=cy;rb[cnt]=cb;
                cnt++;
            }
        }
    }
    for(int i=0;i<cnt;i++){
        sol(i);
    }
    int st=1;
    int ans=0;
    dp[0]=0;
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<ml[i]<<"\n";
        
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
}
