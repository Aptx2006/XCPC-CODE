#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define all(A) A.begin(), A.end()
#define dbg(A) cerr << #A << ':' << A << endl;

int n, m, k;

void solve(){
    cin >> n >> m;
    vector G(n, vector<i64>(m));
    for(auto &v: G) {
        for(auto &x: v) {
            cin >> x;
        }
    }
    i64 ans = 0;
    for(int j = 0; j < m; j++) {
        i64 tmp = 0;
        for(int i = 0; i < n; i++) {
            if(j != 0)
                tmp += G[i][j - 1];
            if(tmp >= G[i][j]) tmp -= G[i][j];
            else {
                ans += G[i][j] - tmp;
                tmp = 0;
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1, r;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
