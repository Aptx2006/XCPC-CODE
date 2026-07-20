#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(A) (A).begin(), (A).end()

int T = 1, n, m;
i64 pw3[20];

void solve() {
    cin >> n;
    m = 1 << n;
    vector<int> a(m), b(m);
    for(auto &x: a) cin >> x;
    vector<i64> ans(pw3[n+1]);
    for(int i = 0; i < m; i++) {
        int st = 0;
        for(int j = 0; j < n; j++) {
            int bit = (i >> j) & 1;
            st += bit * pw3[j];
        }
        b[i] = st;
        ans[st] = a[i];
    }
    for(int i = 0; i < n; i++) {
        for(int low = 0; low < pw3[i]; low++) {
            for(int high = 0; high < (1 << (n - i - 1)); high++) {
                int st0 = b[high] * pw3[i + 1] + low;
                int st1 = st0 + pw3[i];
                int st2 = st0 + 2 * pw3[i];
                ans[st2] = ans[st0] + ans[st1];
            }
        }
    }
    i64 res = 0;
    for(auto &x: ans) res ^= x;
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pw3[0] = 1;
    for(int i = 1; i <= 20; i++) {
        pw3[i] = pw3[i - 1] * 3;
    }
    for(; T--; solve());
    return 0;
}