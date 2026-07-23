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
    cin >> n >> k;
    if(k & 1) {
        for(int i = 0; i < k; i++) cout << n << ' ';
    }else {

        int mxi = -1;
        for(int i = 32; i >= 0; i--) if((n >> i) & 1ll) {
            mxi = i;
            break;
        }
        int mx2i = -1;
        for(int i = mxi - 1; i >= 0; i--) if((n >> i) & 1ll) {
            mx2i = i;
            break;
        }

        if(mx2i == -1) {
            for(int i = 0; i < k - 2; i++) cout << n << ' ';
            cout << n << ' ' << 0;
        }else {
            for(int i = 0; i < k - 2; i++) cout << n << ' ';
            int y = 1ll << mxi, x = n ^ y;
            for(int i = 0; i <= 32; i++) {
                if((n >> i) & 1ll) continue;
                int add = 1ll << i;
                int nx = x | add, ny = y | add;
                if(nx <= n and ny <= n) x = nx, y = ny;
            }
            cout << x << ' ' << y;
        }
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1; cin >> times;
    while (times--) solve();
    return 0;
}
