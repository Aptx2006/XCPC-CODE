#include<bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << (x) << endl;

int T = 1, n, m, k, ans, cnt;

void solve() {
    cin >> n >> m;
    vector<int> a(n), suf(n);
    for(auto &x : a) cin >> x;
    suf[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        suf[i] = min(suf[i + 1], a[i]);
    }
    ans = 0;
    int pre = a[0];
    for(int i = 1; i < n; i++) {
        if(pre > suf[i]) {
            ans = max(ans, (i & -i));
        }
        pre = max(pre, a[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(cin >> T; T--; solve());
    return 0;
}
