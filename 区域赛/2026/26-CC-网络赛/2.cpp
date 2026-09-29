#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[10],b[40];

void solve() {
    int n;
    cin >> n;
    if(n & 1) {
        cout << "-1\n";
        return;
    }
    int a = n / 2;
    int b = 1, c = -1;
    cout << a << ' ' << b << ' ' << c << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}