#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(A) A.begin(),A.end()
using ld = long double;
const int N = 2e5+5,M=1e9+7;
int n,m;
void solve(){
    cin >> n;
    int sum = 0;
    vector<int>a(n);
    vector<int>pre(n+1,0);
    for(auto &x:a) {
        cin >> x;
    }
    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1] + a[i-1];
    }
    int mn = *min_element(all(a)),id;
    double res = pre[n]*1.0/n;
    for(int i=1;i<=n;i++) if(a[i-1]==mn) id = i;
    res = max(res,(pre[id+1]-pre[0])*1.0/(id+1));
    res = max(res,(pre[n]-pre[id-2])*1.0/(n-id+2));
    cout << fixed << setprecision(20) << res << '\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}