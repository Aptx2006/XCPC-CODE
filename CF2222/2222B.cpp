#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m;

void solve() {
    cin >> n >> m;
    vector<i64> a, b;
    i64 ans = 0;
    for(int i = 1; i <= n; i++) {
        i64 v;
        cin >> v;
        ans += v;
        (i & 1 ? a: b).push_back(v);
    }
    int c1 = 0, ce = 0;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        (x & 1 ? c1: ce)++;
    }
    sort(all(a), greater<i64>());
    sort(all(b), greater<i64>());
    i64 add = 0;
    if(c1 and !a.empty()) {
        add += a[0];
        int mn = min(c1 - 1, (int)a.size() - 1);
        for(int i = 1; i <= mn; i++) {
            if(a[i] > 0) add += a[i];
        }
    }
    if(ce and !b.empty()) {
        add += b[0];
        int mn = min(ce - 1, (int)b.size() - 1);
        for(int i = 1; i <= mn; i++) {
            if(b[i] > 0) add += b[i];
        }
    }
    cout << ans - add << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T--) solve();
    return 0;
}