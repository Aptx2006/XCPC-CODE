#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<int> x(n, -1);
    vector<bool> col(n), d1(2 * n - 1), d2(2 * n - 1);

    auto dfs = [&](auto && self, int row) -> void {
        if (row == n) {
            for (int i = 0; i < n; i++) 
                cout << x[i] << " \n"[i == n - 1];
            return;
        }
        int l = 0, r = n;
        if (row == 0) r = n / 2;
        for (int c = l; c < r; c++) {
            int d = row - c + n - 1;
            int e = row + c;
            if (col[c] or d1[d] or d2[e]) continue;
            x[row] = c;
            col[c] = d1[d] = d2[e] = true;
            self(self, row + 1);
            col[c] = d1[d] = d2[e] = false;
        }
    };

    dfs(dfs, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(T = 1; T--; solve());
    return 0;
}
