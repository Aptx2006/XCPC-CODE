#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, m, ans, cnt;

void solve() {
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++) cin >> a[i], sum += a[i];
    int mx = 0;
    for(int i = 0; i < n; i++) mx = max(mx, a[i]);
    if(sum % 5 != 0 or mx * 5 > sum) cout << "F\n";
    else cout << "T\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 0;
    cin >> T;
    while(T--)  solve();
    return 0;
}