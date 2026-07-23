#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using i64 = long long;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pb_set;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m + 1);
    vector<i64> b(m + 1), c(m + 1), ans(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<queue<int>> q(n + 1);
    vector<bool> busy(n + 1, false);
    pb_set available; 
    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> pq;

    int ptr = 1;
    while (ptr <= m || !pq.empty()) {
        i64 t = 2e18;
        if (ptr <= m) t = min(t, b[ptr]);
        if (!pq.empty()) t = min(t, pq.top().first);

        while (!pq.empty() && pq.top().first == t) {
            auto [_, idx] = pq.top(); pq.pop();
            int u = a[idx];
            k++;
            busy[u] = false;
            if (!q[u].empty()) {
                available.insert(q[u].front());
            }
        }

        while (ptr <= m && b[ptr] == t) {
            int u = a[ptr];
            if (q[u].empty() && !busy[u]) {
                available.insert(ptr);
            }
            q[u].push(ptr);
            ptr++;
        }

        while (k > 0 && !available.empty()) {
            int idx = *available.begin(); 
            available.erase(available.begin()); 
            int u = a[idx];
            q[u].pop();
            k--;
            busy[u] = true;
            ans[idx] = t;
            pq.push({t + c[idx], idx});
        }
    }

    for (int i = 1; i <= m; ++i) {
        cout << ans[i] << (i == m ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for (cin >> T; T--; ) solve();
    return 0;
}
