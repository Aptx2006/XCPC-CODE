#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(A) A.begin(),A.end()
#define dbg(A) cout<<#A<<" is "<<A<<'\n';
const int N = 1e3+5,M=1e9+7;
int n,m,G[N][N];
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> G[i][j];
        }
    }
    int cur = 0;
    for(int i=1;i<=n;i++){
        int tmp = 0;
        for(int j=m;j>=1;j--){
            if(G[i][j]<0) tmp-=G[i][j],G[i][j]=0;
            else{
                int mn = min(tmp,G[i][j]);
                tmp-=mn,G[i][j]-=mn;
            }
        }
        cur+=tmp;
        if(i!=n)
            for(int j=1;j<=m;j++) G[i+1][j] += G[i][j];
        else 
            for(int j=1;j<=m;j++) cur+=G[i][j];
    }
    cout<<cur<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}