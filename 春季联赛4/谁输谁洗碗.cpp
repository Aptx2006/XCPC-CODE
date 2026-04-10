#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<pair<string, int>> a(n);
    for(auto &[x, y] : a)  cin >> x >> y;
    auto fun = [](int x) {
        string s(4, '0');
        for (int i = 3; i >= 0; i--) {
            s[i] = '0' + (x % 10);
            x /= 10;
        }
        return s;
    };
    for(int i = 0; i <= 9999; i++) {
        string s = fun(i);
        bool ok = 1;
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                if (s[k] == a[j].first[k]) {
                    cnt++;
                }
            }
            if (cnt != a[j].second) {
                ok = 0;
                break; 
            }
        }
        if (ok) {
            cout << s << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    while(t--) {
        solve();
    }
    return 0;
}
