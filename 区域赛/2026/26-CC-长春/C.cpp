#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int n, m, k;

void solve(){
    cin >> n >> k;
    vector<int> b(n);
    for(auto &x: b) cin >> x;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int j = i % k;
        if(b[i] > k) continue;
        mp[(b[i] - j + k) % k]++;
    }
    int ans = 0;
    for(auto &[x, y]: mp) ans = max(ans, y);
    ans = n - ans;
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
