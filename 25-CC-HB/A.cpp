#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(A) A.begin(),A.end()
const int N = 2e5+5,M=1e9+7;
int n,m,a[N];
void solve(){
    set<int>st;
    cin >> n;
    for(int t,i=0;i<n;i++) cin >> t,st.insert(t);
    vector<int>a(all(st));
    if(a.size()==1){
        cout<<"infinite\n";
    }else{
        int m=a.size(),d = a[1]-a[0],mn = a[0];
        for(int i=1;i<m;i++){
            mn = min(mn,a[i]);
            d = __gcd(d,a[i]-a[i-1]);
        }
        cout << d << " ";
        int y = d/__gcd(d,mn);
        cout << y <<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}