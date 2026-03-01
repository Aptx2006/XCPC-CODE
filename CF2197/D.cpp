// Problem: D. Another Problem about Beautiful Pairs
// Contest: Codeforces - Codeforces Round 1079 (Div. 2)
// URL: https://codeforces.com/contest/2197/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize(2)
/*i32 : -2e9~2e9
i64: -9e18~9e18
u64: 0~1.8e19*/
using i64 = long long;
using u64 = unsigned long long;
#define dbg(A) cout << #A << "==" << A << '\n';
#define all(A) A.begin(), A.end()
#define int long long

const int MAXN = 2E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> ar[i];
    int B = sqrt(n);
    ans = 0;
    for (int ai = 1; ai <= B; ai++) {
        for (int j = 1; j <= n; j++) {
            k = ai * ar[j];
            int i = j - k;
            if (k < j and ar[i] == ai) ans++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ar[i] <= B) continue;
        for (int aj = 1; aj <= B; aj++) {
            int j = i + ar[i] * aj;
            if (j <= n and ar[j] == aj) ans++;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
