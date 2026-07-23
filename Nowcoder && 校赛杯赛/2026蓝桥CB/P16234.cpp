#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, m, ans, cnt;

void solve() {
    int L, R;
    cin >> n >> L >> R;
    cout << max(0ll, R- L + 1) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 0;
    cin >> T;
    while(T--)  solve();
    return 0;
}