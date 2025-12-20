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

int n;

void solve() { 
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    int ans = 0;
    int P = 0;
    while(P < n) {
        int l = 0, r = INF, sum = 0, mn[2] = {INF, 0ll};
        P++;
        int f = 1;
        while(P < n) {
            int d = a[P] - a[P-1], nsum = d - sum;
            int nl = l, nr = r, nf = 1 - f;
            if(nf) {
                nl = min(nl, -nsum);
            }else {
                nr = min(nr, nsum);
            }
            int rongcuo = 0ll;
            if(nl < nr) {
                int nmn = mn[nf];
                if(nmn != INF) rongcuo = max(0ll, nsum - nmn); 
            }
            int nd = 0;
            if(P < n - 1) nd = a[P + 1] - a[P];
            if(nl < nr and (!nd or rongcuo < nd)) {
                ans++;
                sum = nsum;
                l = nl, r = nr;
                mn[nf] = min(mn[nf], nsum);
                f = nf;
                P++;
            }else break;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int times = 1; cin >> times;
    while (times--) solve();
    return 0;
}
