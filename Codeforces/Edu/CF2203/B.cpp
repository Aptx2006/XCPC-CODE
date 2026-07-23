// Problem: B. Beautiful Numbers
// Contest: Codeforces - Educational Codeforces Round 187 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2203/problem/B
// Memory Limit: 512 MB
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

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
    cin >> n;
    int buc[20] = {0}, sum = 0;
    while (n) {
        if (n < 10) {
            buc[n % 10 - 1]++;
            sum += n % 10;
            n /= 10;
        } else {
            buc[n % 10]++;
            sum += n % 10;
            n /= 10;
        }
    }
    ans = 0;
    if (sum < 10)
        cout << ans << '\n';
    else {
        for (int i = 9; i >= 1; i--) {
            cnt = buc[i];
            // cout << i << ' ' << buc[i] << endl;
            if (sum - cnt * i <= 9) {
                ans += (sum - 9 + i - 1) / i;
                cout << ans << '\n';
                return;
            }
            sum -= cnt * i;
            ans += cnt;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
