#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;
const i128 INF = 1e9;

void solve() {
    cin >> n;
    i64 L = -INF, R = INF;
    bool ok = true;
    auto div = [](i64 x, i64 y) {
        if(x >= 0) return x / y;
        return -((-x + y - 1) / y);
    };
    for(int i = 0; i < n; i++) {
        i64 a, b, c;
        cin >> a >> b >> c;
        
        auto isok = [&](i64 x) {
            i128 cur = a;
            cur *= x * x;
            cur += b * x + c;
            return cur > 0;
        };

        i64 A = -a;
        i64 p = div(b, 2 * A);

        if(!isok(p)) {
            p++;
            if(!isok(p)) {
                ok = false;
                continue;
            }
        }

        i64 left = p;
        i64 l = -INF, r = p;
        while(l <= r) {
            i64 mid = (l + r) >> 1;
            if(isok(mid)) {
                left = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        i64 right = p;
        l = p, r = INF;
        while(l <= r) {
            i64 mid = (l + r) >> 1;
            if(isok(mid)) {
                right = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        L = max(L, left);
        R = min(R, right);
    }

    if(ok and L <= R) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
