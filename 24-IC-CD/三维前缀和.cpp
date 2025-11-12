#include<bits/stdc++.h>
using namespace std;
#define int long long
using ld = long double;
#define dbg(A) cout<<#A<<" : "<<A<<" ";
#define all(A) A.begin(), A.end()
const int N = 305,M = 1e9+7;
int n,m,q,ans;
int dp[N][N][N],pre[N][N][N];
void solve(){
    string s;
    cin >> n >> q >> s;
    auto add = [&](int &a,int b){
        a = (a+b+M)%M;
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                pre[i+1][j+1][k+1] = dp[i][j][k];
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
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; //cin >> T;
    while(T--) solve();
}