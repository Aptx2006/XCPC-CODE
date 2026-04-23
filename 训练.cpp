#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int fa[1010], n, m, k = 1;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void solve() {
    cin >> n >> m;
    vector<array<int, 3>> e(m);
    for (auto& x : e) cin >> x[0] >> x[1] >> x[2];
    sort(e.begin(), e.end(), [](auto& a, auto& b) { return a[2] < b[2]; });
    for (int i = 1; i <= n; i++) fa[i] = i;
    i64 ans = 0, need = n - k;
    for(auto& x : e) {
        int u = find(x[0]), v = find(x[1]);
        if (u == v) continue;
        fa[u] = v;
        ans += x[2];
        if(--need == 0) {
            cout << ans << '\n';
            return;
        }
    }
    cout << (need == 0 ? to_string(ans) : "no spanning tree") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
