#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

i64 T = 1, n, m, k, cnt, ans;

void solve() {
    i64 x, y;
    cin >> x >> y >> k;
    i64 d = y - x, len = 0;
    if (d >= x) {
        len = min(k, d - x + 1);
    }
    ans = (k - len) * d;
    for (i64 i = 0; i < len; i++) {
        ans += d % (x + i);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}