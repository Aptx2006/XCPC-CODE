#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n;
    vector<i64> pos(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> k;
        pos[k] = i;
    }

    set<i64> s{0, n + 1};
    i64 res = 0;
    for(int v = n; v >= 1; v--) {
        i64 x = pos[v];
        auto it = s.lower_bound(x);
        i64 r = *it, l = *prev(it);
        if(l != 0) {
            int ll = *prev(prev(it));
            res += (x - l) * (l - ll) * (r - x);
        }
        if(r != n + 1) {
            int rr = *next(it);
            res += (r - x) * (x - l) * (rr - r);
        }
        s.insert(x);
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(; T--; solve());
    return 0;
}
