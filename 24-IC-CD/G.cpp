#include<bits/stdc++.h>
using namespace std;
#define int long long
using ld = long double;
#define dbg(A) cout<<#A<<" : "<<A<<endl;
#define all(A) A.begin(), A.end()
const int N = 2e5+5,M = 1e9+7;
int n,m,a[N],ans;
void solve(){
    cin >> n;
    unordered_set<int>st{0};
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    for(int i=1;i<n;i++){
        int x = a[i]&a[i+1],y = a[i]|a[i+1], z = a[i]^a[i+1];
        st.insert(x),st.insert(y),st.insert(z),st.insert(z&a[i]),st.insert(z&a[i+1]);
    }
    cout<<st.size()<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1; //cin >> T;
    while(T--) solve();
}