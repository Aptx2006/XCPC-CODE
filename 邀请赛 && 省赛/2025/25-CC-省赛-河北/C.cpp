#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128_t;

const i64 N = 2e5 + 5, M = 1e9 + 7;

i64 nn, mm, kk, xx;
i128 bc[N], a[N], v[N], b[N], c[N], n, m, k, x;

void solve() {
    cin >> nn >> mm >> kk >> xx;
    n = nn, m = mm, k = kk, x = xx;
    for(int i = 1, u, v; i <= n; i ++) {
        cin >> u >> v;
        b[i] = u, c[i] = v;
    }
    for(int i = 1; i <= n; i ++) bc[i] = b[i] * c[i] + bc[i - 1];
    
    if(n * x < m)  {
        cout << "NO\n";
        return;
    }
    for(int i = 1; i <= n; i ++) {
        a[i] = min(m, x);
        m -= a[i];
    }

    i128 mx = 0;
    for(int i = 1; i <= n; i ++)  mx += a[i] * a[i];
    mx = mx * k;

    for(int i = 1; i <= n; i ++)  v[i] = c[i] - k * b[i];

    sort(v + 1, v + n + 1, greater<i128>());
    
    for (int i = 1; i <= n; i++)  mx += v[i] * (i128) a[i];
        
    if (mx > bc[n]) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; cin >> T;
    while(T--) solve();
}
