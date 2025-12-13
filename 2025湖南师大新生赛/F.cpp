// Problem: Maxduan 的排列还原
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/124874/F
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
#define aint(A) A.begin(), A.end()
#define int long long

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;

void solve() {
    cin >> n;
    vector<int> a(n - 1);
    for (auto &x : a) cin >> x;
    vector<int> t(n);
    int tag = n * (n + 1) / 2, sum = 0;
    t[0] = 0;
    for (int i = 1; i < n; ++i) {
        t[i] = a[i - 1] - t[i - 1];
        sum += t[i];
    }
    vector<int> p(n);
    bool flag = 1;

    if (n & 1) {
        int x = tag - sum;
        for (int i = 0; i < n; ++i) {
            if (i & 1)
                p[i] = -x;
            else
                p[i] = x;
            p[i] += t[i];
        }
    } else {
        if (sum != tag) {
            flag = 0;
        } else {
            int l = max(1ll, a[0] - n), r = min(n, a[0] - 1);
            if (l > r) {
                flag = 0;
            } else {
                p[0] = l;
                for (int i = 1; i < n; ++i) {
                    p[i] = a[i - 1] - p[i - 1];
                }
            }
        }
    }

    if (!flag) {
        cout << -1 << '\n';
        return;
    }

    vector<bool> vis(n + 1, 0);
    flag = 1;
    for (auto &x : p) {
        if (x < 1 or x > n) {
            flag = 0;
            break;
        }
        if (vis[x]) {
            flag = 0;
            break;
        }
        vis[x] = 1;
    }

    if (flag) {
        for (int i = 0; i < n - 1; ++i) {
            if (p[i] + p[i + 1] != a[i]) {
                flag = 0;
                break;
            }
        }
    }

    if (flag) {
        for (auto &x : p) cout << x << ' ';
        cout << '\n';
    } else
        cout << -1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;
    cin >> times;
    while (times--) solve();
    return 0;
}
