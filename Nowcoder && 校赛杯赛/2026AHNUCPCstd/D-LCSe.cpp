#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 n, m, t, k;

void solve() {
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    for(int i = n - 1; i >= 0; i--) 
        cout << a[i] << " \n"[i == 0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
