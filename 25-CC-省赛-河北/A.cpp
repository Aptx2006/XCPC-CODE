#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128_t;

const i64 N = 2e5 + 5, M = 1e9 + 7;
i64 n, m, a[3][N];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[1][i];
    for(int i = 1; i <= n; i++) cin >> a[2][i];
    for(int i = 1; i <= n; i++) {
        a[1][i] += a[1][i - 1];
        a[2][i] += a[2][i - 1];
    }

    auto get = [&](int i, int j) {
        if (i <= j) return a[1][j] + a[2][j] - a[1][i - 1] - a[2][i - 1];
        return 0ll; 
    };

    int ii = n / 2, jj = ii + 1;

    if (get(1, ii) > get(jj, n)) cout << "Mandy\n";
    else if (get(1, ii + 1) < get(jj + 1, n)) cout << "brz\n";
    else {
        if (a[1][n] < a[2][n] and get(1, ii) != get(jj, n)) cout << "brz\n";
        else if (a[1][n] > a[2][n] and get(1, ii + 1) != get(jj + 1, n)) cout << "Mandy\n";
        else cout << "draw\n";
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; cin >> T;
    while(T--) solve();
}
