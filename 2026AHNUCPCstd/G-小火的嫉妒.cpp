#include <bits/stdc++.h>
using namespace std;
 
int n;
 
void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    if (n > 60)
        cout << "1\n";
    else {
        int ans = 1e9;
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] ^ a[i - 1];
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = i; k < j; k++) {
                    if ((pre[k] ^ pre[i - 1]) > (pre[j] ^ pre[k]))
                        ans = min(ans, j - i - 1);
                }
            }
        }
        cout << (ans == 1e9 ? -1 : ans) << '\n';
    }
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}
