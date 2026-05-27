#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x)(x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " <<(x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    cin >> n >> m;
    vector<i64> x(n + 1), y(n + 1);
    vector<i32> upd(n + 1, 0);
    set<pair<i64, i32>> st;
    for(i32 i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        st.insert({x[i], i});
    }
    for(i32 i = 1; i <= m; i++) {
        i64 l, r, u, v;
        cin >> l >> r >> u >> v;
        auto it = st.lower_bound({l, 0});
        vector<i32> upd1;
        while(it != st.end()and it->first <= r) {
            upd1.push_back(it->second);
            it = st.erase(it);
        }
        for(i32 id : upd1) {
            x[id] += u;
            y[id] += v;
            upd[id]++;
            if(upd[id] < 6) {
                st.insert({x[id], id});
            }
        }
    }
    for(i32 i = 1; i <= n; i++) {
        if(upd[i] >= 6) {
            cout << "Disappeared\n";
        } else if(upd[i] == 0) {
            cout << "Cumulus " << x[i] << " " << y[i] << "\n";
        } else {
            cout << "Cirrus " << x[i] << " " << y[i] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
