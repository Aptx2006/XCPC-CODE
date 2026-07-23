#include<bits/stdc++.h>
using namespace std;
#define int long long
using ld = long double;
#define dbg(A) cout<<#A<<" : "<<A<<" ";
#define all(A) A.begin(), A.end()
const int N = 305,M = 1e9+7;
int n,m,q,ans;
int dp[N][N][N][3],pre[N][N][N];
void solve(){
    string s;
    cin >> n >> q >> s;
    dp[1][0][0][0] = 1;
    dp[0][1][0][1] = 1;
    dp[0][0][1][2] = 1;
    auto add = [&](int &a,int b){
        a = (a+b+M)%M;
    };
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            for(int k=0;k<=n-i-j;k++){
                if(i+j+k==0) continue;
                char ch = s[i+j+k-1];
                auto dpp = dp[i][j][k];
                if(ch == 'a'){
                    dpp[1] = dpp[2] = 0;
                }else if(ch == 'b'){
                    dpp[0] = dpp[2] = 0;
                }else if(ch == 'c'){
                    dpp[0] = dpp[1] = 0;
                }
                if(i+j+k==n) continue;
                add(dp[i+1][j][k][0],dpp[1]+dpp[2]);
                add(dp[i][j+1][k][1],dpp[0]+dpp[2]);
                add(dp[i][j][k+1][2],dpp[0]+dpp[1]);
            }
        }
    }
    int c[4]{};
    for(auto x:s) {
        if(x!='?') c[x-'a']++;
        else c[3]++;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            for(int k=0;k<=n-i-j;k++){
                if(i+j+k<n) dp[i][j][k][0]=dp[i][j][k][1]=dp[i][j][k][2]=0;
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                pre[i+1][j+1][k+1] = dp[i][j][k][0] + dp[i][j][k][1] + dp[i][j][k][2];
                add(pre[i+1][j+1][k+1],pre[i+1][j+1][k]);
                add(pre[i+1][j+1][k+1],pre[i][j+1][k+1]);
                add(pre[i+1][j+1][k+1],pre[i+1][j][k+1]);
                add(pre[i+1][j+1][k+1],-pre[i][j][k+1]);
                add(pre[i+1][j+1][k+1],-pre[i][j+1][k]);
                add(pre[i+1][j+1][k+1],-pre[i+1][j][k]);
                add(pre[i+1][j+1][k+1],pre[i][j][k]);
            }
        }
    }
    while(q--){
        int ii,jj,kk;
        cin >> ii >> jj >> kk;
        ans = 0;
        // for(int i=0;i<=ii+c[0];i++){
        //     for(int j=0;j<=min(jj+c[1],n-i);j++){
        //         int k = n-i-j;
        //         if(i>ii+c[0] or j>jj+c[1] or k>kk+c[2]) continue;
        //         add(ans,dp[i][j][k][0]+dp[i][j][k][1]+dp[i][j][k][2]);
        //     }
        // }
        ii = min(ii+c[0],n),jj = min(jj+c[1],n) , kk = min(kk+c[2],n);
        cout<<pre[ii+1][jj+1][kk+1]<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; //cin >> T;
    while(T--) solve();
}