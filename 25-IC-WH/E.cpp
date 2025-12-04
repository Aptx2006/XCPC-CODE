#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define all(A) A.begin(), A.end()
const int N = 2e5 + 5, M = 1e9 + 7;
int n, m;
void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    int f1 = 0, f2 = 0;
    sort(all(a)), sort(all(b));
    int sum1 = (a[0] & 1), sum2 = (b[0] & 1);
    for(int i = 1; i < n; i ++ ){
        sum1 += a[i] % 2, sum2 += b[i] % 2;
        if(abs(a[i]-a[i-1])==1) f1 = 1;
        if(abs(b[i]-b[i-1])==1) f2 = 1;
    }
    if(f1 == 1 and f2 == 1 and (sum1) == (sum2)) {
        cout << "Yes\n";
    }else{
        if(a==b) cout << "Yes\n";
        else cout << "No\n";
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1 ; cin >> T;
    while(T--) solve();
}