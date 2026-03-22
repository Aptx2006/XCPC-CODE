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

int n, m, t, ar[MAXN], ans, cnt, k;
struct nod {
    int s, d;
    bool operator<(const nod& other) const {
        if (s != other.s) {
            return s < other.s;
        } else
            return d < other.d;
    }
};

void solve() {
    cin >> n;
    vector<nod> a(n);
    for (auto& [x, y] : a) cin >> x >> y;
    sort(all(a));
    ans = 0;
    for (auto& c : a) {
        ans = max(ans, c.s) + c.d;
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
