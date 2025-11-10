#include<bits/stdc++.h>
using namespace std;
#define int long long
#define dbg(A) cout<<#A<<'='<<A<<' ';
const int N = 2e5+5,M = 1e9 + 7;
int n,m,ar[N],ans,k;
void solve(){
    cin >> n >> k >> m;
    if(n==m){
        cout<<n<<'\n';return;
    }
    int cnt = n/k;
    if(n-cnt<m){
        cnt -= m - (n-cnt);
    }
    cnt--;
    //cout << cnt <<' '<< m <<'\n';
    ans = cnt/2 + m + 1;
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T=1; cin >> T;
    while(T--) solve();
    return 0;
}
