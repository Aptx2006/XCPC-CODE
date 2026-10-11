#include<bits/stdc++.h>
using namespace std;
#define all(A) (A).begin(), (A).end()
using i64 = long long;
int n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(n), b(n), c(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    i64 ans = 0;
    for(int i = 0; i < n; i++) {
        ans += b[i];
        c[i] = a[i] - b[i];
    }
    sort(all(c), greater<int>());
    for(int i = 0; i < m; i++) ans += c[i];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
