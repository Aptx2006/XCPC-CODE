#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using pbset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, ans, cnt;
using pii = pair<i64, i64>;

void solve() {
    cin >> n >> m >> k;
    vector<i64> a(m + 1), b(m + 1), c(m + 1), ans(m + 1);
    for(int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }


    vector<queue<int>> q(n + 1);
    bool busy[n + 1]{0};
    pbset st; 
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    int p = 1;
    while(p <= m or !pq.empty()) {
        i64 time = 2e18;
        if (p <= m) time = min(time, b[p]);
        if (!pq.empty()) time = min(time, pq.top().first);

        while(!pq.empty() and pq.top().first == time) {
            auto [_, id] = pq.top(); 
            pq.pop();
            int u = a[id];
            k++;
            busy[u] = 0;
            if(!q[u].empty()) {
                st.insert(q[u].front());
            }
        }

        while(p <= m and b[p] == time) {
            int u = a[p];
            if (q[u].empty() and !busy[u]) {
                st.insert(p);
            }
            q[u].push(p);
            p++;
        }

        while(k > 0 and !st.empty()) {
            int id = *st.begin(); 
            st.erase(st.begin()); 
            int u = a[id];
            q[u].pop();
            k--;
            busy[u] = 1;
            ans[id] = time;
            pq.push({time + c[id], id});
        }
    }

    for(int i = 1; i <= m; i++) {
        cout << ans[i] << " \n"[i == m];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
