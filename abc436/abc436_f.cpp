// Problem: F - Starry Landscape Photo
// Contest: AtCoder - AtCoder Beginner Contest 436
// URL: https://atcoder.jp/contests/abc436/tasks/abc436_f
// Memory Limit: 1024 MB
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

const int MAXN = 5E5 + 5, MOD = 1E9 + 7, INF = 1E18;

int n, m, t, ar[MAXN], ans, cnt, k;
int tree[MAXN];
auto add = [](int i, int v) {
    for (; i <= n; i += i & -i) tree[i] += v;
};
auto qry = [](int i, int res = 0) {
    for (; i >= 1; i -= i & -i) res += tree[i];
    return res;
};

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> ar[i];
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) pos[ar[i]] = i;
    for (int i = 1; i <= n; i++) {
        int mn = qry(pos[i] - 1), mx = i - mn;
        ans += (mn + 1) * mx;
        add(pos[i], 1);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1;  // cin >> times;
    while (times--) solve();
    return 0;
}
