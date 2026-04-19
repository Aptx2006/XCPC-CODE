#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 n, m, t, k;

void solve() {
    cin >> n >> m >> k;
    i64 z = (n - 1) % ((k + 1) / 2 * (m + 1) + 1);
    if(z % (m + 1) or z == 0) cout << "Alice\n";
    else cout << "Bob\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}
