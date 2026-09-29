#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

using P = pair<i64, i64>;
i64 n, m, q, ans;

void solve() {
    cin >> n >> m >> q;
    set<P> st1_x, st1_y;
    multiset<i64> st2_x, st2_y;
    st1_x.insert({0, n});
    st1_y.insert({0, m});
    st2_x.insert(n);
    st2_y.insert(m);
    while(q--) {
        i64 op, i;
        cin >> op >> i;
        if(op == 1) {
            P tmp = {i, 0};
            auto cur = prev(st1_x.upper_bound(tmp));
            i64 len = i - cur->first;
            st1_x.insert({cur->first, len});
            st1_x.insert({i, cur->second - len});
            
            st2_x.erase(st2_x.find(cur->second));
            st2_x.insert(len);
            st2_x.insert(cur->second - len);

            st1_x.erase(cur);
        }else {
            P tmp = {i, 0};
            auto cur = prev(st1_y.upper_bound(tmp));
            i64 len = i - cur->first;
            st1_y.insert({cur->first, len});
            st1_y.insert({i, cur->second - len});

            st2_y.erase(st2_y.find(cur->second));
            st2_y.insert(len);
            st2_y.insert(cur->second - len);
            
            st1_y.erase(cur);
        }
        i64 ans = *prev(st2_x.end()) * *prev(st2_y.end());
        cout << ans << '\n'; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
