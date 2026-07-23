#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ans = 0;
    cin >> n;
    vector<int> a(n), d(n);
    for(auto &x : a) cin >> x;
    for(int i = 1; i < n; i++) {
        d[i] = a[i] - a[i-1];
        ans += d[i];
    }
    sort(d.begin(), d.end());
    cout << ans << ' ';
    for(int i = n-1; i > 0; i--) {
        ans -= d[i];
        cout << ans << ' ';
    }
}