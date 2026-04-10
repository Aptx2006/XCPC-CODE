#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    int N = 1 << n;
    vector<int> pre(N);
    vector<bool> dp(N);

    for (int i = 0; i < n; i++) {
        pre[1 << i] = a[i];
    }
    for (int mask = 1; mask < N; mask++) {
        int lsb = mask & -mask;
        pre[mask] = pre[mask ^ lsb] ^ pre[lsb];
    }

    for (int mask = 1; mask < N; mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                int k = mask ^ (1 << i);
                if (a[i] > pre[k] and !dp[k]) {
                    dp[mask] = 1;
                    break;
                }
            }
        }
    }

    if (dp[N - 1]) {
        cout << "Left\n";
    } else {
        cout << "Right\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
