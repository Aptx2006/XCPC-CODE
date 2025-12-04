#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int MOD = 1e9 + 7;
int n;
void solve() {
    cin >> n;
    vector G(2*n, vector<int>(2*n, 0));
    // n n^2 n^3 n^4
    for(int i = 0; i < n - 1; i++) {
        G[n-1][i] = 1;
        G[i][n-1] = n;
    }
    for(int i = n; i < 2*n; i++) {
        G[n-1][i] = n*n;
        G[i][n-1] = n*n*n;
    }
    for(auto v: G) {
        for(auto x: v) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) solve();
}