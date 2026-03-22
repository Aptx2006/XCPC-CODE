#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize(2)
/*i32 : -2e9~2e9
i64: -9e18~9e18
u64: 0~1.8e19*/
using i64 = long long;
using u64 = unsigned long long;
#define dbg(A) cout << #A << "==" << A << '\n';
#define all(A) A.begin(), A.end()
#define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], cnt, k;

void solve() {
    cin >> n >> k;
    if (k == 1 or k <= n) {
        cout << "-1\n";
        return;
    }
    vector<bool> vis(k, 0);
    vis[0] = 1;
    int S = 0, last = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int a = last + 1;
        while (1) {
            int ns = S + a;
            int r = ns % k;
            if (!vis[r]) {
                vis[r] = 1;
                S = ns;
                last = a;
                ans.push_back(last);
                break;
            }
            a++;
        }
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
