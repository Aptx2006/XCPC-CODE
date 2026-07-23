#include<bits/stdc++.h>
using namespace std;

int n, m, t, x;

void solve() {
    cin >> x;
    while(x % 2 and x > 1) {
        x /= 2;
    }
    cout << x * 30 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}
