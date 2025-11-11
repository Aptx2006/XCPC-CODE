#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(A) A.begin(),A.end()
#define dbg(A) cout<<#A<<" is "<<A<<'\n';
const int N = 1e3+5,M=1e9+7;
int n,m,k,a[N];
void solve(){
    cin >> n >> m >> k;
    vector<int>pos(m+1,0);
    for(int i=0,x,y;i<k;i++){
        cin >> x >> y;
        pos[y] = x;
    }
    for(int t=0;t<(1<<k);t++){
        vector dp(105,vector<int>(105,1e9));
        for(int i=1;i<=n;i++) dp[i][0]=0;
        int cur = 0;
        for(int j=1;j<=m;j++){
            int l=1,r=n;
            if(pos[j]){
                if((t>>cur)&1) l=pos[j]+1;
                else r=pos[j]-1;
                cur++;
            }
            for(int i=l;i<=r;i++) 
                dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
            for(int i=l;i<=r;i++) 
                dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
            for(int i=r;i>=l;i--) 
                dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
        }
        int mn=1e9;
        for(int i=1;i<=n;i++) mn=min(mn,dp[i][m]);
        cout<<(mn==1e9?-1:mn-1)<<' ';
    }cout<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}