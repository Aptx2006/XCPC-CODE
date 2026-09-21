#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> deg(n + 1);
    for (int i = 1; i <= m; i++) {
        int l, r, pre;
        cin >> l >> r >> pre;
        for (int j = l + 1, x; j <= r; j++) {
            cin >> x;
            g[pre].push_back(x);
            deg[x]++;
            pre = x;
        }
    }

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++) {
        if (!deg[i]) q.push(i);
    }

    vector<int> p(n + 1);
    int cur = 0;
    while (!q.empty()) {
        int x = q.top();
        q.pop();
        p[x] = ++cur;
        for (auto y: g[x]) {
            if (!--deg[y]) q.push(y);
        }
    }

    if (cur < n) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
