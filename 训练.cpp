#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;

int n, m, q;

void solve() {
    vector<int> mx(1e5 + 5, 0);
    vector<pair<int, int>> st, last;
    i64 sum = 0;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int c, v;
            cin >> c >> v;
            st.push_back({c, v});
            if (v >= mx[c]) {
                last.push_back({c, mx[c]});
                sum += (v - mx[c]);
                mx[c] = v;
            } else {
                last.push_back({-1, -1});
            }
        } else if (op == 2) {
            if (st.empty()) continue;
            st.pop_back();
            auto [c, v] = last.back();
            last.pop_back();
            if (c != -1) {
                sum -= (mx[c] - v);
                mx[c] = v;
            }
        } else if (op == 3)
            cout << sum << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    solve();
    return 0;
}
