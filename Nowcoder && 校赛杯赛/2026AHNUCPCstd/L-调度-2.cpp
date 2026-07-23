#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        a[x - 1]++;
    }
    
    auto isok = [&](int x) {
        i64 time = 0, work = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] <= x) {
                time +=(x - a[i]) / 3;
            } else {
                work += a[i] - x;
            }
        }
        return time >= work;
    };

    int l = 0, r = m, ans = 1e9;
    while(l <= r) {
        int mid =(l + r) / 2;
        if(isok(mid)) {
            ans = min(ans, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
