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
#define int u64

const int MAXN = 1E5 + 5, MOD = 1E9 + 7, INF = 1E18;

u64 n, m, t, ar[MAXN], ans, cnt, k;

void solve() { 
    cin >> n >> m;
    auto isok = [](int x) {
        return x > 0 and ( x & (x - 1) ) == 0;
    };
    if(~n & 1) {
        cout << "NO\n";
        return;
    }
    cnt = 0;
    while(!isok(m)) {
        m = bit_ceil(m) - m;
        cnt++;
    }
    if(n <= 2 * cnt + 1) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1; cin >> times;
    while (times--) solve();
    return 0;
}
