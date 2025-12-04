#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(A) A.begin(), A.end()
const int N = 20, M = 998244353;
int n, m;
int G[N][N];
void solve() {
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            G[i][j] = a[i];
            if(i==j) G[i][j]++;
            G[i][j] %= M;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << G[i][j] << ' ';
        }cout << "\n";
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1 ; //cin >> T;
    while(T--) solve();
}