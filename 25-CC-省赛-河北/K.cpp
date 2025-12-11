#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128_t;

const i64 N = 2e5 + 5, M = 1e9 + 7;
i64 n, m;
string s;

void solve() {
    cin >> n >> m;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    cin >> s;

    int d = 1;
    set<int> st;
    for(int i = 0; i < n; i ++) st.insert(i);
    auto it = st.begin();

    auto next = [&]() {
        if(d) {
            if(it == prev(st.end())) it = st.begin();
            else it++; 
        }else {
            if(it == st.begin()) it = prev(st.end());
            else it = prev(it);
        }
    };

    for(auto &x : s) {
        --a[*it];   
        auto tmp = it;
        if(x == 'S') {
            next();
        }else if(x == 'R') {
            d = !d;
        }else if(x == 'D') {
            next();
            a[*it] += 2;
        }
        next();
        if(a[*tmp] == 0)  st.erase(tmp);
    }
    for(auto &x : a) cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; //cin >> T;
    while(T--) solve();
}
