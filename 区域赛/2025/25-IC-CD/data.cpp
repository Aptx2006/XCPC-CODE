#include<bits/stdc++.h>
using namespace std;
#define int long long
#define dbg(A) cout<<#A<<'='<<A<<' ';
const int N = 2e5+5,M = 1e9 + 7;
int n,m,a[N],b[N],ans,k;
mt19937_64 rg(random_device{}());
void solve(){
    cout<<1<<endl;
    n = 5;
    for(int i=1;i<=n;i++){
        m = rg()%40;
        cout<<m<<" ";
    }cout<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}
