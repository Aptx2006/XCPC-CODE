#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<i64> a(n);
    for(auto &x: a) cin >> x;
    
    vector<i64> mx(n);
    mx[n-1] = a[n-1];
    for (int i = n - 2; i >= 0; i--) {
        mx[i] = max(a[i], a[i] + mx[i+1]);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (mx[i] > 0) ans++;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    solve();
}
